#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <windows.h>

float tx = 10, bx = 10, rx = 10;
float shift = 0;
float birdShift = 0;

// -------------------- Circle Function --------------------
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);

        glVertex2f(x + cx, y + cy);
    }

    glEnd();
}

// -------------------- Initialization --------------------
void init(void)
{
    glClearColor(0.5, 0.8, 1.0, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 500, 0, 500);
}

// -------------------- Green Bushes --------------------
void Bushes()
{
    // Left bushes
    glColor3ub(0, 128, 0);

    circle(20, 30, 20, 180);
    circle(20, 30, 40, 210);
    circle(20, 30, 60, 180);

    // Right bushes
    glColor3ub(154, 205, 50);

    circle(20, 30, 430, 180);
    circle(20, 30, 450, 210);
    circle(20, 30, 470, 180);

    glColor3ub(0, 128, 0);

    circle(20, 30, 490, 180);
    circle(20, 30, 510, 210);
}

// -------------------- Road --------------------
void road()
{
    // Green roadside
    glColor3ub(0, 128, 0);

    glBegin(GL_POLYGON);

    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 75);
    glVertex2d(0, 75);

    glEnd();

    // White road border
    glColor3ub(255, 255, 255);

    glBegin(GL_POLYGON);

    glVertex2d(0, 50);
    glVertex2d(500, 50);
    glVertex2d(500, 55);
    glVertex2d(0, 55);

    glEnd();

    // Main road
    glColor3ub(105, 105, 105);

    glBegin(GL_POLYGON);

    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 50);
    glVertex2d(0, 50);

    glEnd();

    // Road markings
    glColor3ub(255, 255, 255);

    for (int x = 15; x < 500; x += 50)
    {
        glBegin(GL_POLYGON);

        glVertex2d(x, 20);
        glVertex2d(x + 35, 20);
        glVertex2d(x + 35, 30);
        glVertex2d(x, 30);

        glEnd();
    }
}

// -------------------- Sun --------------------
void sun()
{
    glColor3ub(255, 255, 0);

    circle(20, 30, 450, 450);

    // Sun rays
    glColor3ub(255, 200, 0);

    glBegin(GL_LINES);

    glVertex2d(450, 485);
    glVertex2d(450, 495);

    glVertex2d(450, 415);
    glVertex2d(450, 405);

    glVertex2d(415, 450);
    glVertex2d(405, 450);

    glVertex2d(485, 450);
    glVertex2d(495, 450);

    glEnd();
}

// -------------------- Big Tree --------------------
void tree()
{
    // Back tree trunk
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);

    glVertex2d(75, 180);
    glVertex2d(85, 180);
    glVertex2d(85, 350);
    glVertex2d(75, 350);

    glEnd();

    // Back leaves
    glColor3ub(0, 128, 0);

    circle(30, 40, 85, 370);
    circle(20, 30, 90, 340);
    circle(20, 30, 65, 395);

    // Front leaves
    glColor3ub(0, 100, 0);

    circle(40, 50, 45, 360);
    circle(30, 30, 60, 330);
    circle(20, 30, 30, 300);
    circle(20, 30, 60, 300);

    // Front trunk
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);

    glVertex2d(40, 180);
    glVertex2d(50, 180);
    glVertex2d(50, 296);
    glVertex2d(60, 320);
    glVertex2d(55, 326);
    glVertex2d(50, 300);
    glVertex2d(50, 350);
    glVertex2d(45, 350);
    glVertex2d(45, 310);

    glEnd();
}

// -------------------- Small Trees --------------------
void little_tree()
{
    // Tree 1
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);

    glVertex2d(0, 60);
    glVertex2d(10, 60);
    glVertex2d(10, 100);
    glVertex2d(0, 100);

    glEnd();

    glColor3ub(0, 100, 0);

    circle(15, 20, 0, 110);
    circle(15, 20, 10, 110);
    circle(15, 20, 5, 130);

    // Tree 2
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);

    glVertex2d(125, 60);
    glVertex2d(135, 60);
    glVertex2d(135, 100);
    glVertex2d(125, 100);

    glEnd();

    glColor3ub(0, 100, 0);

    circle(15, 20, 125, 110);
    circle(15, 20, 135, 110);
    circle(15, 20, 130, 130);

    // Tree 3
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);

    glVertex2d(300, 60);
    glVertex2d(310, 60);
    glVertex2d(310, 100);
    glVertex2d(300, 100);

    glEnd();

    glColor3ub(0, 100, 0);

    circle(15, 20, 300, 110);
    circle(15, 20, 310, 110);
    circle(15, 20, 305, 130);

    // Tree 4
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);

    glVertex2d(425, 60);
    glVertex2d(435, 60);
    glVertex2d(435, 100);
    glVertex2d(425, 100);

    glEnd();

    glColor3ub(0, 100, 0);

    circle(15, 20, 425, 110);
    circle(15, 20, 435, 110);
    circle(15, 20, 430, 130);
}

