
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void init(void) 
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
}


//main for objects
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutReshapeFunc(reshape); 
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;
}
//main from pend math to be added
int main(int argc, char** argv)
{

   double t=0.0;
   double theta=M_PI/4.0;
   double omega=0.0;

   for (long i=0; i<2*Nstep; i++ ) {
      printf("%f %f %f\n", t, theta, omega);
      step( &t, &theta, &omega);
   } 
}
