#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include <RenderWindow.hpp>
#include <Entity.hpp>

class Game
{

public:
    Game(const char* title, const size_t width, const size_t height);
    ~Game();

    void handleEvents();
    void update();
    bool running();
    void cleanUp();
    void clearWindow();
    void render(Entity& entity);
    void display();
    // Spaghetti way to load textures. Need to think on this more
    RenderWindow* getWindow(); 

private:
    bool isRunning;
    RenderWindow* window;
};