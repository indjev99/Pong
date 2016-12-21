#include "../headers/draw.h"
#include "../headers/window_size.h"
#include "../headers/window_functions.h"
#include "../headers/colours.h"
#include "../headers/dimensions.h"
#include<math.h>

const double DEG2RAD=3.14159/180.0;

void drawPartEllipse(float x, float y, float radiusX, float radiusY, double alpha, double beta)
{
    alpha=round(alpha*2);
    beta=round(beta*2);
    glBegin(GL_TRIANGLES);
    for(int i=alpha;i<beta;++i)
    {
        float rad=i*0.5*DEG2RAD;
        float rad2=(i+1)*0.5;
        while (rad2>=360) rad2-=360;
        rad2*=DEG2RAD;
        glVertex2f(cos(rad)*radiusX+x,sin(rad)*radiusY+y);
        glVertex2f(cos(rad2)*radiusX+x,sin(rad2)*radiusY+y);
        glVertex2f(x,y);
    }
    glEnd();
}
void drawWindow(GLFWwindow* w, std::vector<Ball>& balls, double p1H, double p2H)
{
    glfwSetWindowShouldClose(w,0);
    pressed=-1;

    float ratio;
    int width, height;

    glfwMakeContextCurrent(w);
    glfwGetFramebufferSize(w,&width,&height);
    ratio=width/(float)height;
    glViewport(0,0,width,height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio,ratio,-1.f,1.f,1.f,-1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(BACKGROUND_COLOUR_R,BACKGROUND_COLOUR_G,BACKGROUND_COLOUR_B);

    glBegin(GL_QUADS);

    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);

    glEnd();

    glColor3f(FOREGROUND_COLOUR_R,FOREGROUND_COLOUR_G,FOREGROUND_COLOUR_B);

    for (int i=0;i<balls.size();++i)
    {
        drawPartEllipse(balls[i].x,balls[i].y,thickness,thickness,0,360);
    }

    glBegin(GL_QUADS);

    glVertex2f(-1.0+thickness,p1H-length);
    glVertex2f(-1.0,p1H-length);
    glVertex2f(-1.0,p1H+length);
    glVertex2f(-1.0+thickness,p1H+length);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(1.0-thickness,p2H-length);
    glVertex2f(1.0,p2H-length);
    glVertex2f(1.0,p2H+length);
    glVertex2f(1.0-thickness,p2H+length);

    glEnd();

    glfwSwapBuffers(w);
}
