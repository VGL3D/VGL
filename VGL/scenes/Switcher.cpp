//
// Created by soham on 1/5/23.
//

#ifndef VGL_SWITCHER_CPP
#define VGL_SWITCHER_CPP

#include "Classes/Libs/libs.hpp"
#include "Scenes.hpp"
#include "scene2.hpp"

void Switcher(int scene) {
    if(scene == 1){
        glutDisplayFunc(displayText);
    }
    else if(scene == 2){
        std::cout<<"You reached scene2\n";
    }
    else {
        std::cout<<"Error at switcher\n";
    }
}

#endif //VGL_SWITCHER_CPP
