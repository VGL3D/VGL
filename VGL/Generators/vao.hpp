#include <iostream>
#include <GL/glew.h>

class VAO {
public:
  VAO() {
    glGenVertexArrays(1, &mVAO);
  }

  ~VAO() {
    glDeleteVertexArrays(1, &mVAO);
  }

  void bind() const {
    glBindVertexArray(mVAO);
  }

  void unbind() const {
    glBindVertexArray(0);
  }

  void setVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) const {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
  }

private:
  GLuint mVAO;
};
