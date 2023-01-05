//
// Created by soham on 12/26/22.
//
//https://www.youtube.com/watch?v=45MIykWJ-C4
#include "../Classes/Libs/libs.hpp"
#include "VGL/scenes/scene1.hpp"
#include "VGL/scenes/Switcher.hpp"

int main(int argc,char *argv[]){
    sceneCnt = 1;
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Game");
    //glutFullScreen();

    Switcher(&sceneCnt);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
} 