#include <iostream>
#include <stdlib.h>
#include <Gl/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

void myInit() {
    glEnable(GL_DEPTH_TEST);
    gluOrtho2D(0, 1600, 0, 800);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float sun_move = 0.0f;
float cloud_move = 0.0f;
float cloud_move1 = 0.0f;
float cloud_move2 = 0.0f;
float boat_move = 0.0f;

bool start1 = false;
bool start2 = false;
bool start3 = false;

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'n': start1 = true; break;
    case 'd': start2 = true; break;
    }
}
void circle(float x, float y, double r) {
    float x1, y1;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200;i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 25;
        float x1 = x + ((r - 0.07) * cos(A));
        float y1 = y + ((r)*sin(A));
        glVertex2f(x1, y1);
    }
    glEnd();
}


void sky() {
    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.2);
    glVertex2f(-1.0, 1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, 0.2);
    glEnd();
}

void river() {
    glColor3f(0.255, 0.412, 0.882);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(-1.0, -0.5);
    glVertex2f(1.0, -0.1);
    glVertex2f(1.0, -1.0);
    glEnd();
}

void field() {
    glColor3f(0.420, 0.557, 0.137);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.2);
    glVertex2f(-1.0, -0.5);
    glVertex2f(1.0, -0.1);
    glVertex2f(1.0, 0.2);
    glEnd();
}

void hill() {
    glColor3f(0.627, 0.322, 0.176);
    glBegin(GL_POLYGON);
    glVertex2f(-0.20, 0.20);
    glVertex2f(0.03, 0.50);
    glVertex2f(0.20, 0.20);
    glEnd();
    glBegin(GL_POLYGON_BIT);
    glVertex2f(-0.05, 0.20);
    glVertex2f(-0.38, 0.45);
    glVertex2f(-0.60, 0.20);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.90, 0.20);
    glVertex2f(-0.65, 0.38);
    glVertex2f(-0.50, 0.20);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-1.3, 0.20);
    glVertex2f(-0.98, 0.35);
    glVertex2f(-0.90, 0.40);
    glVertex2f(-0.75, 0.20);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.56, 0.20);
    glVertex2f(0.38, 0.45);
    glVertex2f(0.10, 0.20);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.82, 0.20);
    glVertex2f(0.67, 0.40);
    glVertex2f(0.43, 0.20);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(1.3, 0.20);
    glVertex2f(0.89, 0.40);
    glVertex2f(0.71, 0.20);
    glEnd();
}

void sun()
{
    glColor3f(1.000, 0.843, 0.000);
    circle(-0.25, 0.75, 0.18);
}

void moon() {
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    circle(0.75, 0.75, 0.18);
    glPopMatrix();
}

void cloud1() {
    glColor3f(0.80, 0.80, 0.80);
    circle(-0.85, 0.77, 0.15);
    circle(-0.79, 0.70, 0.15);
    circle(-0.70, 0.70, 0.15);
    circle(-0.75, 0.77, 0.15);
}

void cloud2() {
    glColor3f(0.80, 0.80, 0.80);
    circle(0.35, 0.77, 0.15);
    circle(0.45, 0.70, 0.15);
    circle(0.55, 0.75, 0.15);
    circle(0.45, 0.80, 0.15);
}

void cloud3() {
    glColor3f(0.80, 0.80, 0.80);
    circle(-0.07, 0.85, 0.15);
    circle(-0.01, 0.80, 0.15);
    circle(0.08, 0.83, 0.15);
    circle(0.02, 0.85, 0.15);
}

void tree1() {
    glColor3f(0.38f, 0.19f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, -0.30);
    glVertex2f(-0.25, -0.12);
    glVertex2f(-0.27, -0.12);
    glVertex2f(-0.27, -0.30);
    glEnd();

    glColor3f(0.0, 0.43, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.36, -0.12);
    glVertex2f(-0.26, 0.12);
    glVertex2f(-0.16, -0.12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.36, -0.04);
    glVertex2f(-0.26, 0.20);
    glVertex2f(-0.16, -0.04);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.36, 0.04);
    glVertex2f(-0.26, 0.28);
    glVertex2f(-0.16, 0.04);
    glEnd();

}

void tree2() {
    glColor3f(0.38f, 0.19f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.20);
    glVertex2f(-0.05, 0.00);
    glVertex2f(-0.07, 0.00);
    glVertex2f(-0.07, -0.20);
    glEnd();

    glColor3f(0.0, 0.43, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.18, 0.00);
    glVertex2f(-0.06, 0.24);
    glVertex2f(0.06, 0.00);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.18, 0.08);
    glVertex2f(-0.18, 0.08);
    glVertex2f(-0.06, 0.32);
    glVertex2f(0.06, 0.08);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.18, 0.16);
    glVertex2f(-0.06, 0.40);
    glVertex2f(0.06, 0.16);
    glEnd();

}

