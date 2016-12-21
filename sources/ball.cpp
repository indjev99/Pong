#include "../headers/ball.h"
#include "../headers/dimensions.h"

#include<stdlib.h>
#include<math.h>

const double DEG2RAD=3.14159/180.0;

Ball::Ball() {}
Ball::Ball(double nx, double ny, double ns)
{
    x=nx;
    y=ny;
    double phi=(rand()%46+45.0/2+rand()%4*90.0)*DEG2RAD;
    xs=ns*cos(phi);
    ys=ns*sin(phi);
}
Ball::Ball(double nx, double ny, double nxs, double nys)
{
    x=nx;
    y=ny;
    xs=nxs;
    ys=nys;
}
int Ball::update(double p1H, double p2H)
{
    int point=0;
    x+=xs*deltaT;
    y+=ys*deltaT;

    if (x>=1.0-radius-thickness && y>=p2H-length && y<=p2H+length)
    {
        xs=-xs;
        x=2*(1.0-radius-thickness)-x;
        xs+=xs*speedUpRate;
        ys+=ys*speedUpRate;
    }
    if (x<=-1.0+radius+thickness && y>=p1H-length && y<=p1H+length)
    {
        xs=-xs;
        x=-2*(1.0-radius-thickness)-x;
        xs+=xs*speedUpRate;
        ys+=ys*speedUpRate;
    }

    if (x>=1.0-radius)
    {
        xs=-xs;
        x=2*(1.0-radius)-x;
        point=1;
    }
    if (x<=-1.0+radius)
    {
        xs=-xs;
        x=-2*(1.0-radius)-x;
        point=2;
    }
    if (y>=1.0-radius)
    {
        ys=-ys;
        y=2*(1.0-radius)-y;
    }
    if (y<=-1.0+radius)
    {
        ys=-ys;
        y=-2*(1.0-radius)-y;
    }
    return point;
}
