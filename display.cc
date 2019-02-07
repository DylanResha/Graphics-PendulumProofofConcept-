#include "includes.h"
#include "globals.h"


//pulled from main.cc
void display(void)
{

extern double theta;

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 

    // We are going to set our position to be down the Y-Axis looking at the
    // center of the coordinate frame.  The positive Z-Axis will be up.

    gluLookAt( 20.0,   0.0, 5.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up


    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);

    // This should be to draw a cylinder 
    glPushMatrix();
    glTranslated(2.0,0.0,5.0);  
    glRotatef(-90.0,1.0,1.0,0.0);  
    glColor3f (1.0,0.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 4.0,
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();

    // This should be to draw a cylinder 
    glPushMatrix();
    glTranslated(2.0,0.0,1.0);    
    glColor3f (0.0,0.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 4.0,
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();

    // This should be to draw a cylinder 
    glPushMatrix();
    glTranslated(-3.0,3.0,-5.0);    
    glColor3f (0.0,1.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 10.0,
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();

    // This should draw a red sphere 
    glPushMatrix();
    glRotated((double)180*theta/M_PI,1,0,0);
    glRotated((double)180*theta/M_PI,0,0,1);

    glColor3f (1.0,0.0,0.0);
    gluSphere(gluNewQuadric(), 
             (GLdouble) 0.5,
             (GLint)     10,
             (GLint)     10 );
    glPopMatrix();

    glutSwapBuffers();

 frames++;

}
