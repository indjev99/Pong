#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

struct Ball
{
    double x,y;
    double xs,ys;

    Ball();
    Ball(double nx, double ny, double ns);
    Ball(double nx, double ny, double nxs, double nys);
    int update(double p1H, double p2H);
};

#endif // BALL_H_INCLUDED
