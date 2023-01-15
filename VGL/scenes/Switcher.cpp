//
// Created by soham on 1/5/23.
//

#ifndef VGL_SWITCHER_CPP
#define VGL_SWITCHER_CPP

#include "Classes/Libs/libs.hpp"
#include "Scenes.hpp"
#include "VGL/scenes/Scene2/scene2.hpp"


void Switcher() {
    if(sceneCnt == 1){
        LoadVideo();
    }
    else if(sceneCnt == 3){
        std::cout<<"You reached scene2\n";
    }
    else {
        std::cout<<"Error at switcher\n";
    }
    std::cout<<sceneCnt<<"\n";
}

#endif //VGL_SWITCHER_CPP
