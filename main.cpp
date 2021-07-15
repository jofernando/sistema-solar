#include "main.h"

int POS_X, POS_Y;

float pos_x = 0, pos_y = 0, pos_z = -100;
float mercury_rotate, mars_rotate, neptune_rotate, jupiter_rotate, uranus_rotate, venus_rotate, saturn_rotate, earth_rotate, moon_rotate;
float rotation_earth;
float speed = 0.8;
int x_old, y_old;
bool holding_mouse = false, update = true;
Model earth, moon, mercury, mars, neptune, jupiter, uranus, venus, saturn, sun;
int mercury_z = 40, venus_z = mercury_z + 3, earth_z = venus_z + 4, mars_z = earth_z + 4, jupiter_z = mars_z + 14, saturn_z = jupiter_z + 38, uranus_z = saturn_z + 30, neptune_z = uranus_z + 12;
// float camera_x = 0, camera_z = 5, lx, lz = -1, angle;
float fovy = 45;
float contador = 0;

void initLights()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    GLfloat light_position[] = {pos_x, pos_y, pos_z, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
}

void initTextures()
{
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_TEXTURE_2D);
}

void init()
{
    glClearColor(0, 0, 0, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 1.0, 2000.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    initTextures();
    glEnable(GL_DEPTH_TEST);
    earth.load("planetas/earth.obj");
    mercury.load("planetas/mercury.obj");
    moon.load("planetas/moon.obj");
    jupiter.load("planetas/jupiter.obj");
    neptune.load("planetas/neptune.obj");
    mars.load("planetas/mars.obj");
    uranus.load("planetas/uranus.obj");
    venus.load("planetas/venus.obj");
    saturn.load("planetas/saturn.obj");
    sun.load("planetas/sun.obj");
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    initLights();

    glPushMatrix();
    glDisable(GL_LIGHTING);
    glTranslatef(pos_x, pos_y, pos_z);
    sun.draw();
    glEnable(GL_LIGHTING);
    glPopMatrix();
    // mercury
    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(mercury_rotate, 0, 1, 0);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glPushMatrix();
    glTranslatef(0, 0, -mercury_z);
    mercury.draw();
    glPopMatrix();
    glPopMatrix();

    //venus
    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(venus_rotate, 0, 1, 0);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glPushMatrix();
    glTranslatef(0, 0, -venus_z);
    venus.draw();
    glPopMatrix();
    glPopMatrix();

    //earth
    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(earth_rotate, 0, 1, 0);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glPushMatrix();
    glTranslatef(0, 0, -earth_z);
    glRotatef(rotation_earth, 0, 1, 0);
    earth.draw();
    //moon
    glPushMatrix();
    glTranslatef(0, 0, -2);
    glRotatef(moon_rotate, 0, 1, 0);
    moon.draw();
    glRotatef(moon_rotate, 0, 1, 0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    //mars
    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(mars_rotate, 0, 1, 0);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glPushMatrix();
    glTranslatef(0, 0, -mars_z);
    mars.draw();
    glPopMatrix();
    glPopMatrix();

    //jupiter
    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(jupiter_rotate, 0, 1, 0);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glPushMatrix();
    glTranslatef(0, 0, -jupiter_z);
    jupiter.draw();
    glPopMatrix();
    glPopMatrix();

    //saturn
    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(saturn_rotate, 0, 1, 0);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glPushMatrix();
    glTranslatef(0, 0, -saturn_z);
    glRotatef(27, 1, 1, 0);
    saturn.draw();
    glPopMatrix();
    glPopMatrix();

    //uranus
    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(uranus_rotate, 0, 1, 0);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glPushMatrix();
    glTranslatef(0, 0, -uranus_z);
    uranus.draw();
    glPopMatrix();
    glPopMatrix();

    //neptune
    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(neptune_rotate, 0, 1, 0);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glPushMatrix();
    glTranslatef(0, 0, -neptune_z);
    neptune.draw();
    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void timer(int value)
{
    if (update)
    {
        mercury_rotate += 4.166666667 * speed;
        venus_rotate += 1.612903226 * speed;
        earth_rotate += 1.0 * speed;
        mars_rotate += .5319148936 * speed;
        jupiter_rotate += .084317032 * speed;
        saturn_rotate += .0339558574 * speed;
        uranus_rotate += .0119019281 * speed;
        neptune_rotate += .0060683294 * speed;
        rotation_earth += 1 * speed * 365;
        moon_rotate += 1 * speed * 24;
    }
    if (mercury_rotate > 360)
        mercury_rotate = 1;
    if (venus_rotate > 360)
        venus_rotate = 1;
    if (earth_rotate >= 360)
    {
        printf("rotations %f", contador);
        earth_rotate = 1;
    }
    if (rotation_earth >= 360)
    {
        rotation_earth = 1;
        contador++;
    }
    if (mars_rotate > 360)
        mars_rotate = 1;
    if (moon_rotate > 360)
        moon_rotate = 1;
    if (jupiter_rotate > 360)
        jupiter_rotate = 1;
    if (saturn_rotate > 360)
        saturn_rotate = 1;
    if (uranus_rotate > 360)
        uranus_rotate = 1;
    if (neptune_rotate > 360)
        neptune_rotate = 1;
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            x_old = x;
            y_old = y;
            holding_mouse = true;
        }
        else
            holding_mouse = false;
    }
    else if (state == GLUT_UP)
    {
        switch (button)
        {
        case 3: //scroll up
            // pos_x++;
            // pos_y++;
            pos_z++;
            break;
        case 4: //scrholl down
            // pos_x--;
            // pos_y--;
            pos_z--;
            break;
        }
    }
    glutPostRedisplay();
}

void motion(int x, int y)
{
    if (holding_mouse)
    {
        pos_x += (x + 0.f - x_old) / (glutGet(GLUT_SCREEN_WIDTH) / 5);
        pos_y += (y_old + 0.f - y) / (glutGet(GLUT_SCREEN_HEIGHT) / 5);
        printf("x:%f y%f\n", pos_x, pos_y);
        x_old = x;
        y_old = y;
        glutPostRedisplay();
    }
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;
    float ratio = width * 1.0 / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(fovy, ratio, 0.1f, 2000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    float fraction = 0.1f;
    switch (key)
    {
    case 'p':
    case 'P':
        update = !update;
        break;
        // case 'w':
        // case 'W':
        //     camera_x += lx * fraction;
        //     camera_z += lz * fraction;
        //     break;

        // case 's':
        // case 'S':
        //     camera_x -= lx * fraction;
        //     camera_z -= lz * fraction;
        //     break;
        // case 'a':
        // case 'A':
        //     angle -= 0.01f;
        //     lx = sin(angle);
        //     lz = -cos(angle);
        //     break;
        // case 'd':
        // case 'D':
        //     angle += 0.01f;
        //     lx = sin(angle);
        //     lz = -cos(angle);
        //     break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glEnable(GL_MULTISAMPLE);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
    glutSetOption(GLUT_MULTISAMPLE, 8);
    POS_X = (glutGet(GLUT_SCREEN_WIDTH) - WIDTH) >> 1;
    POS_Y = (glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) >> 1;
    glutInitWindowPosition(POS_X, POS_Y);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("sistema solar");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
    return 0;
}
