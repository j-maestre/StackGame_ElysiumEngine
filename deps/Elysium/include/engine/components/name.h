#ifndef __NAME_H__
#define __NAME_H__ 1
#include <string>

/**
 * @struct NodeName
 * @brief Structure representing a named node.
 */
struct NodeName {
	std::string name_; /**< The name of the node */
	size_t id_; /**< The ID of the node */

	/**
	 * @brief Default constructor for NodeName.
	 */
	NodeName() = default;

	/**
	 * @brief Constructor for NodeName.
	 * @param name The name of the node.
	 * @param id The ID of the node.
	 */
	NodeName(const std::string& name, size_t id) : name_(name), id_(id) {}

	/**
	 * @brief Equality comparison operator for NodeName.
	 * @param other The other NodeName object to compare with.
	 * @return True if the two NodeName objects are equal, false otherwise.
	 */
	bool operator==(const NodeName& other) const {
		return (name_ == other.name_) && (id_ == other.id_);
	}
};

#endif