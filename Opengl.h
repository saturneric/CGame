//
//  Opengl.h
//  CGame
//
//  Created by Eric on 16/7/22.
//  Copyright © 2016年 Bakantu Eric. All rights reserved.
//

#ifndef Opengl_h
#define Opengl_h

#include <GLUT/glut.h>

/*Var*/
lnd *g_lnd = NULL;
cty *g_cty = NULL;
int *form = NULL;

/*Function*/

//MAJOR
void oglinit(int argc, const char * argv[]);
void oglstart(void);
void game_engine(void);
void ctl_engine(int will);
void ogl_menu(void);
void ogl_game(void);
void ogl_gmenu(void);

//DESCRIBE
void oglinit(int argc, const char * argv[]){
    glutInit(&argc, (char **) argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 300);
    glutCreateWindow("CGame");
    glutDisplayFunc(&ogl_menu);
    glutMainLoop();
}

void ogl_menu(void){
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(1, 1);
    glVertex2f(1, 0);
    glVertex2f(0, 1);
}


#endif /* Opengl_h */
