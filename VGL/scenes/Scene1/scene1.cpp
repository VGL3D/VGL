//
// Created by soham on 1/7/23.
//

#include "VGL/scenes/Scenes.hpp"

//float cam_theta = 25, cam_dist = 8;
int win_height, win_width;

void reshape(int x, int y) {
    float vsz, aspect = (float) x / (float) y;
    win_width = x;
    win_height = y;

    glViewport(0, 0, x, y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    vsz = 0.4663f * ZNEAR;
    glFrustum(-aspect * vsz, aspect * vsz, -vsz, vsz, 0.5, 500.0);
}
//
//void LoadText() {
//    int i;
//    const char *s, **text;
//
//    glPushAttrib(GL_ENABLE_BIT);
//    glDisable(GL_LIGHTING);
//    glDisable(GL_DEPTH_TEST);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glMatrixMode(GL_PROJECTION);
//    glPushMatrix();
//    glLoadIdentity();
//    glOrtho(0, win_width, 0, win_height, -1, 1);
//
//    text = sceneCnt == 1 ? helptext : scene2;
//
//    for (i = 0; text[i]; i++) {
//        glColor3f(0.5, 0.1, 0);
//        glRasterPos2f(win_width / 6, win_height - (i + 1) * 20 - 2);
//        s = text[i];
//        while (*s) {
//            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *s++);
//        }
//        glColor3f(0.9, 0.9, 0.9);
//        glRasterPos2f(win_width / 6, win_height - (i + 1) * 20);
//        s = text[i];
//        while (*s) {
//            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *s++);
//        }
//    }
//    glPopMatrix();
//    glMatrixMode(GL_MODELVIEW);
//    glPopAttrib();
//}
//
//void displayText() {
//    time_t endwait = time(NULL) + 10;
//    while (time(NULL) < endwait) {
//        if (time(NULL) == endwait - 6) {
//            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//            //std::cout<<"Reached\n";
//            sceneCnt = 2;
//            LoadText();
//            glutSwapBuffers();
//        } else if (time(NULL) == endwait - 1) {
//            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//            sceneCnt = 3;
//            glutSwapBuffers();
//            break;
//        } else {
//            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//            //std::cout << time(NULL) << " " << endwait << "\n";
//            LoadText();
//            glutSwapBuffers();
//        }
//        std::cout << time(NULL) << " " << endwait << "\n";
//    }
//}