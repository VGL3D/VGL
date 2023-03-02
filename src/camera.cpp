#include "camera.h"

Camera ::Camera(int width, int height, glm::vec3 position)
{
    Camera::width = width;
    Camera::height = height;
    Position = position;
}

void Camera ::Matrix(float FOVdeg, float nearplane, float farplane, Shader &shader, const char *uniform)
{
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(Position, Position + orientation, up);
    projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearplane, farplane);

    glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}

void Camera ::Inputs(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        Position += speed * orientation;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        Position += speed * -glm::normalize(glm::cross(orientation, up));
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        Position += speed * -orientation;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        Position += speed * glm::normalize(glm::cross(orientation, up));
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        Position += speed * up;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    {
        Position += speed * -up;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        speed = 0.4f;
    }
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
    {
        speed = 0.1f;
    }

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        double mouseX;
        double mouseY;

        glfwGetCursorPos(window, &mouseX, &mouseY);

        float roatx = sensetivity * (float)(mouseY - (height / 2)) / height;
        float roaty = sensetivity * (float)(mouseX - (height / 2)) / height;

        // Calculates upcoming vertical change in the Orientation
        float angle = glm::radians(-roatx);
        glm::vec3 axis = glm::normalize(glm::cross(orientation, up));
        glm::quat rotation = glm::angleAxis(angle, axis);
        glm::vec3 newOrientation = rotation * orientation;

        // Decides whether or not the next vertical Orientation is legal or not
        if (abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f))
        {
            orientation = newOrientation;
        }

        // Rotates the Orientation left and right
        orientation = glm::rotate(orientation, glm::radians(-roaty), up);

        // Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
        glfwSetCursorPos(window, (width / 2), (height / 2));
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}