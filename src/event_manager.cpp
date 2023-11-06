#include "event_manager.hpp"


std::pair<int, int> EventManager::getMousePosition() const {
    std::pair<int, int> mousePosition;
    SDL_GetMouseState(&mousePosition.first, &mousePosition.second);
    return mousePosition;
}

void EventManager::processEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            gameRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                leftClick = true;
                break;
            case SDL_BUTTON_RIGHT:
                rightClick = true;
                break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                leftClick = false;
                break;
            case SDL_BUTTON_RIGHT:
                rightClick = false;
                break;
            }
            break;
        }
    }
}