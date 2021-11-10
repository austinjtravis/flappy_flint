#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <memory>

#include <Game.hpp>
#include <Entity.hpp>
#include <Vector2.hpp>

// int argv, char* args[] are required for SDL  
int main(int argv, char* args[])
{
    const std::string title = "Game";
    const size_t windowWidth = 1280;
    const size_t windowHeight = 720;
    std::unique_ptr<Game> game(new Game(title.c_str(), windowWidth, windowHeight));
    
    const int fps = 30;
    const int frameDelay = 1000/fps;
    Uint32 frameStart;
    int frameTime;

    // FIXME: Figure out why std::filesystem::absolute isn't working
    const std::string texturePath = "/home/tomatten/c++/flappy_flint/res/imgs/grass.png";
    SDL_Texture* grassTexture = game->getWindow()->loadTexture(texturePath.c_str());

    const size_t texWidth = 256;
    const size_t texHeight = 256;
    // std::vector<Entity> entities({
    //     Entity(Vector2(0, 0), grassTexture, texWidth, texHeight),
    //     Entity(Vector2(128, 128), grassTexture, texWidth, texHeight),
    //     Entity(Vector2(0, 128), grassTexture, texWidth, texHeight),
    // });

    Entity grass(Vector2(128, 128), grassTexture, texWidth, texHeight);

    // FIXME: Limit framerate 
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->clearWindow();
        const Uint8* state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_RIGHT])
        {
            float newX = grass.getPos().x + 2;
            grass.updatePosX(newX);
        }
        if (state[SDL_SCANCODE_LEFT])
        {
            float newX = grass.getPos().x - 2;
            grass.updatePosX(newX);
        }
        if (state[SDL_SCANCODE_UP])
        {
            float newY = grass.getPos().y + 2;
            grass.updatePosY(newY);
        }
        if (state[SDL_SCANCODE_DOWN])
        {
            float newY = grass.getPos().y - 2;
            grass.updatePosY(newY);
        }

        game->render(grass);

        /*
        for (auto& obj : entities)
        {
            game->render(obj);
        }
        */
        game->display();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->cleanUp();
    return 0;
}