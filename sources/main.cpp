#include "../headers/run.h"
#include "../headers/window_functions.h"
#include<iostream>
#include<stdlib.h>

GLFWwindow *game;
int main()
{
    system("cls");

    std::string message;
    message=initializeGLFW();
    std::cout<<message<<std::endl;
    if (message!="GLFW initialized successfully.") return -1;

    message=createWindow(game);
    std::cout<<message<<std::endl;
    if (message!="Game window created successfully.") return -1;

    message=setCallbacks(game);
    std::cout<<message<<std::endl;
    if (message!="Callbacks for game window set successfully.") return -1;

    system("cls");
    run(game);

    stopGraphics({game});
    return 0;
}
