#ifndef __SCENE_GRAPH_H__
#define __SCENE_GRAPH_H__ 1
#include <memory>

/**
 * @struct NodeScene
 * @brief Structure representing a node in a scene graph.
 */
struct NodeScene {
	
	size_t parent_id; /**< The ID of the parent node */

	/**
	 * @brief Constructor for NodeScene.
	 * @param parent The ID of the parent node (default is 0).
	 */
	NodeScene(size_t parent = 0) : parent_id(parent) {}

	/**
	 * @brief Equality comparison operator for NodeScene.
	 * @param other The other NodeScene object to compare with.
	 * @return True if the two NodeScene objects are equal, false otherwise.
	 */
	bool operator==(const NodeScene& other) const {
		return (parent_id == other.parent_id);
	}

};

#endif