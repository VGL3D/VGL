//
// Created by soham on 12/24/22.
//

#ifndef GAMECLION_LOADTEXTURE_HPP
#define GAMECLION_LOADTEXTURE_HPP

#define STB_IMAGE_IMPLEMENTATION
#include "../ImageLoader/stb_image.hpp"
#include "GL/freeglut.h"
#include "iostream"
#include "vector"
#include "string"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "stdlib.h"

using namespace std;

//int width, height, nrChannels;
//unsigned char *data = stbi_load("/home/soham/Documents/objects/trishul/tris.png", &width, &height,
//                                &nrChannels, 0);
class LoadTextures{
public:
    int width, height, nrChannels;
    char LoadTexture(char *path);
};

char LoadTextures :: LoadTexture(char *path){
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path, &width, &height,
                                    &nrChannels, 0);

    if (data)
    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
//                     GL_UNSIGNED_BYTE, data);
        return *data;
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture");
    }
    stbi_image_free(data);
}

#endif //GAMECLION_LOADTEXTURE_HPP
