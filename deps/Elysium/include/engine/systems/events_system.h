#ifndef __EVENTS_SYSTEM_H__
#define __EVENTS_SYSTEM_H__ 1

/**
 * @brief Represents an event that can be subscribed to and broadcasted.
 *
 * @tparam Args The types of arguments accepted by the event.
 */
template<typename... Args>
class Event {
public:
	using Callback = std::function<void(Args...)>;/**< Type definition for the callback function. */

	/**
	 * @brief Adds a dynamic callback to the event.
	 *
	 * @param callback The callback function to add.
	 */
	void AddDynamic(const Callback& callback) {
		listeners.push_back(callback);
	}

	/**
	 * @brief Broadcasts the event to all subscribed listeners.
	 *
	 * @param args The arguments to be passed to the listeners.
	 */
	void Broadcast(Args... args) {
		for (const auto& listener : listeners) {
			listener(args...);
		}
	}

private:
	std::vector<Callback> listeners; /**< Vector containing all the subscribed listeners. */
};


#endif