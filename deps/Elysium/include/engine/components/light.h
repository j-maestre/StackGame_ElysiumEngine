#ifndef __LIGHT__
#define __LIGHT__ 1

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

/**
 * @struct Light
 * @brief Represents a light source in a 3D environment.
 */
struct Light {

	/**
	 * @enum Type
	 * @brief Enumerates the different types of lights.
	 */
	enum class Type {
		kPoint_Light,
		kSpotlight,
		kDirectional_Light,
		kAmbient_Light
	};

	glm::vec3 position;
	glm::vec3 attenuation;
	glm::vec3 direction;
	glm::vec3 color;

	float strength;

	Light::Type type;

	float cut_off;
	float outer_cut_off;

	/**
	 * @brief Default constructor for Light.
	 * @param t The type of the light.
	 * @param pos The position of the light.
	 * @param att The attenuation factors.
	 * @param col The color of the light.
	 * @param dir The direction of the light.
	 * @param cut The inner cutoff angle for spotlight (default: 12.5 degrees).
	 * @param outer_cut The outer cutoff angle for spotlight (default: 17.5 degrees).
	 * @param str The strength of the light (default: 0.5).
	 */
	Light(Light::Type t, glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 att = glm::vec3(1.0f, 0.014f, 0.0007f),
		  glm::vec3 col = glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3 dir = glm::vec3(0.0f, 0.0f, -1.0f), 
		  float cut = 12.5f, float outer_cut = 17.5f, float str = 0.5f);

	/**
	 * @brief Set the position of the light source.
	 * @param pos The new position.
	 */
	void setPosition(glm::vec3 pos) { position = pos; };

	/**
	 * @brief Set the attenuation factors for the light source.
	 * @param att The new attenuation factors.
	 */
	void setAttenuation(glm::vec3 att) { attenuation = att; };

	/**
	 * @brief Set the color of the light source.
	 * @param col The new color.
	 */
	void setColor(glm::vec3 col) { color = col; };

	/**
	 * @brief Set the direction of the light source.
	 * @param dir The new direction.
	 */
	void setDirection(glm::vec3 dir) { direction = dir; };

	/**
	 * @brief Set the inner cutoff angle for spotlight.
	 * @param cut The new inner cutoff angle (in degrees).
	 */
	void setCutOff(float cut) { cut_off = cut; };

	/**
	 * @brief Set the outer cutoff angle for spotlight.
	 * @param outer_cut The new outer cutoff angle (in degrees).
	 */
	void setOuterCutOff(float outer_cut) { outer_cut_off = outer_cut; };

};

#endif
