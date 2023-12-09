#pragma once

#include "controller.hpp"
#include "event_manager.hpp"



class ControllerPlayer : public Controller {
public:
    ControllerPlayer(EventManager &eventManager) : eventManager(eventManager) {};
    pair<int,int> Interact(vector<vector<pieces::Piece*>> board);
private:
    EventManager &eventManager;
    bool Click = false;
};
    