// -------------------- More Trees --------------------
void moreTrees()
{
    // Tree 5
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);

    glVertex2d(210, 60);
    glVertex2d(220, 60);
    glVertex2d(220, 100);
    glVertex2d(210, 100);

    glEnd();

    glColor3ub(0, 100, 0);

    circle(15, 20, 210, 110);
    circle(15, 20, 220, 110);
    circle(15, 20, 215, 130);

    // Tree 6
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);

    glVertex2d(350, 60);
    glVertex2d(360, 60);
    glVertex2d(360, 100);
    glVertex2d(350, 100);

    glEnd();

    glColor3ub(0, 100, 0);

    circle(15, 20, 350, 110);
    circle(15, 20, 360, 110);
    circle(15, 20, 355, 130);

    // Tree 7
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);

    glVertex2d(455, 60);
    glVertex2d(465, 60);
    glVertex2d(465, 100);
    glVertex2d(455, 100);

    glEnd();

    glColor3ub(0, 100, 0);

    circle(15, 20, 455, 110);
    circle(15, 20, 465, 110);
    circle(15, 20, 460, 130);
}

// -------------------- House --------------------
void house()
{
    // House body
    glColor3ub(255, 200, 120);

    glBegin(GL_POLYGON);

    glVertex2d(300, 180);
    glVertex2d(400, 180);
    glVertex2d(400, 260);
    glVertex2d(300, 260);

    glEnd();

    // Roof
    glColor3ub(150, 50, 30);

    glBegin(GL_TRIANGLES);

    glVertex2d(285, 260);
    glVertex2d(415, 260);
    glVertex2d(350, 325);

    glEnd();

    // Door
    glColor3ub(100, 50, 20);

    glBegin(GL_POLYGON);

    glVertex2d(340, 180);
    glVertex2d(365, 180);
    glVertex2d(365, 230);
    glVertex2d(340, 230);

    glEnd();

    // Windows
    glColor3ub(100, 180, 220);

    glBegin(GL_POLYGON);

    glVertex2d(310, 215);
    glVertex2d(330, 215);
    glVertex2d(330, 240);
    glVertex2d(310, 240);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2d(375, 215);
    glVertex2d(395, 215);
    glVertex2d(395, 240);
    glVertex2d(375, 240);

    glEnd();

    // Door knob
    glColor3ub(255, 215, 0);

    circle(2, 2, 360, 205);
}

// -------------------- Clouds --------------------
void clouds()
{
    glPushMatrix();

    glTranslatef(shift, 0, 0);

    glColor3ub(255, 255, 255);

    // Cloud 1
    circle(20, 30, 90, 460);
    circle(15, 20, 110, 460);
    circle(15, 20, 70, 460);

    // Cloud 2
    circle(20, 30, 185, 430);
    circle(15, 20, 205, 430);
    circle(15, 20, 165, 430);

    glPopMatrix();

    shift += 0.1;

    if (shift > 500)
        shift = -220;
}

// -------------------- Moving Birds --------------------
void birds()
{
    glPushMatrix();

    // Move birds horizontally
    glTranslatef(birdShift, 0, 0);

    // Wing flapping
    float wing = sin(birdShift * 0.15) * 8;

    glColor3ub(0, 0, 0);

    glBegin(GL_LINES);

    // Bird 1
    glVertex2d(260, 405);
    glVertex2d(250, 400 + wing);

    glVertex2d(260, 405);
    glVertex2d(270, 400 + wing);

    // Bird 2
    glVertex2d(310, 375);
    glVertex2d(300, 370 + wing);

    glVertex2d(310, 375);
    glVertex2d(320, 370 + wing);

    // Bird 3
    glVertex2d(380, 410);
    glVertex2d(370, 405 + wing);

    glVertex2d(380, 410);
    glVertex2d(390, 405 + wing);

    glEnd();

    glPopMatrix();

    // Bird movement
    birdShift += 0.3;

    if (birdShift > 500)
        birdShift = -400;
}

// -------------------- Car --------------------
void car()
{
    glPushMatrix();

    glTranslatef(tx, 0, 0);

    // Main body
    glColor3ub(255, 0, 0);

    glBegin(GL_POLYGON);

    glVertex2d(410, 40);
    glVertex2d(490, 40);
    glVertex2d(485, 70);
    glVertex2d(410, 70);

    glEnd();

    // Upper body
    glColor3ub(220, 0, 0);

    glBegin(GL_POLYGON);

    glVertex2d(420, 70);
    glVertex2d(475, 70);
    glVertex2d(465, 100);
    glVertex2d(430, 100);

    glEnd();

    // Windows
    glColor3ub(180, 230, 240);

    glBegin(GL_POLYGON);

    glVertex2d(425, 70);
    glVertex2d(445, 70);
    glVertex2d(445, 90);
    glVertex2d(430, 90);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2d(450, 70);
    glVertex2d(470, 70);
    glVertex2d(465, 90);
    glVertex2d(450, 90);

    glEnd();

    // Headlight
    glColor3ub(255, 255, 0);

    circle(4, 5, 482, 55);

    // Wheels
    glColor3ub(0, 0, 0);

    circle(10, 14, 435, 40);
    circle(10, 14, 465, 40);

    glColor3ub(245, 245, 245);

    circle(5, 8, 435, 40);
    circle(5, 8, 465, 40);

    glPopMatrix();

    // Car movement
    tx += 0.9;

    if (tx > 500)
        tx = -500;
}

