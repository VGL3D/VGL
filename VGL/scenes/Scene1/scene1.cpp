//
// Created by soham on 1/7/23.
//

#include "VGL/scenes/Scenes.hpp"

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "VGL/SOIL2/SOIL2.h"
#include "VGL/Shader.h"

const GLuint WIDTH = 800, HEIGHT = 600;
Shader ourShader = Shader("res/shaders/core.vs", "res/shaders/core.frag");

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
    // Scale to window size
    GLint windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    glViewport(0, 0, windowWidth, windowHeight);
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluPerspective(60, (double)windowWidth / (double)windowHeight, 0.1, 100);
    glMatrixMode(GL_MODELVIEW_MATRIX);
    glTranslatef(0, 0, -5);

    drawCube();
}

int load_text()
{
    glfwPollEvents();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // std::cout<<"VAO:"<<VAO<<"VBO:"<<VBO<<"EBO:"<<EBO<<"\n";
    //  Draw the triangle
    ourShader.Use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture"), 0);
    // Draw container
    glBindVertexArray(VAO);
    display();
    glBindVertexArray(0);

    return EXIT_SUCCESS;
}

// void displayText() {
//     time_t endwait = time(NULL) + 10;
//     while (time(NULL) < endwait) {
//         if (time(NULL) == endwait - 6) {
//             glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//             //std::cout<<"Reached\n";
//             sceneCnt = 2;
//             LoadText();
//             glutSwapBuffers();
//         } else if (time(NULL) == endwait - 1) {
//             glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//             sceneCnt = 3;
//             glutSwapBuffers();
//             break;
//         } else {
//             glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//             //std::cout << time(NULL) << " " << endwait << "\n";
//             LoadText();
//             glutSwapBuffers();
//         }
//         std::cout << time(NULL) << " " << endwait << "\n";
//     }
// }