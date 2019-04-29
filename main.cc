#include "includes.h"
#include "globals.h"



double thetadot(double t, double theta, double omega)
{
   return omega;
}

double omegadot(double t, double theta, double omega)
{
   static double R = 1.00;  // Length of pendulum  (meters)
   static double g = 9.80;  // Normalized gravitational constant  (m/s^2)
   static double b = 0.0;  // Frictional damping constant
   static double m = 1.00;  // Mass in normalized gravitational units (kg)
   static double A = 0.20;  // Amplitude of initial driving force
   static double k = 0.50;  // Frequency parameter of initial driving force

   double num, denom;

   num = -b*omega + A*cos(k*t);
   denom = m*R*R;
   // To test limiting case of small theta, use following line of code
   //return -g/R*theta;


   return (-g/R*sin(theta)+num)/denom;

}


// This is the function that actually propagates the motion 

void step(double *t, double *theta, double *omega )
{
  // Time step variables
  double dt, h; 
  // variables for fourth-order Runge-Kutta method
  double k1, k2, k3, k4, j1, j2, j3, j4;

  h=10000.0/Nstep;   // Try changing the value of Nstep above to see what happens 

      // Fourth-Order Runge-Kutta propagation step for second order dynamical systems
        k1 = thetadot(*t, *theta, *omega); 
        j1 = omegadot(*t, *theta, *omega); 
        k2 = thetadot(*t+h/2, *theta+h/2*k1, *omega+h/2*j1); 
        j2 = omegadot(*t+h/2, *theta+h/2*k1, *omega+h/2*j1); 
        k3 = thetadot(*t+h/2, *theta+h/2*k2, *omega+h/2*j2); 
        j3 = omegadot(*t+h/2, *theta+h/2*k2, *omega+h/2*j2); 
        k4 = thetadot(*t+h, *theta+h*k3, *omega+h*j3); 
        j4 = omegadot(*t+h, *theta+h*k3, *omega+h*j3); 
        *theta = *theta + h/6*(k1+2*k2+2*k3+k4);
        *omega = *omega + h/6*(j1+2*j2+2*j3+j4);
        *t = *t + h;
 glutPostRedisplay();
}

void idleFunc(){

      step( &t, &theta, &omega);

}

void keyInput( unsigned char key, int x, int y)
{

if(key == 'd' || key == 'D'){

Cam_x = Cam_x + 0.2;
Cent_x = Cent_x + 0.2;
 }

if(key == 'a' || key == 'A'){

Cam_x = Cam_x - 0.2;
Cent_x = Cent_x - 0.2;
 }

if(key == 's' || key == 's'){

Cam_y = Cam_y - 0.2;
Cent_y = Cent_y - 0.2;
 }

if(key == 'w' || key == 'W'){

Cam_y = Cam_y + 0.2;
Cent_y = Cent_y + 0.2;
 }

if(key == 'c' || key == 'C'){


 }

if(key == 'z' || key == 'Z'){

 }

glutPostRedisplay();
}

int main(int argc, char** argv)
{

 
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1000, 1000); 
    glutInitWindowPosition (400, 400);
    glutCreateWindow (argv[0]);
    init ();
    glutKeyboardFunc(keyInput);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display); 
    glutIdleFunc(idleFunc);
    glutMainLoop();
    return 0;
}

