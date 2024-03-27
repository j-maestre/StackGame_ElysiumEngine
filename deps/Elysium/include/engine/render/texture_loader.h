#ifndef __TEXTURE_LOADER_H__
#define __TEXTURE_LOADER_H__ 1
#include <iostream>
#include <string>
#include "stb_image.h"
#include <engine/core/logger.h>


/**
 * @brief The ImageLoader class handles loading of image textures.
 *
 * This class provides functionalities for loading image textures from files.
 */
class ImageLoader {
private:
    int width; /**< Width of the loaded image. */
    int height; /**< Height of the loaded image. */
    int numChannels; /**< Number of color channels in the loaded image. */

public:
    /**
     * @brief Constructs an ImageLoader object and loads the image from the specified file.
     *
     * @param filename The path to the image file to load.
     */
    ImageLoader(const char* filename) : width(0), height(0), numChannels(0), data(nullptr) {
        stbi_set_flip_vertically_on_load(true);
        data = stbi_load(filename, &width, &height, &numChannels, 0);
        if (data == nullptr) {
            ENGINE_ERROR("Error to load the texture {}", filename);
        }
    }

    /**
     * @brief Destroys the ImageLoader object and frees the loaded image data.
     */
    ~ImageLoader() {
        if (data != nullptr) {
            stbi_image_free(data);
        }
    }

    /**
     * @brief Get the width of the loaded image.
     *
     * @return The width of the loaded image.
     */
    int getWidth() const { return width; }

    /**
     * @brief Get the height of the loaded image.
     *
     * @return The height of the loaded image.
     */
    int getHeight() const { return height; }

    /**
     * @brief Get the number of color channels in the loaded image.
     *
     * @return The number of color channels in the loaded image.
     */
    int getNumChannels() const { return numChannels; }

    /**
     * @brief Get a pointer to the loaded image data.
     *
     * @return A pointer to the loaded image data.
     */
    unsigned char* getData() const { return data; }

    unsigned char* data; /**< Pointer to the loaded image data. */
};

#endif
