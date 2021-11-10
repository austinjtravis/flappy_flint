#pragma once  // include guard
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Entity.hpp>

class RenderWindow
{
public:
    RenderWindow(const char* title, const size_t width, const size_t height);

    // FIXME: Why not just use destructor?
    void cleanUp();

    SDL_Texture* loadTexture(const char* filePath);

    void clear();
    
    void render(Entity& entity);
    
    void display();

private:
    SDL_Window* window;  // Window to draw on
    SDL_Renderer* renderer;  // Renderer to use on Window (uses opengl)
};