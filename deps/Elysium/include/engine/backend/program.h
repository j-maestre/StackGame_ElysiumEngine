#ifndef __PROGRAM_H__
#define __PROGRAM_H__ 1

#include <memory>
#include "engine/backend/constants.h"
#include "engine/backend/shader.h"

/**
 * @class Program
 * @brief Represents an OpenGL shader program.
 */
class Program {
 private:

  /**
  * @brief Constructor for Program (private to enforce creation through create method).
  * @param vertex_shader The vertex shader.
  * @param fragment_shader The fragment shader.
  */
  Program(Shader& vertex_shader, Shader& fragment_shader);

public:
  
  Program(const Program&) = delete;

  /**
  * @brief Move constructor for Program.
  * @param other The rvalue reference to the other Program.
  */
  Program(Program&& other) noexcept;

  /**
  * @brief Destructor for Program.
  */
  ~Program();

  /**
  * @brief Create a new program with the given vertex and fragment shaders.
  * @param vertex_shader The vertex shader.
  * @param fragment_shader The fragment shader.
  * @return An optional containing the created program, or std::nullopt on failure.
  */
  static std::optional<Program> create(Shader& vertex_shader, Shader& fragment_shader);

  /**
  * @brief Move assignment operator for Program.
  * @param other The rvalue reference to the other Program.
  * @return A reference to the modified Program.
  */
  Program& operator=(Program&& other) noexcept;

  /**
   * @brief Use the program.
   *
   * This method sets the program as the active program for rendering.
   */
  void use() const;

  /**
   * @brief Get the attribute location.
   *
   * This method retrieves the location of an attribute in the program.
   *
   * @param name The name of the attribute.
   * @return The attribute location.
   */
  int getAttribLocation(const char* name) const;

  /**
   * @brief Get the uniform position.
   *
   * This method retrieves the position of a uniform in the program.
   *
   * @param name The name of the uniform.
   * @return The uniform position.
   */
  int getUniformPosition(const char* name) const;

  /**
   * @brief Set the value of a uniform variable.
   *
   * This method sets the value of a uniform variable in the program.
   *
   * @param uniform_pos The position of the uniform.
   * @param uniform_type The type of the uniform.
   * @param number The value of the uniform.
   */
  void setUniformValue(const int uniform_pos,
                                 const Type uniform_type,
                                 const float* number) const;

  /**
   * @brief Set the value of a uniform variable.
   *
   * This method sets the value of a uniform variable in the program.
   *
   * @param uniform_pos The position of the uniform.
   * @param uniform_type The type of the uniform.
   * @param number The value of the uniform.
   */
  void setUniformValue(const int uniform_pos,
                                 const Type uniform_type,
                                 const int* number) const;


  /**
   * @brief Set the value of a uniform variable.
   *
   * This method sets the value of a uniform variable in the program.
   *
   * @param uniform_pos The position of the uniform.
   * @param uniform_type The type of the uniform.
   * @param number The value of the uniform.
   */
  void setUniformValue(const int uniform_pos,
                                 const Type uniform_type,
                                 const unsigned int* number) const;

  /**
   * @brief Get the internal ID of the program.
   *
   * This method retrieves the internal ID of the program.
   *
   * @return The internal ID of the program.
   */
  unsigned int internalId() const;

 protected:

  unsigned int id_;
  bool linked_;
  bool destroy_ = true;

};


#endif
