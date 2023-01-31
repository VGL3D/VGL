//
// Created by soham on 1/15/23.
//

#include "scene2.hpp"

GLFWwindow *window;
VideoReaderState vr_state;
using namespace std;
const int ALIGNMENT = 128;
int frame_width;
int frame_height;
uint8_t *frame_data;
GLuint tex_handle;

int genrate_textures(){
    glGenTextures(1, &tex_handle);
    glBindTexture(GL_TEXTURE_2D, tex_handle);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, 0);
}

int LoadVideo() {
    //glfwMaximizeWindow(window);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Set up orphographic projection
    int window_width, window_height;
    glfwGetFramebufferSize(window, &window_width, &window_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = window_width / window_height;
    glViewport(0, 0, window_width, window_height);
    glOrtho(window_width / 8, (window_width), window_height, window_height / 5, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    // Read a new frame and load it into texture
    int64_t pts;
    if (!video_reader_read_frame(&vr_state, frame_data, &pts)) {
        printf("Couldn't load video frame\n");
        return 1;
    }
    static bool first_frame = true;
    if (first_frame) {
        glfwSetTime(0.0);
        first_frame = false;
    }
    double pt_in_seconds = pts * (double) vr_state.time_base.num / (double) vr_state.time_base.den;
    while (pt_in_seconds > glfwGetTime()) {
        glfwWaitEventsTimeout(pt_in_seconds - glfwGetTime());
    }
    glBindTexture(GL_TEXTURE_2D, tex_handle);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, frame_width, frame_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, frame_data);
    // Render whatever you want
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex_handle);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex2i(window_width / 8, window_height / 5);
    glTexCoord2d(1, 0);
    glVertex2i(window_width, window_height / 5);
    glTexCoord2d(1, 1);
    glVertex2i(window_width, window_height);
    glTexCoord2d(0, 1);
    glVertex2i(window_width / 8, window_height);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

