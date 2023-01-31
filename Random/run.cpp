//
// Created by soham on 12/26/22.
//
// https://www.youtube.com/watch?v=45MIykWJ-C4
#include "../Classes/Libs/libs.hpp"
#include "VGL/scenes/Scenes.hpp"

const int ALIGNMENT = 128;
float cam_theta = 25, cam_dist = 8;
int sceneCnt = 1;

int main(int argc, char *argv[])
{
    if (!glfwInit())
    {
        printf("GLFW error!\n");
        return 1;
    }
    GLFWmonitor *MyMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(MyMonitor);
    int mWidth = glfwGetVideoMode(glfwGetPrimaryMonitor())->width, mHeight = glfwGetVideoMode(glfwGetPrimaryMonitor())->height;
    window = glfwCreateWindow(mWidth, mHeight, "Astravarse", MyMonitor, NULL);
    if (!window)
    {
        printf("\nwindow Error");
        return 1;
    }
    if (!video_reader_open(&vr_state, "Assets/Videos/logov.mp4"))
    {
        printf("Video Loading error\n");
        return 1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    frame_width = vr_state.width;
    frame_height = vr_state.height;
    if (posix_memalign((void **)&frame_data, ALIGNMENT, frame_width * frame_height * 4) != 0)
    {
        printf("Couldn't allocate frame buffer\n");
        return 1;
    }
    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, 1);
        }
        Switcher();
    }
    video_reader_close(&vr_state);
    return 0;
}