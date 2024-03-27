#ifndef __VERTEX__
#define __VERTEX__ 1

#include "glm/glm.hpp"

/**
 * @brief A struct representing a basic vertex with position and normals.
 */
struct Vertex {
	glm::vec3 position; /**< The position of the vertex. */
	glm::vec3 normals; /**< The normal vector of the vertex. */
	glm::vec2 uv;
};

#endif 
