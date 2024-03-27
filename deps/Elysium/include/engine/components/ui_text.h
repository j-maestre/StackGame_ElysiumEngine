#ifndef __UITEXT_H__
#define __UITEXT_H__ 1
#include <string>
#include <glm/ext/vector_float3.hpp>

/**
 * @struct UIText
 * @brief Structure representing UI text.
 */
struct UIText {
    std::string text_;      /**< The text content */
    float x_;               /**< The x-coordinate position */
    float y_;               /**< The y-coordinate position */
    float scale_;           /**< The scale of the text */
    glm::vec3 color_;       /**< The color of the text */

    /**
     * @brief Constructor for UIText.
     * @param text The text content.
     * @param x The x-coordinate position.
     * @param y The y-coordinate position.
     * @param scale The scale of the text.
     * @param color The color of the text.
     */
    UIText(const std::string& text, float x, float y, float scale, const glm::vec3& color)
        : text_(text), x_(x), y_(y), scale_(scale), color_(color) {}

    /**
     * @brief Equality comparison operator for UIText.
     * @param other The other UIText object to compare with.
     * @return True if the two UIText objects are equal, false otherwise.
     */
    bool operator==(const UIText& other) const {
        return text_ == other.text_ &&
            x_ == other.x_ &&
            y_ == other.y_ &&
            scale_ == other.scale_ &&
            color_ == other.color_;
    }
};

#endif