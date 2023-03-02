#ifndef VGL_CAMERA_H
#define VGL_CAMERA_H

#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "string"
#include "Headers/shader.h"
#include "Headers/VBO.h"
#include "Headers/VAO.h"
#include "Headers/EBO.h"
#include "Headers/texture.h"
#include "math.h"
#include "src/SOIL2/SOIL2.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>


class Camera
{
public:
    glm::vec3 Position;
    glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    int width, height;
    float speed = 0.1f;
    float sensetivity = 100.0f;

    Camera(int width, int height, glm::vec3 position);

    void Matrix(float FOVdeg,float nearplane,float farplane,Shader &shader,const char *uniform);
    void Inputs(GLFWwindow *window);
};

#endif