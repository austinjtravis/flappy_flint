#include <Game.hpp>

Game::Game(const char* title, const size_t width, const size_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init FAILED. SDL_ERROR: " 
                  << SDL_GetError() << std::endl;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "IMG_Init FAILED. SDL_ERROR: "
                  << SDL_GetError() << std::endl;
    }
    this->window = new RenderWindow(title, width, height);
    this->isRunning = true;
}

Game::~Game()
{

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            this->isRunning = false;
            break;
    
        default:
            break;
    }
}

void Game::update()
{

}

bool Game::running()
{
    return this->isRunning;
}

void Game::cleanUp()
{
    this->window->cleanUp();
    SDL_Quit();
}

void Game::clearWindow()
{
    this->window->clear();
}

void Game::render(Entity& entity)
{
    this->window->render(entity);
}

void Game::display()
{
    this->window->display();
}

RenderWindow* Game::getWindow()
{
    return this->window;
}

