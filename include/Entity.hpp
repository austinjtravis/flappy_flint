#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Vector2.hpp>

class Entity
{
public:
    Entity(Vector2 pos,
           SDL_Texture* texture, 
           const size_t width, 
           const size_t height) :
        pos(pos), texture(texture)
    {
        currentFrame.x = 0;
        currentFrame.y = 0;
        currentFrame.w = width;
        currentFrame.h = height;
    }

    Vector2& getPos()
    {
        return pos;
    }

    void updatePosX(const float xNew)
    {
        this->pos.x = xNew;
    }
    void updatePosY(const float yNew)
    {
        this->pos.y = yNew;
    }

    SDL_Texture* getTexture()
    {
        return texture;
    }
    SDL_Rect getCurrentFrame()
    {
        return currentFrame;
    }

private:
    Vector2 pos;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};