#ifndef __BUFFER_H__
#define __BUFFER_H__ 1

/**
 * @class Buffer
 * @brief Represents a buffer object for OpenGL.
 */
class Buffer {
 public:

     /**
     * @enum Target
     * @brief Enumerates the different buffer targets.
     */
    enum Target {
        kTarget_Vertex_Data,
        kTarget_Elements,
    };

   /**
   * @brief Default constructor for Buffer.
   */
   Buffer();

   /**
   * @brief Constructor for Buffer with specified size and target.
   * @param size The size of the buffer.
   * @param t The target for the buffer.
   */
   Buffer(unsigned int size, const Buffer::Target t);

   Buffer(const Buffer& other) = delete;

   /**
   * @brief Move constructor for Buffer.
   * @param other The rvalue reference to the other Buffer.
   */
   Buffer(Buffer&& other) noexcept;

   /**
   * @brief Destructor for Buffer.
   */
   ~Buffer();

   //Buffer& operator=(const Buffer& other);
   Buffer& operator=(Buffer&& other);

  /**
   * @brief Bind the buffer to the specified target.
   * @param t The target to bind the buffer to.
   */
  void bind() const;

  /**
   * @brief Get the size of the buffer.
   * @return The size of the buffer as an unsigned integer.
   */
  unsigned int size() const;

  /**
  * @brief Upload data to the buffer.
  * @param data A pointer to the data to upload.
  * @param size The size of the data to upload.
  * @param offset The offset in the buffer to upload the data to (default: 0).
  */
  void uploadData(const void *data, unsigned int size,
                          unsigned int offset = 0);

 protected:

  unsigned int id_;
  unsigned int size_;
  
  Buffer::Target target_;

  bool destroy_ = true;

 private:
  

}; 

#endif
