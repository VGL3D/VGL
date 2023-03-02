//
// Created by soham on 1/5/23.
//

#ifndef VGL_SWITCHER_CPP
#define VGL_SWITCHER_CPP

#include "Classes/Libs/libs.hpp"
#include "unistd.h"
#include "VGL/Scenes.hpp"

// GLuint VBO, VAO, EBO;
// GLFWwindow *window;
void Switcher(Shader ourShader)
{
    std::cout << "Cuurent scene no:" << sceneCnt << "\n";
    const time_t endwait = time(NULL) + 10;
    if (sceneCnt == 1)
    {
        //test_cube();
        //load_text(ourShader);
        LoadVideo();
        //sceneCnt = 2;
    }
    else if (sceneCnt == 3)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        sceneCnt = 3;
        glfwSwapBuffers(window);
        glfwPollEvents();
        // exit(1);
    }
    else if (sceneCnt == 2)
    {
        LoadVideo();
    }
    else
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        std::cout << "Reached scene 4" << std::endl;
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    std::cout << "Time:" << time(NULL) << " Remaining:" << endwait << "\n";
}

#endif // VGL_SWITCHER_CPP
