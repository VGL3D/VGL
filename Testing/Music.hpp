//
// Created by soham on 12/15/22.
//

#ifndef GAMECLION_MUSIC_HPP
#define GAMECLION_MUSIC_HPP

#include "Python.h"
#include "../Constants/Common.hpp"

class Sounds{
public:
    int sceneNum;
    void PlayAudio(int scene);
};

void Sounds :: PlayAudio(int scene) {
    Py_Initialize();
    PyObject *myResult,*myModule,*pName;
    PyRun_SimpleString(getPycode());
    myResult = PyObject_CallMethod((PyObject *) "", "getchar", NULL);
    Py_Finalize();
}

#endif //GAMECLION_MUSIC_H
