#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <memory>

#include "engine/render/resource.h"

/**
 * @class Texture
 * @brief Represents a texture used in rendering.
 * @details This class inherits from the Resource class.
 */
class Texture : public Resource {

public:

	/**
	 * @brief Enumerates the possible formats for the texture.
	 */
	enum Format {
		kFormat_RGB,
		kFormat_DEPTH
	};

	/**
	 * @brief Default constructor for Texture.
	 */
	Texture();

	/**
	 * @brief Constructor for creating a texture with a specific format.
	 * @param format The format of the texture.
	 */
	Texture(Texture::Format format);

	/**
	 * @brief Constructor for loading a texture from a file.
	 * @param filename The filename of the texture image.
	 */
	Texture(const char* filename);

	Texture(const Texture& other) = delete;
	
	/**
	 * @brief Move constructor for Texture.
	 * @param other The rvalue reference to another Texture.
	 */
	Texture(Texture&& other) noexcept;

	/**
	 * @brief Move assignment operator for Texture.
	 * @param other The rvalue reference to another Texture.
	 * @return A reference to the current Texture object.
	 */
	Texture& operator=(Texture&& other) noexcept;

	/**
	 * @brief Destructor for Texture.
	 */
	~Texture();

	/**
	 * @brief Overrides the bind function from the Resource class.
	 */
	virtual void bind() override;

	/**
	 * @brief Activates the texture on a specific texture unit.
	 * @param textUnit The texture unit to activate.
	 */
	void activate(unsigned int textUnit);

	/**
	 * @brief Uploads data to the texture.
	 * @param data The pointer to the image data.
	 * @param width The width of the texture.
	 * @param height The height of the texture.
	 */
	void uploadData(unsigned char* data, int width, int height);

	/**
	* @brief Retrieves the internal identifier of the texture.
	* @return The internal identifier of the texture.
	*/
	const unsigned int internalId();

protected:

	friend class PhongSystem;

	bool destroy_ = true;

	struct TextureInformation {

		TextureInformation() : id_(0), width_(0), height_(0), data_(nullptr), format_(kFormat_RGB){}

		TextureInformation(TextureInformation&& other) noexcept
			: id_(std::move(other.id_)),
		width_(std::move(other.width_)),
		height_(std::move(other.height_)) {
			data_ = other.data_;
			format_ = other.format_;
		}

		unsigned int id_;
		int width_, height_;
		unsigned char* data_;
		Texture::Format format_;
	};

	std::unique_ptr<TextureInformation> info_;

};

#endif