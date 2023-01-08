//
// Created by soham on 1/5/23.
//

#ifndef VGL_SWITCHER_CPP
#define VGL_SWITCHER_CPP

#include "Classes/Libs/libs.hpp"
#include "Scenes.hpp"
#include "scene2.hpp"

void Switcher() {
    if(sceneCnt == 1){
        glutDisplayFunc(displayText);
    }
    else if(sceneCnt == 3){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        std::cout<<"You reached scene2\n";
        glutSwapBuffers();
    }
    else {
        std::cout<<"Error at switcher\n";
    }
    std::cout<<sceneCnt<<"\n";
}

#endif //VGL_SWITCHER_CPP
