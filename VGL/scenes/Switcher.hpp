//
// Created by soham on 1/5/23.
//

#ifndef VGL_SWITCHER_HPP
#define VGL_SWITCHER_HPP

#include "Classes/Libs/libs.hpp"
#include "scene1.hpp"
#include "scene2.hpp"
#include "Counter.hpp"

void Switcher(int *sceneCnt) {
    switch (*sceneCnt) {
        case 1:
            glutDisplayFunc(displayText);
//        case 2:
//            glutDisplayFunc(sceneTwo);
        default:
            std::cout<<"Error in switcher";
    }
}

#endif //VGL_SWITCHER_HPP
