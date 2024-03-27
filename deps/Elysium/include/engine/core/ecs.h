#ifndef __ECS_H__
#define __ECS_H__ 1

#include <vector>
#include <optional>
#include <unordered_map>
#include <tuple>
#include <memory>
#include <assert.h>

struct component_base {
	virtual void add() = 0;
	virtual size_t size() = 0;
	virtual void remove(size_t e) = 0;
};

template<typename T>
struct custom_iterator {
public:
	custom_iterator(std::vector<std::optional<T>>::iterator it, std::vector<std::optional<T>>::iterator end) : ptr_{ it }, end_{ end }
	{
		if (ptr_ != end_) { //CHECKS IF THIS IS NOT THE END
			while (*ptr_ == std::nullopt && ptr_ != end_) {
				ptr_++;
			}
		}
	}

	~custom_iterator() { }

	void advance_pointer() {
		while ((*ptr_ == std::nullopt) && (ptr_ != end_)) {
			ptr_++;
		}
	}

	custom_iterator& operator++() {
		if (ptr_ == end_) {
			return (*this);
		}

		do {
			ptr_++;
		} while ((ptr_ != end_) && ((*ptr_) == std::nullopt));
		return (*this);
	}

	custom_iterator operator++(int) {
		custom_iterator tmp = *this;
		++(*this);
		return tmp;
	}

	bool operator==(const custom_iterator& other) const {
		return ptr_ == other.ptr_;
	}

	bool operator!=(const custom_iterator& other) const {
		return ptr_ != other.ptr_; 
		//ASK ARNAU IF THIS IS CORRECT return ptr_ != other.end_; 
	}

	T& operator*() {
		return ptr_->value();
	}

private:
	std::vector<std::optional<T>>::iterator ptr_;
	std::vector<std::optional<T>>::iterator end_;
};

template<typename T>
struct component_list_iterator {
public:

	component_list_iterator(std::vector<std::optional<T>>& vector) : current_(vector.begin(), vector.end()),
																	 last_(vector.end(), vector.end()) {

	}

	~component_list_iterator() {}

	custom_iterator<T> begin() {
		return current_;
	}

	custom_iterator<T> end() {
		return last_;
	}

private:
	custom_iterator<T> current_;
	custom_iterator<T> last_;

};

//template<typename T, typename U>
//struct component_list_iterator_multiple {
//public:
//	component_list_iterator_multiple(component_list_iterator<T>& it, component_list_iterator<U>& it2) {
//		currents_ = std::make_tuple(it.begin(), it2.begin());
//		lasts_ = std::make_tuple(it.end(), it2.end());
//	}
//
//	~component_list_iterator_multiple() { }
//
//	template<typename C>
//	void advance_iterator(custom_iterator<C>& it) {
//		++it;
//	}
//
//	component_list_iterator_multiple& operator++() {
//		++std::get<0>(currents_);
//		++std::get<1>(currents_);
//		return *this;
//	}
//
//	bool operator==(const component_list_iterator_multiple& other) const {
//		return std::get<0>(currents_) == std::get<0>(other.currents_) &&
//			std::get<1>(currents_) == std::get<1>(other.currents_);
//	}
//
//	bool operator!=(const component_list_iterator_multiple& other) const {
//		return (std::get<0>(currents_) != std::get<0>(other.currents_)) ||
//			(std::get<1>(currents_) != std::get<1>(other.currents_));
//	}
//
//	std::tuple<T&, U&> operator*() {
//		return std::tuple<T&, U&>((*std::get<0>(currents_)), (*std::get<1>(currents_)));
//	}
//
//	std::tuple<custom_iterator<T>, custom_iterator<U>> begin() {
//		return currents_;
//	}
//
//	std::tuple<custom_iterator<T>, custom_iterator<U>> end() {
//		return lasts_;
//	}
//
//private:
//	std::tuple<custom_iterator<T>, custom_iterator<U>>  currents_;
//	std::tuple<custom_iterator<T>, custom_iterator<U>>  lasts_;
//
//};

template<typename T>
struct component_list : component_base {
	virtual void add() {
		components_.emplace_back();
	}

	void add_component(size_t e, T& value) {
		components_[e - 1] = std::move(value);
	}

	std::optional<T>& get_component(size_t e) {
		return components_.at(e - 1);
	}

	size_t get_entity(T& c) {
		size_t n_entity = 1;
		for (const auto& component : components_) {
			if (component.has_value()) {
				if (component.value() == c) {
					return n_entity;
				}
			}
			n_entity++;
		}
		return 0;
	}

	virtual size_t size() {
		return components_.size();
	}

