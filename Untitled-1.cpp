#include "main.h"

int POS_X, POS_Y;

std::string model_name = "planetas/earth.obj";

float pos_x = 0, pos_y = 0, pos_z = 0;
float fovy = 45.f;
GLfloat light_pos[] = {0, 0, 0, 1};
float angle_x = 0, earth_rotate = 0, angle_2 = 0;
int x_old, y_old;
// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 1.f, lz = -1.f;
// XZ position of the camera
float camera_x = 4.f, camera_z = 20.f;
bool esta_segurando_o_mouse = false;
Model model;

void init()
{
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    model.load(model_name.c_str());
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -20);

    // desenha um ponto no centro para servir de apoio
    glRotatef(angle_x, 0, 1, 0);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();

    //ativa as luzes e configura os parametros da luz 0
    glEnable(GL_LIGHTING);
    GLfloat light_position[] = {0.0, 0.0, 0.0, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    //desenha o que deveria ser mercurio
    glPushMatrix();
    glRotatef(earth_rotate, 0, 1, 0);
    glTranslatef(0, 0, -10.0);
    model.draw();
    glPopMatrix();

    // troca os buffers
    glutSwapBuffers();
}

void resize(int w, int h)
{
    // define the visible area of the window ( in pixels )
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    // Setup viewing volume
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 1000.0);
}

void timer(int value)
{
    earth_rotate += 6;
    angle_2 += 15;
    angle_x += 9;
    if (angle_x > 360)
    {
        angle_x = 0;
    }
    if (angle_2 > 360)
    {
        angle_2 = 0;
    }
    if (earth_rotate > 360)
    {
        earth_rotate = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            x_old = x;
            y_old = y;
            esta_segurando_o_mouse = true;
        }
        else
            esta_segurando_o_mouse = false;
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
    if (esta_segurando_o_mouse)
    {
        pos_x += (x + 0.f - x_old) / (glutGet(GLUT_SCREEN_WIDTH) / 5);
        pos_y += (y_old + 0.f - y) / (glutGet(GLUT_SCREEN_HEIGHT) / 5);
        x_old = x;
        y_old = y;
        glutPostRedisplay();
    }
}

void processSpecialKeys(int key, int x, int y)
{
    float fraction = 0.2f;
    switch (key)
    {
    case GLUT_KEY_LEFT:
        angle -= 0.01f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_RIGHT:
        angle += 0.01f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_UP:
        camera_x += lx * fraction;
        camera_z += lz * fraction;
        break;
    case GLUT_KEY_DOWN:
        camera_x -= lx * fraction;
        camera_z -= lz * fraction;
        break;
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
    glutReshapeFunc(resize);
    glutMouseFunc(mouse);
    // glutMotionFunc(motion);
    // glutSpecialFunc(processSpecialKeys);
    glutTimerFunc(100, timer, 0);
    glutMainLoop();
    return 0;
}
