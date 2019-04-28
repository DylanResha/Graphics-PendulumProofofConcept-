#include "includes.h"
#include "globals.h"



void glutSleep(int millisecondsToWait){

	int startTime=glutGet(GLUT_ELAPSED_TIME);

	do{/*waiting*/}
	while((glutGet(GLUT_ELAPSED_TIME)-startTime)<millisecondsToWait);

}

void display(void)
{

 extern double theta;
   // printf("%f\n",theta);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 

    // We are going to set our position to be down the Y-Axis looking at the
    // center of the coordinate frame.  The positive Z-Axis will be up.

    gluLookAt( Cam_x, Cam_y, Cam_z,  // Eye
                Cent_x, Cent_y, Cent_z,  // Center
                0.0,   0.0, 1.0); // Up


    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);

glPushMatrix();
glTranslated(10.0, 10.0, 1.0);
glScaled(0.1, 0.1, 0.1);

    // This should be to draw a cylinder horizontal support
    glPushMatrix();
    glTranslated(2.0, 0.0, 11.0);  
    glRotatef(-90.0, -1.0, 0.0, 0.0);  
    glColor3f (1.0,0.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 4.0,
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();


    // This should be to draw a cylinder back hold
    glPushMatrix();
    glTranslated(2.0, 0.0, 3.0); 
    glColor3f (0.0,1.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 8.0,
            (GLint)    40,
            (GLint)    40 );
    glPopMatrix();

    // This should be to draw a cylinder pendulum
    glPushMatrix();
    glTranslated(2.0,0.0,11.0);
    glRotatef(180.0,1.0,0.0,0.0); 
    glRotated((double)180*theta/M_PI,1,0,0);
    glRotated((double)180*theta/M_PI,0,0,1);    
    glColor3f (0.0,0.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 4.0,
            (GLint)    40,
            (GLint)    40 );
    glPopMatrix();



    // This should draw a red sphere 
    glPushMatrix();
     glTranslated(2.0,0.0,11.0);
      glRotated((double)180*theta/M_PI,1,0,0);
      glRotated((double)180*theta/M_PI,0,0,1);
     glTranslated(0.0, 0.0, -4.0);
    glColor3f (1.0,0.0,0.0);
    gluSphere(gluNewQuadric(), 
             (GLdouble) 0.5,
             (GLint)     10,
             (GLint)     10 );

    glPopMatrix();

//cylinder base
 glPushMatrix();
  glTranslated(2.0,2.5,3.0);
  glColor3f (0.0,1.0,0.0);
  gluDisk(gluNewQuadric(), 
    (GLdouble) 0,
    (GLdouble) 5,
    (GLint)    20,
    (GLint)    10 );
 glPopMatrix();

 glPushMatrix();
  glTranslated(2.0,2.5,2.5);
  glColor3f (0.0,0.8,0.0);
  gluCylinder(gluNewQuadric(), 
    (GLdouble) 5,
    (GLdouble) 5,
    (GLdouble) 0.5,
    (GLint)    20,
    (GLint)    10 );
 glPopMatrix();
glPopMatrix();

///////////////////////////////
//Room
//floor
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 20.0, 0.0, 0.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 20.0, 0.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.0, 20.0, 0.0 );
	  glEnd();
	glPopMatrix();

//ceiling
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.6, 0.8);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 10.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 20.0, 0.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 20.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.0, 20.0, 10.0 );
	  glEnd();
	glPopMatrix();

//left wall
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.0, 0.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.0, 20.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.0, 20.0, 0.0 );
	  glEnd();
	glPopMatrix();

//right wall
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 20.0, 0.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 20.0, 0.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 20.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 20.0, 20.0, 0.0 );
	  glEnd();
	glPopMatrix();

//back wall
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.6);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 20.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.0, 20.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 20.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 20.0, 20.0, 0.0 );
	  glEnd();
	glPopMatrix();

//front wall
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.6);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.0, 0.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 0.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 20.0, 0.0, 0.0 );
	  glEnd();
	glPopMatrix();
///////////////////////////////

///////////////////////////////    
    showFPS();
    showFPP();
    glutSwapBuffers();
//#ifdef SYNC
    float desired = 1/60;
    glutSleep(desired);
//#endif


}