void tree3() {
    glColor3f(0.38f, 0.19f, 0.0f);
    glLineWidth(7);
    glBegin(GL_LINES);
    glVertex2f(0.92, 0.0);
    glVertex2f(0.92, 0.11);
    glEnd();

    glColor3f(0.0, 0.43, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.98, 0.10);
    glVertex2f(0.92, 0.5);
    glVertex2f(0.86, 0.10);
    glEnd();
}

void tree4() {
    glColor3f(0.38f, 0.19f, 0.0f);
    glLineWidth(7);
    glBegin(GL_LINES);
    glVertex2f(0.74, 0.0);
    glVertex2f(0.74, 0.11);
    glEnd();

    glColor3f(0.0, 0.43, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.80, 0.10);
    glVertex2f(0.74, 0.5);
    glVertex2f(0.68, 0.10);
    glEnd();
}

void tree5() {
    glColor3f(0.38f, 0.19f, 0.0f);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0.56, 0.0);
    glVertex2f(0.56, 0.11);
    glEnd();

    glColor3f(0.0, 0.43, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.62, 0.10);
    glVertex2f(0.56, 0.5);
    glVertex2f(0.50, 0.10);
    glEnd();


}

void tree6() {
    glColor3f(0.38f, 0.19f, 0.0f);
    glLineWidth(7);
    glBegin(GL_LINES);
    glVertex2f(-0.46, -0.30);
    glVertex2f(-0.46, -0.20);
    glEnd();


    glColor3f(0.0, 0.43, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52, -0.22);
    glVertex2f(-0.46, -0.0);
    glVertex2f(-0.40, -0.22);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.52, -0.17);
    glVertex2f(-0.46, -0.0);
    glVertex2f(-0.40, -0.17);
    glEnd();


}


void house1() {
    glColor3f(0.38f, 0.19f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, -0.04);
    glVertex2f(-0.91, 0.10);
    glVertex2f(-0.63, 0.10);
    glVertex2f(-0.59, -0.04);
    glEnd();

    glColor3f(0.0f, 0.31f, 0.31f);
    glBegin(GL_QUADS);
    glVertex2f(-0.89, -0.08);
    glVertex2f(-0.89, -0.20);
    glVertex2f(-0.82, -0.20);
    glVertex2f(-0.82, -0.08);
    glEnd();

    glColor3f(0.0f, 0.31f, 0.31f);
    glBegin(GL_QUADS);
    glVertex2f(-0.81, -0.09);
    glVertex2f(-0.81, -0.32);
    glVertex2f(-0.73, -0.32);
    glVertex2f(-0.73, -0.09);
    glEnd();

    glColor3f(0.0f, 0.31f, 0.31f);
    glBegin(GL_QUADS);
    glVertex2f(-0.72, -0.08);
    glVertex2f(-0.72, -0.20);
    glVertex2f(-0.65, -0.20);
    glVertex2f(-0.65, -0.08);
    glEnd();

    glColor3f(1.0, 0.14, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.91, -0.32);
    glVertex2f(-0.91, -0.04);
    glVertex2f(-0.63, -0.04);
    glVertex2f(-0.63, -0.32);
    glEnd();


}

void house2() {
    glColor3f(0.38f, 0.19f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.12);
    glVertex2f(0.19, 0.26);
    glVertex2f(0.47, 0.26);
    glVertex2f(0.51, 0.12);
    glEnd();

    //  Window 1
    glColor3f(0.0f, 0.31f, 0.31f);
    glBegin(GL_QUADS);
    glVertex2f(0.20, -0.01);
    glVertex2f(0.20, 0.10);
    glVertex2f(0.27, 0.10);
    glVertex2f(0.27, -0.01);
    glEnd();

    // Window 2
    glColor3f(0.0f, 0.31f, 0.31f);
    glBegin(GL_QUADS);
    glVertex2f(0.39, -0.01);
    glVertex2f(0.39, 0.10);
    glVertex2f(0.46, 0.10);
    glVertex2f(0.46, -0.01);
    glEnd();

    // Door 
    glBegin(GL_POLYGON);
    glVertex2f(0.29, -0.20);
    glVertex2f(0.29, 0.10);
    glVertex2f(0.37, 0.10);
    glVertex2f(0.37, -0.20);
    glEnd();

    glColor3f(0.0, 0.65, 0.42);
    glBegin(GL_POLYGON);
    glVertex2f(0.19, -0.20);
    glVertex2f(0.19, 0.12);
    glVertex2f(0.47, 0.12);
    glVertex2f(0.47, -0.20);
    glEnd();



}


