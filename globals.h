#ifndef GLOBAL
#define GLOBAL

extern void display(void);
extern void init(void);
extern void reshape(int, int);
extern void step(double*, double*, double*);
extern void drawString(GLuint, GLuint, void*, const char*);
extern void showFPS(void);
extern void showFPP(void);
extern void checkFPS(int);
extern double t;
extern double theta;
extern double omega;
extern unsigned frames;
extern int oldTime;

#endif
