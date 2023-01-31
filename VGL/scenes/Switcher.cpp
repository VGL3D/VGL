//
// Created by soham on 1/5/23.
//

#ifndef VGL_SWITCHER_CPP
#define VGL_SWITCHER_CPP

#include "Classes/Libs/libs.hpp"
#include "Scenes.hpp"
#include "VGL/scenes/Scene2/scene2.hpp"

// GLuint VBO, VAO, EBO;
// GLFWwindow *window;
void Switcher(Shader ourShader)
{
    const time_t endwait = time(NULL) + 10;
    if (time(NULL) <= endwait - 6)
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // std::cout<<"Reached\n";
        LoadVideo();
        glfwSwapBuffers(window);
        glfwPollEvents();
        sceneCnt = 2;
    }
    else if (time(NULL) == endwait - 1)
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        sceneCnt = 3;
        glfwSwapBuffers(window);
        glfwPollEvents();
        // exit(1);
    }
    else if (time(NULL) <= endwait - 10)
    {
        load_text(ourShader);
    }
    else
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    std::cout<<"Time:" << time(NULL) << "Remaining:" << endwait << "\n";
    std::cout<<sceneCnt<<"\n";
}

#endif // VGL_SWITCHER_CPP
