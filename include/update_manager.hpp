#pragma once


#include "entity.hpp"
#include "event_manager.hpp"
#include "board.hpp"

class UpdateManager
{
public:
    UpdateManager(EventManager &eventManager, Board &board);
    void update(); 


private:
    EventManager &eventManager;
    Board &board;
};