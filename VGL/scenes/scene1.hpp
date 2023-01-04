//
// Created by soham on 1/5/23.
//

#ifndef VGL_SCENE1_HPP
#define VGL_SCENE1_HPP

#include "Classes/Libs/libs.hpp"

int win_width, win_height;
float cam_theta, cam_phi = 25, cam_dist = 8;
float cam_pan[3];
int mouse_x, mouse_y;
int bnstate[8];
int anim, help;
long anim_start;
long nframes;


#define ZNEAR	0.5f
void reshape(int x, int y)
{
    float vsz, aspect = (float)x / (float)y;
    win_width = x;
    win_height = y;

    glViewport(0, 0, x, y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    vsz = 0.4663f * ZNEAR;
    glFrustum(-aspect * vsz, aspect * vsz, -vsz, vsz, 0.5, 500.0);
}

void LoadText(void)
{
    int i;
    const char *s, **text;

    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, win_width, 0, win_height, -1, 1);

    text = helptext ;

    for(i=0; helptext[i]; i++) {
        glColor3f(0.5, 0.1, 0);
        glRasterPos2f(win_width/6, win_height - (i + 1) * 20 - 2);
        s = text[i];
        while(*s) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *s++);
        }
        glColor3f(0.9, 0.9, 0.9);
        glRasterPos2f(win_width/6, win_height - (i + 1) * 20);
        s = text[i];
        while(*s) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *s++);
        }
    }

    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glPopAttrib();
}

void displayText(){
    time_t endwait = time(NULL) + 3;
    while(time(NULL) < endwait) {
        std::cout<<time(NULL)<<" "<<endwait<<"\n";
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        LoadText();
        glutSwapBuffers();
    }
}

#endif //VGL_SCENE1_HPP