void house3() {
    // Roof 
    glColor3f(0.38f, 0.19f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.70, 0.10);
    glVertex2f(-0.66, 0.24);
    glVertex2f(-0.38, 0.24);
    glVertex2f(-0.34, 0.10);
    glEnd();

    // Window 1
    glColor3f(0.0f, 0.31f, 0.31f);
    glBegin(GL_QUADS);
    glVertex2f(-0.64, 0.08);
    glVertex2f(-0.64, -0.04);
    glVertex2f(-0.58, -0.04);
    glVertex2f(-0.58, 0.08);
    glEnd();


    // Door
    glColor3f(0.0f, 0.31f, 0.31f);
    glBegin(GL_QUADS);
    glVertex2f(-0.57, 0.07);
    glVertex2f(-0.57, -0.18);
    glVertex2f(-0.48, -0.18);
    glVertex2f(-0.48, 0.07);
    glEnd();


    // Window 2
    glColor3f(0.0f, 0.31f, 0.31f);
    glBegin(GL_QUADS);
    glVertex2f(-0.47, 0.08);
    glVertex2f(-0.47, -0.04);
    glVertex2f(-0.40, -0.04);
    glVertex2f(-0.40, 0.08);
    glEnd();

    glColor3f(0.7, 0.14, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.38, -0.18);
    glVertex2f(-0.38, 0.10);
    glVertex2f(-0.66, 0.10);
    glVertex2f(-0.66, -0.18);
    glEnd();

}

void boat() {
    glColor3f(0.000, 0.000, 0.502);
    glBegin(GL_QUADS);
    glVertex2f(-0.78, -0.89);
    glVertex2f(-0.84, -0.76);
    glVertex2f(-0.40, -0.76);
    glVertex2f(-0.46, -0.89);
    glEnd();

    glColor3f(0.698, 0.133, 0.1333);
    glBegin(GL_POLYGON);
    glVertex2f(-0.62, -0.75);
    glVertex2f(-0.88, -0.75);
    glVertex2f(-0.62, -0.56);
    glEnd();

    glColor3f(0.184, 0.310, 0.310);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(-0.54, -0.74);
    glVertex2f(-0.54, -0.56);
    glEnd();

    glColor3f(0.184, 0.310, 0.310);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(-0.58, -0.76);
    glVertex2f(-0.58, -0.56);
    glEnd();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    tree1();
    tree2();
    tree3();
    tree4();
    tree5();
    tree6();
    house1();
    house2();
    house3();
    hill();
    field();


    // Moving Boat 
    glPushMatrix();
    glTranslatef(boat_move, 0.0, 0.0);
    boat();
    glPopMatrix();
    boat_move += 0.005;
    {
        if (boat_move > 1.9) {
            boat_move = -1.0;
        }
    }

    river();
    //  Moving Clouds
    glPushMatrix();
    glTranslatef(cloud_move, 0.0, 0.0);
    cloud1();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_move1, 0.0, 0.0);
    cloud2();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_move2, 0.0, 0.0);
    cloud3();
    glPopMatrix();

    cloud_move += 0.003;
    {
        if (cloud_move > 1.9) {
            cloud_move = -1.0;
        }
    }

    cloud_move1 += 0.003;
    {
        if (cloud_move > 1.0) {
            cloud_move = -1.7;
        }
    }

    cloud_move2 += 0.003;
    {
        if (cloud_move > 1.5) {
            cloud_move = -1.2;
        }
    }

    // Sun Move 

    glPushMatrix();
    glTranslatef(0.0, sun_move, 0.0);
    sun();
    glPopMatrix();
    if (start3 == true)
    {
        moon();
    }

    if (start1 == true)
    {
        sun_move -= 0.5;
        if (sun_move < -0.67) {
            glDisable(GL_LIGHT0);
            start1 = false;
            start3 = true;
        }
    }

    if (start2 == true)
    {
        start3 = false;
        glEnable(GL_LIGHT0);
        sun_move += 0.005;
        if (sun_move > 0.30)
        {
            glEnable(GL_LIGHT0);
        }
        if (sun_move > 0)
        {
            start2 = false;
        }
    }

    sky();

    glutSwapBuffers();
}

void update(int value) {
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 700);
    glutCreateWindow("Day & Night");
    myInit();

    glutDisplayFunc(display);
    glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboard);

    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;

}
