#include "update_manager.hpp"
#include "event_manager.hpp"
#include "entity.hpp"


UpdateManager::UpdateManager(EventManager &eventManager, Board &board) : eventManager(eventManager) , board(board){}


void UpdateManager::update()
{
    board.update(eventManager);
}

