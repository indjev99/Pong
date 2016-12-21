#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "ball.h"
#include<vector>
#include<GLFW/glfw3.h>

void drawPartEllipse(float x, float y, float radiusX, float radiusY, double alpha, double beta);
void drawWindow(GLFWwindow* w, std::vector<Ball>& balls, double p1H, double p2H);

#endif // DRAW_H_INCLUDED
