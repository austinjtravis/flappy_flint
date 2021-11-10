#include <iostream>

#include <RenderWindow.hpp>

//FIXME: just use nullptr?
RenderWindow::RenderWindow(const char* title, const size_t width, const size_t height) :
    window(NULL), renderer(NULL)
{
    // FIXME: Video mentioned this is raw pointer and need to handle deletion
    //        to avoid memory leak.  Just use std::shared_ptr
    window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            SDL_WINDOW_SHOWN);
    
    if (window == NULL)
    {
        std::cout << "Window failed to initialize. Error: " 
                  << SDL_GetError() << std::endl; 
    }

    // Note: -1: Look for graphics driver instead of directly configuring
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        std::cout << "Renderer failed to initialize. Error: " 
                  << SDL_GetError() << std::endl; 
    }
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
    if (texture == NULL)
    {
        std::cout << "Failed to load texture. Error: "
                  << SDL_GetError() << std::endl;
    }
    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& entity)
{
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = entity.getPos().x;
    dst.y = entity.getPos().y;
    dst.w = entity.getCurrentFrame().w;
    dst.h = entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, entity.getTexture(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

