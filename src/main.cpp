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
    // FIXME: Figure out why std::filesystem::absolute isn't working
    const std::string texturePath = "/home/tomatten/c++/flappy_flint/res/imgs/grass.png";
    SDL_Texture* grassTexture = game->getWindow()->loadTexture(texturePath.c_str());

    const size_t texWidth = 128;
    const size_t texHeight = 128;
    std::vector<Entity> entities({
        Entity(Vector2(0, 0), grassTexture, texWidth, texHeight),
        Entity(Vector2(128, 128), grassTexture, texWidth, texHeight),
        Entity(Vector2(0, 128), grassTexture, texWidth, texHeight),
    });

    // FIXME: Limit framerate 
    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->clearWindow();
        for (auto& obj : entities)
        {
            game->render(obj);
        }
        game->display();
    }

    game->cleanUp();
    return 0;
}