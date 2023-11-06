#pragma once

#include <SDL2/SDL.h>
#include <utility>

class EventManager
{
public:
    EventManager() = default; // Constructeur avec liste d'initialisation vide
    ~EventManager() = default; // Destructeur avec liste d'initialisation vide
    void processEvents();


    bool isRightClick() const { return rightClick; }
    bool isLeftClick() const { return leftClick; }
    std::pair<int, int> getMousePosition() const ;
    bool isGameRunning() const { return gameRunning; }

private:
    SDL_Event event; // Structure qui contient le type d'évènement et ses données associées
    bool gameRunning{true};
    bool rightClick{false} , leftClick{false};
    
};
