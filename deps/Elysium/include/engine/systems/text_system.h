/**
 * @file text_system.h
 * @brief Header file for the TextSystem class.
 */

#ifndef __TEXT_SYSTEM_H__
#define __TEXT_SYSTEM_H__ 1

#include <ft2build.h>
#include FT_FREETYPE_H
#include <glm/ext/vector_int2.hpp>
#include <map>
#include "engine/elysium.h"


 /**
  * @struct Character
  * @brief Structure representing a single character glyph.
  */
struct Character {
	unsigned int textureID_;  /**< ID handle of the glyph texture */
	glm::ivec2   size_;       /**< Size of glyph */
	glm::ivec2   bearing_;    /**< Offset from baseline to left/top of glyph */
	unsigned int advance_;    /**< Offset to advance to next glyph */
};

/**
 * @class TextSystem
 * @brief Class responsible for rendering text using FreeType and OpenGL.
 */
class TextSystem
{
public:
	/**
	 * @brief Constructor for TextSystem class.
	 * @param vertex_shader Reference to the vertex shader object.
	 * @param fragment_shader Reference to the fragment shader object.
	 * @param font Path to the font file.
	 */
	TextSystem(Shader& vertex_shader, Shader& fragment_shader,const char* font);

	/**
	* @brief Destructor for TextSystem class.
	*/
	~TextSystem();

	/**
	 * @brief Applies the text rendering system.
	 * @param ecs Reference to the ComponentManager object.
	 * @param w Reference to the Window object.
	 */
	void apply(ComponentManager& ecs, Window& w);

private:

	/**
	 * @brief Loads characters from the specified font file.
	 * @param font Path to the font file.
	 */
	void loadCharacters(const char* font);

	std::map<char, Character> characters_; /**< Map of characters */

	std::optional<Program> program_; /**< Optional shader program */
	unsigned int VAO, VBO, EBO;  /**< Vertex Array Object, Vertex Buffer Object, Element Buffer Object */
};

#endif