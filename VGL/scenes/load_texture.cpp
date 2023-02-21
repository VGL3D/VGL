#include "Classes/Libs/libs.hpp"
#include "math.h"
#include "VGL/scenes/Scenes.hpp"

GLint windowWidth, windowHeight;

// float vert2[] = {
//     0.5f, 0.5f, 0.0f, // top right
//     0.5f, -0.5f, 0.0f, // bottom right
//     -0.5f, -0.5f, 0.0f, // bottom left
//     -0.5f, 0.5f, 0.0f // top left
// };

GLfloat ind2[] = {
    0, 1, 3, // first triangle
    1, 2, 3};

GLfloat vert2[] =
    {
        -1, -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1,
        1, -1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1,
        -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1, -1,
        -1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1, -1,
        -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1,
        -1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 1};

GLfloat colors[] =
    {
        0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0,
        1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0,
        0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0,
        0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1};

void draw_cube()
{

    static float alpha = 0;
    // attempt to rotate cube
    glRotatef(alpha, 0, 1, 0);

    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vert2);
    glColorPointer(3, GL_FLOAT, 0, colors);

    /* Send data : 24 vert2 */
    glDrawArrays(GL_QUADS, 0, 24);

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    alpha += 1;
}

void test_cube()
{
    // Scale to window size  09bny76vvv
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    glViewport(0, 0, windowWidth, windowHeight);
    // Draw stuff
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluPerspective(60, (double)windowWidth / (double)windowHeight, 0.1, 100);

    glMatrixMode(GL_MODELVIEW_MATRIX);
    glTranslatef(0, 0, -5);

    draw_cube();
    glfwSwapBuffers(window);
    glfwPollEvents();
}

// void testing()
// {
//     glfwInit();
//     window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         printf("Failed to create GLFW window");
//         glfwTerminate();
//         return -1;
//     }
//     GLenum err;
//     glfwMakeContextCurrent(window);
//     glewExperimental = GL_TRUE;
//     if (glewInit() != GLEW_OK)
//     {
//         std::cout << glewGetErrorString(err) << "\n";
//     }

//     glViewport(0, 0, 800, 600);
//     while (!glfwWindowShouldClose(window))
//     {
//         glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//         // shaderProgram.Activate();
//         // vao1.Bind();
//         // glDrawArrays(GL_QUADS, 0, 24);
//         // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//         display();
//     }
//     glfwTerminate();
//     return 0;
// }