	virtual void remove(size_t e) {
		components_[e - 1] = std::nullopt;
	}

	component_list_iterator<T> get_iterator() {
		return component_list_iterator<T>(components_);
	}

private:
	std::vector<std::optional<T>> components_;
};

template<typename T>
struct id_component {
	size_t id;
	T component;
};

template<typename T>
struct compact_component_list : component_base {

	virtual size_t size() {
		return components_.size();
	}

	std::vector<id_component<T>> components_;
};

/**
 * @brief Manages components and entities using an ECS pattern.
 */
class ComponentManager {
public:
	ComponentManager() = default;
	~ComponentManager() = default;

	ComponentManager(ComponentManager&) = delete;

	/**
	 * @brief Adds a component class of type T to the ECS system.
	 */
	template<typename T> void add_component_class() {
		component_classes_.emplace(typeid(T).hash_code(),std::make_unique<component_list<T>>());
	}

	/**
	 * @brief Adds an entity and initializes components for all registered component classes.
	 * @return The id of the added entity.
	 */
	size_t add_entity(){
		size_t size = 0;
		for (auto& [key, value] : component_classes_) {
			value->add();
			size = value->size();
		}
		return size;
	}
	
	/**
	 * @brief Removes an entity by its identifier from all registered component classes.
	 * @param e The entity identifier to remove.
	 */
	void remove_entity(size_t e){
		for (auto& [key, value] : component_classes_) {
			value->remove(e);
		}
	}

	/**
	 * @brief Gets the entity identifier of a component.
	 * @tparam T The type of the component.
	 * @param c The component instance.
	 * @return The entity identifier.
	 */
	template<typename T> size_t get_entity_id(T& c) {
		auto hc = typeid(T).hash_code();
		auto component_list_it = component_classes_.find(hc);
		auto& v_component = *static_cast<component_list<T>*>(component_list_it->second.get());
		return v_component.get_entity(c);
	}

	/**
	 * @brief Gets an iterator for a specific component type.
	 * @tparam T The type of the component.
	 * @return An iterator for the specified component type.
	 */
	template<typename T> component_list_iterator<T> get_component_iterator() {
		auto hc = typeid(T).hash_code();
		assert(component_classes_.size());
		assert(component_classes_.contains(typeid(T).hash_code()));
		auto component_list_it = component_classes_.find(hc);
		auto& component_ = *static_cast<component_list<T>*>(component_list_it->second.get());
		return component_.get_iterator();
	}

	/*template<typename T, typename U> component_list_iterator_multiple<T, U> get_component_iterator_multiple() {
		auto hc = typeid(T).hash_code();
		assert(component_classes_.size());
		assert(component_classes_.contains(typeid(T).hash_code()));
		auto component_list_it = component_classes_.find(hc);
		auto& component_ = *static_cast<component_list<T>*>(component_list_it->second.get());

		auto hcu = typeid(U).hash_code();
		assert(component_classes_.contains(typeid(U).hash_code()));
		auto component_list_it_u = component_classes_.find(hcu);
		auto& component_u = *static_cast<component_list<U>*>(component_list_it_u->second.get());

		return component_list_iterator_multiple(component_.get_iterator(), component_u.get_iterator());
	}*/

	/**
	 * @brief Gets a pointer to the component of a specific entity.
	 * @tparam T The type of the component.
	 * @param e The entity identifier.
	 * @return A pointer to the component or nullptr if the entity/component doesn't exist.
	 */
	template<typename T> T* get_entity_component(size_t e) {
		auto hc = typeid(T).hash_code();
		assert(component_classes_.size());
		assert(component_classes_.contains(typeid(T).hash_code()));
		assert(e != 0);
		auto component_list_it = component_classes_.find(hc);
		auto& component_ = *static_cast<component_list<T>*>(component_list_it->second.get());
		assert(e <= component_.size());
		auto& component_opt = component_.get_component(e);
		if (!component_opt.has_value()) return nullptr;
		return &component_opt.value();
	}

	/**
	 * @brief Sets the value of a component for a specific entity.
	 * @tparam T The type of the component.
	 * @param e The entity identifier.
	 * @param value The new value for the component.
	 */
	template<typename T> void set_entity_component_value(size_t e, T& value) {
		auto hc = typeid(T).hash_code();
		assert(component_classes_.contains(hc));
		auto component_list_it = component_classes_.find(hc);
		auto& component_ = *static_cast<component_list<T>*>(component_list_it->second.get());
		component_.add_component(e, value);
	}

private:
	std::unordered_map<std::size_t, std::unique_ptr<component_base>> component_classes_; /**< Map of component classes. */

};

#endif
