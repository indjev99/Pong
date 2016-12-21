#include "../headers/run.h"
#include "../headers/draw.h"
#include "../headers/window_functions.h"
#include "../headers/dimensions.h"
#include "../headers/ball.h"

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<conio.h>
#include<chrono>

using namespace std;
using namespace chrono;

const int SEED=3;

vector<Ball> balls;
double p1H=0;
double p2H=0;

int points1=0;
int points2=0;
bool updateScore=0;

void run(GLFWwindow* game)
{
    srand(SEED);
    balls.push_back(Ball(0,0,initialBallSpeed));
    balls.push_back(Ball(0,0,initialBallSpeed));
    balls.push_back(Ball(0,0,initialBallSpeed));

    high_resolution_clock::time_point start_time,curr_time,benchmark_start_time;
    int benchmark_counter=0;
    start_time=high_resolution_clock::now();
    benchmark_start_time=start_time;
    while (!glfwWindowShouldClose(game))
    {
        ++benchmark_counter;
        if (benchmark_counter==1000)
        {
            curr_time=high_resolution_clock::now();
            cerr<<"Time for last 1000 steps: "<<duration_cast<duration<double>>(curr_time-benchmark_start_time).count()<<'\n';
            benchmark_start_time=curr_time;
            benchmark_counter=0;
        }
        drawWindow(game,balls,p1H,p2H);
        do
        {
            glfwPollEvents();
            curr_time=high_resolution_clock::now();
        }
        while(!glfwWindowShouldClose(game) && duration_cast<duration<double>>(curr_time-start_time).count()<deltaT);

        if (paused) continue;

        p1H+=paddleSpeed*deltaT*p1M;
        p2H+=paddleSpeed*deltaT*p2M;
        if (p1H+length>1.0) p1H=1.0-length;
        if (p1H-length<-1.0) p1H=-1.0+length;
        if (p2H+length>1.0) p2H=1.0-length;
        if (p2H-length<-1.0) p2H=-1.0+length;
        for (int i=0;i<balls.size();++i)
        {
            int curr=balls[i].update(p1H,p2H);
            if (curr==1)
            {
                ++points1;
                updateScore=1;
            }
            else if (curr==2)
            {
                ++points2;
                updateScore=1;
            }
        }
        if (updateScore)
        {
            cout<<"Player 1 score: "<<points1<<"\nPLayer 2 score: "<<points2<<"\n"<<endl;
            updateScore=0;
        }
        start_time=high_resolution_clock::now();
    }
}
