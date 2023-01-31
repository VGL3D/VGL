//
// Created by soham on 1/5/23.
//

#ifndef VGL_SCENES_HPP
#define VGL_SCENES_HPP

#include "Classes/Libs/libs.hpp"
#include "VGL/scenes/common.hpp"
#include "VGL/Shader.h"

// #include "Counter.hpp"
extern int sceneCnt;
extern int win_width, win_height;
extern float cam_theta, cam_phi, cam_dist;
extern float cam_pan[3];
extern int mouse_x, mouse_y;
extern int bnstate[8];
extern int anim, help;
extern long anim_start;
extern long nframes;
extern GLuint VBO, VAO, EBO, texture;

struct WindowData
{
    int window_height;
    int window_width;
};

struct VideState
{
    const int frame_height;
    const int frame_width;
};

extern char* path;
//extern Shader ourShader;

#define ZNEAR 0.5f
void Switcher(Shader ourShader);
void load_texture(char* path);
int load_text(Shader ourShader);
int genrate_textures();


#endif // VGL_SCENES_HPP
