#include "includes.h"
#include "globals.h"

unsigned frames = 0;
//pulled from main.cc
void display(void)
{


    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 

    // We are going to set our position to be down the Y-Axis looking at the
    // center of the coordinate frame.  The positive Z-Axis will be up.

    gluLookAt( 20.0,   0.0, 5.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up


    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);


    // This should draw a red sphere 
    glPushMatrix();
    glTranslatef(t, theta, omega);
    glColor3f (0.0,1.0,0.0);
    gluSphere(gluNewQuadric(), 
             (GLdouble) 0.5,
             (GLint)     10,
             (GLint)     10 );
    glPopMatrix();

    glutSwapBuffers();

 frames++;

}
