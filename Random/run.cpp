//
// Created by soham on 12/26/22.
//
//https://www.youtube.com/watch?v=45MIykWJ-C4
#include "../Classes/Libs/libs.hpp"
#include "VGL/scenes/Scenes.hpp"
//#include "VGL/scenes/Counter.hpp"

float cam_theta = 25, cam_dist = 8;

int main(int argc,char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Game");
    //glutFullScreen();

    Switcher();
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
} 