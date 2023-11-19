#pragma once


#include "entity.hpp"
#include "event_manager.hpp"
// #include "board.hpp"
#include "scene.hpp"
#include <list>

class UpdateManager
{
public:
    UpdateManager(EventManager &eventManager, std::list<Scene*>& scenes);
    void update(int scene); 


private:
    EventManager &eventManager;
    std::list<Scene*>& scenes;
    // Board &board;
};