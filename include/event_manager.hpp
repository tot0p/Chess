#pragma once

#include <SDL2/SDL.h>
#include <utility>
#include <list>
#include <algorithm>
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

    void changeScene(int scene) { this->scene = scene; }
    int getScene() const { return scene; }

    bool isKeyPressed(SDL_Keycode key) const { return std::find(keysPressed.begin(), keysPressed.end(), key) != keysPressed.end(); }

    void quit() { gameRunning = false; }

private:
    SDL_Event event; // Structure qui contient le type d'évènement et ses données associées
    bool gameRunning{true};
    int scene{0};
    bool rightClick{false} , leftClick{false};

    std::list<SDL_Keycode> keysPressed;
    
};
