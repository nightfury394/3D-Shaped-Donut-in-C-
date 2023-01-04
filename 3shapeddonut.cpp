#include <GL/glut.h>
#include <cmath>

const int slices = 20;
const int stacks = 20;

void drawDonut()
{
    for (int i = 0; i <= slices; i++)
    {
        float theta1 = i * 2 * M_PI / slices;
        float theta2 = (i+1) * 2 * M_PI / slices;
        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= stacks; j++)
        {
            float phi = j * M_PI / stacks;
            float r1 = 0.5 + 0.1 * cos(phi);
            float r2 = 0.5 + 0.1 * cos(phi+M_PI/stacks);
            float x1 = r1 * cos(theta1);
            float y1 = r1 * sin(theta1);
            float x2 = r1 * cos(theta2);
            float y2 = r1 * sin(theta2);
            float x3 = r2 * cos(theta2);
            float y3 = r2 * sin(theta2);
            float x4 = r2 * cos(theta1);
            float y4 = r2 * sin(theta1);
            glVertex3f(x1, y1, 0.1 * sin(phi));
            glVertex3f(x2, y2, 0.1 * sin(phi));
            glVertex3f(x3, y3, 0.1 * sin(phi+M_PI/stacks));
            glVertex3f(x4, y4, 0.1 * sin(phi+M_PI/stacks));
        }
        glEnd();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("3D Donut");
    glutDisplayFunc(drawDonut);
    glutMainLoop();
    return 0;
}

