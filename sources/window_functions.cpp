#include "../headers/window_functions.h"
#include "../headers/window_size.h"
#include<iostream>
#include<queue>

std::queue<int> presses;
int pressed;
double mxpos=0,mypos=0;
bool paused=0;
int p1M=0;
int p2M=0;

void errorCallback(int error, const char* description)
{
    std::cout<<error<<": "<<description<<std::endl;
}
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //if (key==GLFW_KEY_ESCAPE && action==GLFW_PRESS) glfwSetWindowShouldClose(window,1);

    if (key==GLFW_KEY_W && action==GLFW_PRESS) p1M+=1;
    if (key==GLFW_KEY_W && action==GLFW_RELEASE) p1M-=1;
    if (key==GLFW_KEY_S && action==GLFW_PRESS) p1M-=1;
    if (key==GLFW_KEY_S && action==GLFW_RELEASE) p1M+=1;

    if (key==GLFW_KEY_UP && action==GLFW_PRESS) p2M+=1;
    if (key==GLFW_KEY_UP && action==GLFW_RELEASE) p2M-=1;
    if (key==GLFW_KEY_DOWN && action==GLFW_PRESS) p2M-=1;
    if (key==GLFW_KEY_DOWN && action==GLFW_RELEASE) p2M+=1;

    if (key==GLFW_KEY_P && action==GLFW_PRESS)
    {
        paused=!paused;
    }
}
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (action==GLFW_PRESS)
    {
        pressed=button;
        glfwGetCursorPos(window,&mxpos,&mypos);
        mxpos=mxpos*2-WINDOWS_WIDTH;
        mypos=-mypos*2+WINDOWS_HEIGHT;
        mxpos/=ORIGINAL_WINDOWS_HEIGHT;
        mypos/=ORIGINAL_WINDOWS_HEIGHT;
    }
}
void windowSizeCallback(GLFWwindow* window, int width, int height)
{
    WINDOWS_WIDTH=width;
    WINDOWS_HEIGHT=height;
    pressed=-2;
}
std::string setCallbacks(GLFWwindow* w)
{
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(w,keyCallback);
    glfwSetMouseButtonCallback(w,mouseButtonCallback);
    glfwSetWindowSizeCallback(w,windowSizeCallback);
    return "Callbacks for game window set successfully.";
}
std::string initializeGLFW()
{
    if (!glfwInit())
        return "Unable to initialize GLFW.";
    return "GLFW initialized successfully.";
}
std::string createWindow(GLFWwindow*& w)
{
    std::string name;
    name="Ping Pong";
    w=glfwCreateWindow(WINDOWS_WIDTH,WINDOWS_HEIGHT,name.c_str(),NULL,NULL);
    if (!w)
    {
        glfwTerminate();
        return "Unable to create game window.";
    }
    return "Game window created successfully.";
}
void stopGraphics(std::vector<GLFWwindow*> w)
{
    for (int i=0;i<w.size();++i)
    {
        glfwDestroyWindow(w[i]);
    }
    glfwTerminate();
}
