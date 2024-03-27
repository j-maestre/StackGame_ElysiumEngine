#ifndef __SHADER_H__
#define __SHADER_H__ 1

#include <memory>
#include <optional>

/**
 * @class Shader
 * @brief Represents an OpenGL shader.
 */
class Shader {
 public:

     /**
     * @enum Type
     * @brief Enumerates the different types of shaders.
     */
    enum Type {
        kType_Invalid,
        kType_Vertex,
        kType_Fragment,
        kType_Geometry,
    };

private:

    /**
   * @brief Constructor for Shader (private to enforce creation through create method).
   * @param shader_type The type of the shader.
   * @param source The source code of the shader.
   * @param source_size The size of the source code.
   */
   Shader(const Shader::Type shader_type, const char* source, const unsigned int source_size);

public:

   Shader(const Shader&) = delete;

   /**
   * @brief Move constructor for Shader.
   * @param other The rvalue reference to the other Shader.
   */
   Shader(Shader&& other) noexcept;

   /**
   * @brief Destructor for Shader.
   */
   ~Shader();

   /**
   * @brief Create a new shader with the given type and source code.
   * @param shader_type The type of the shader.
   * @param source The source code of the shader.
   * @param source_size The size of the source code.
   * @return An optional containing the created shader, or std::nullopt on failure.
   */
   static std::optional<Shader> create(const Shader::Type shader_type, const char* source, const unsigned int source_size);

  /**
   * @brief Get the shader type.
   *
   * Retrieves the type of shader.
   *
   * @return The shader type.
   */
  const Shader::Type type() const;

  /**
   * @brief Get the internal ID of the shader.
   *
   * Retrieves the internal ID of the shader.
   *
   * @return The internal ID of the shader.
   */
  unsigned int internalId() const;

protected:

  unsigned int id_;
  bool compiled_;
  Shader::Type type_;
  bool destroy_ = true;

};


#endif
