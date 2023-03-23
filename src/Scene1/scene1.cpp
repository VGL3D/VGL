//
// Created by soham on 1/7/23.
//

#include "VGL/Scenes.hpp"

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL/SOIL.h"
#include "VGL/Shader.h"

const GLuint WIDTH = 800, HEIGHT = 600;
GLuint VBO, VAO, EBO, texture;

GLfloat vertices[] =
    {
        // Positions          // Colors           // Texture Coords
        1.5f, 1.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // Top Right
        1.5f, -1.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // Bottom Right
        -1.5f, -1.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
        -1.5f, 1.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // Top Left
};
GLfloat indices[] =
    {
        // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
};

void load_texture(char *path)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0); // Unbind VAO
    int width, height;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    unsigned char *image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGBA);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    std::cout<<"VAOtest:"<<VAO<<"VBO:"<<VBO<<"EBO:"<<EBO<<"\n";
}

void drawCube()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void display()
{
    int win_width, win_height;
    glfwGetFramebufferSize(window, &win_width, &win_height);
    // Scale to window size
    glViewport(0, 0, win_width, win_height);
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluPerspective(60, (double)win_width / (double)win_width, 0.1, 100);
    glMatrixMode(GL_MODELVIEW_MATRIX);
    glTranslatef(0, 0, -5);

    drawCube();
}

// GLuint VBO, VAO, EBO,texture;

int load_text(Shader ourShader)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    std::cout<<"VAO:"<<VAO<<"VBO:"<<VBO<<"EBO:"<<EBO<<"\n";
    //  Draw the triangle
    // Shader ourShader;
    ourShader.Use();
    std::cout<<"Shader program:"<<ourShader.Program<<std::endl;
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture"), 0);
    // Draw container
    glBindVertexArray(VAO);
    display();
    glBindVertexArray(0);
    glfwSwapBuffers(window);
    glfwPollEvents();

    return EXIT_SUCCESS;
}
