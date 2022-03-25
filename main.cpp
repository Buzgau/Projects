#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
char title[] = "Barcuta pe mare ";

void initGL() {
        glClearColor(0.0f, 0.3f, 1.0f, 1.0f); /// Set skycolor
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glShadeModel(GL_SMOOTH);
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glMatrixMode(GL_MODELVIEW);
glRotatef(0.02, 0.1, 0.0, 0.1);
/// Ocean
    glLoadIdentity();
    glTranslatef(0.0f,-5.0f,0.0f);
    glColor3f(0,1,1);
    glBegin(GL_QUADS);
        glVertex3f(100,0,100);
        glVertex3f(100,0,-100);
        glVertex3f(-100,0,-100);
        glVertex3f(-100,0,100);
    glEnd();
///



///Varf Barca
    glLoadIdentity();
    glTranslatef(0.0f, -4.75f, -15.0f);
    glBegin(GL_TRIANGLES);

    ///Lateral spate varf
        glColor3f(0.34,0.25,0.01);
        glVertex3f(-3,1,-1);
        glVertex3f(-3,-1,0);
        glVertex3f(-5,1,0);

    ///Lateral fata varf
        glColor3f(0.27,0.20,0.07);
        glVertex3f(-3,1,1);
        glVertex3f(-3,-1,0);
        glVertex3f(-5,1,0);

   /// capac varf
        glColor3f(0.36,0.24,0.03);
        glVertex3f(-3,1,-1);
        glVertex3f(-3,1,1);
        glVertex3f(-5,1,0);
    glEnd();

///

///Corp Barca
glLoadIdentity();

glTranslatef(0.0f, -4.75f, -15.0f);


glBegin(GL_QUADS);


glColor3f(0.34,0.25,0.01);
glVertex3f( 3.0f, 1.0f, 1.0f);
glVertex3f(-3.0f, 1.0f, 1.0f);
glVertex3f(-3.0f, -1.0f, 0.0f);
glVertex3f( 3.0f, -1.0f, 0.0f);



    glColor3f(0.36,0.24,0.03);;
    glVertex3f( 3.0f, -1.0f, 0.0f);
    glVertex3f(-3.0f, -1.0f, 0.0f);
    glVertex3f(-3.0f, 1.0f, -1.0f);
    glVertex3f( 3.0f, 1.0f, -1.0f);

/// Fundul Barcii  (x = 1.0f)
    glColor3f(0.34f, 0.25f, 0.01f);
    glVertex3f(3.0f, 1.0f, -1.0f);
    glVertex3f(3.0f, 1.0f, 1.0f);
    glVertex3f(3.0f, -1.0f, 0.0f);
    glVertex3f(3.0f, -1.0f, 0.0f);

glEnd();
///


glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
if (height == 0) height = 1;
GLfloat aspect = (GLfloat)width / (GLfloat)height;

glViewport(0,0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(90.0f, aspect, 0.9f, 100.0f);
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE);
glutInitWindowSize(1599, 899);
glutInitWindowPosition(0, 0);

glutCreateWindow(title);
glutDisplayFunc(display);

glutReshapeFunc(reshape);

initGL();
glutMainLoop();
return 0;
}