// -------------------- Truck --------------------
void truck()
{
    glPushMatrix();

    glTranslatef(bx, 0, 0);

    // Main truck
    glColor3ub(127, 255, 212);

    glBegin(GL_POLYGON);

    glVertex2d(450, 40);
    glVertex2d(505, 40);
    glVertex2d(505, 110);
    glVertex2d(450, 110);

    glEnd();

    // Cabin
    glColor3ub(220, 20, 60);

    glBegin(GL_POLYGON);

    glVertex2d(505, 40);
    glVertex2d(535, 40);
    glVertex2d(535, 70);
    glVertex2d(505, 70);

    glEnd();

    // Cabin top
    glBegin(GL_POLYGON);

    glVertex2d(505, 70);
    glVertex2d(525, 70);
    glVertex2d(515, 90);
    glVertex2d(505, 90);

    glEnd();

    // Window
    glColor3ub(180, 230, 240);

    glBegin(GL_POLYGON);

    glVertex2d(505, 70);
    glVertex2d(520, 70);
    glVertex2d(515, 85);
    glVertex2d(505, 85);

    glEnd();

    // Wheels
    glColor3ub(0, 0, 0);

    circle(10, 14, 460, 40);
    circle(10, 14, 510, 40);

    glColor3ub(245, 245, 245);

    circle(5, 8, 460, 40);
    circle(5, 8, 510, 40);

    glPopMatrix();

    // Truck movement
    bx += 0.7;

    if (bx > 500)
        bx = -510;
}

// -------------------- Flowers --------------------
void flower()
{
    // Right flower
    glColor3ub(255, 0, 0);

    circle(3, 5, 450, 210);
    circle(3, 5, 455, 205);
    circle(3, 5, 455, 215);
    circle(3, 5, 460, 210);

    glColor3ub(255, 215, 0);

    circle(3, 5, 455, 210);

    // Left flower
    glColor3ub(255, 0, 0);

    circle(3, 5, 30, 205);
    circle(3, 5, 30, 195);
    circle(3, 5, 25, 200);
    circle(3, 5, 35, 200);

    glColor3ub(255, 215, 0);

    circle(3, 5, 30, 200);

    // Middle flower
    glColor3ub(255, 0, 0);

    circle(3, 5, 250, 210);
    circle(3, 5, 250, 200);
    circle(3, 5, 245, 205);
    circle(3, 5, 255, 205);

    glColor3ub(255, 215, 0);

    circle(3, 5, 250, 205);
}

// -------------------- Road Light --------------------
void roadLight()
{
    // Pole
    glColor3ub(0, 0, 0);

    glBegin(GL_POLYGON);

    glVertex2d(80, 50);
    glVertex2d(85, 50);
    glVertex2d(85, 180);
    glVertex2d(80, 180);

    glEnd();

    // Top
    glBegin(GL_POLYGON);

    glVertex2d(65, 150);
    glVertex2d(100, 150);
    glVertex2d(100, 155);
    glVertex2d(65, 155);

    glEnd();

    // Light
    glColor3ub(255, 255, 255);

    circle(10, 15, 83, 180);
}

// -------------------- Display --------------------
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky
    glColor3ub(30, 144, 255);

    glBegin(GL_POLYGON);

    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 500);
    glVertex2d(0, 500);

    glEnd();

    // Bushes
    Bushes();

    // Ground
    glColor3ub(0, 255, 0);

    glBegin(GL_POLYGON);

    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 180);
    glVertex2d(0, 180);

    glEnd();

    // Trees
    little_tree();
    moreTrees();
    tree();

    // House
    house();

    // Road
    road();

    // Sun
    sun();

    // Clouds
    clouds();

    // Birds
    birds();

    // Road light
    roadLight();

    // Vehicles
    truck();
    car();

    // Flowers
    flower();

    glutSwapBuffers();

    glutPostRedisplay();
}

// -------------------- Keyboard --------------------
void key(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        shift -= 2;
        break;

    case GLUT_KEY_RIGHT:
        shift += 2;
        break;

    default:
        break;
    }

    glutPostRedisplay();
}

// -------------------- Main --------------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Moving Cars Project");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(key);

    glutMainLoop();

    return 0;
}