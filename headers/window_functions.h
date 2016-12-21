#ifndef WINDOW_FUNCTIONS_H_INCLUDED
#define WINDOW_FUNCTIONS_H_INCLUDED

#include<string>
#include<queue>
#include<vector>
#include<GLFW/glfw3.h>

extern std::queue<int> presses;
extern int pressed;
extern double mxpos,mypos;
extern bool paused;
extern int p1M;
extern int p2M;

void errorCallback(int error, const char* description);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void windowSizeCallback(GLFWwindow* window, int width, int height);
std::string setCallbacks(GLFWwindow* w);
std::string initializeGLFW();
std::string createWindow(GLFWwindow*& w);
void stopGraphics(std::vector<GLFWwindow*> w);

#endif // WINDOW_FUNCTIONS_H_INCLUDED
