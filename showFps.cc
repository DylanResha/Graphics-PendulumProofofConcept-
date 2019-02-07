#ifndef SHOW_FPS
#define SHOW_FPS

#include "includes.h"
#include "globals.h"
#include <stdio.h>

void drawString(GLuint x, GLuint y, void *font, const char* string)
{
 const char *c;
 glRasterPos2i(x, y);

  for(c=string; *c!='\0'; c++)
	glutBitmapCharacter(font, *c);


}

void showFPS(){
 static float fps;

 frames++;
 int currentTime=glutGet(GLUT_ELAPSED_TIME);
 
 if (currentTime - oldTime > 1000){
  fps = frames*1000.0/(currentTime-oldTime);
  oldTime = currentTime;
  frames = 0;
 }

 char *charString = (char*) malloc(12*sizeof(char));
 sprintf(charString, "FPS: %6.1f", fps);

 glMatrixMode(GL_PROJECTION);
 glPushMatrix();
 glLoadIdentity();
 gluOrtho2D(0.0, 500.0, 0.0, 500.0);

 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glLoadIdentity();

 glColor3f(255,255,0);
 drawString(50,50,GLUT_BITMAP_HELVETICA_12,charString);

 glPopMatrix();
 glMatrixMode(GL_PROJECTION);
 glPopMatrix();
 glMatrixMode(GL_MODELVIEW);

 free(charString);

}

#endif
