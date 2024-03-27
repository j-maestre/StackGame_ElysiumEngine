#ifndef __RENDER_TARGET_H__
#define __RENDER_TARGET_H__ 1

#include "engine/render/texture.h"

/**
 * @class RenderTarget
 * @brief Represents a render target for frame buffer operations.
 */
class RenderTarget {
public:

	/**
	 * @brief Default constructor for RenderTarget.
	 */
	RenderTarget();

	RenderTarget(const RenderTarget& other) = delete;
	RenderTarget(RenderTarget&& other) = delete;

	/**
	 * @brief Destructor for RenderTarget.
	 */
	~RenderTarget();

	/**
	 * @brief Binds the render target for rendering.
	 */
	void bind();

	/**
	 * @brief Unbinds the render target.
	 */
	void unbind();

	/**
	 * @brief Gets the ID of the color texture attached to the render target.
	 * @return The ID of the color texture.
	 */
	unsigned int getColorTexture() const;

	/**
	 * @brief Gets the ID of the depth texture attached to the render target.
	 * @return The ID of the depth texture.
	 */
	unsigned int getDepthTexture() const;

protected:

	friend class PhongSystem;
	friend class DeferredSystem;

	unsigned int fbo_;

	unsigned int depth_texture_id_;
	unsigned int color_texture_id_;

};

#endif
