//
// Created by soham on 1/5/23.
//

#ifndef VGL_SWITCHER_CPP
#define VGL_SWITCHER_CPP

#include "Classes/Libs/libs.hpp"
#include "Scenes.hpp"
#include "VGL/scenes/Scene2/scene2.hpp"

GLuint VBO, VAO, EBO,texture;
void Switcher() {
    if(sceneCnt == 1){
    Shader ourShader("res/shaders/core.vs", "res/shaders/core.frag");
    load_texture();
    load_text();
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    }
    else if(sceneCnt == 2){
        std::cout<<"You reached scene2\n";
    }
    else {
        std::cout<<"Error at switcher\n";
    }
    std::cout<<sceneCnt<<"\n";
}

#endif //VGL_SWITCHER_CPP
