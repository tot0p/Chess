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
            // if key is not already pressed
            if (std::find(keysPressed.begin(), keysPressed.end(), event.key.keysym.scancode) == keysPressed.end())
                keysPressed.push_back(event.key.keysym.scancode);
            break;
        case SDL_KEYUP:
            //if key is in the list
            if (std::find(keysPressed.begin(), keysPressed.end(), event.key.keysym.scancode) != keysPressed.end())
                keysPressed.remove(event.key.keysym.scancode);
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

bool EventManager::isKeyPressed(SDL_Keycode key) {
    return std::find(keysPressed.begin(), keysPressed.end(), key) != keysPressed.end();
}