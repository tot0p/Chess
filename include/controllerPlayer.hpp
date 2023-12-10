#pragma once

#include "controller.hpp"
#include "event_manager.hpp"



class ControllerPlayer : public Controller {
public:
    ControllerPlayer(bool isWhite,EventManager &eventManager) : eventManager(eventManager) , Controller(isWhite,ControllerType::PLAYER) {};
    pair<int,int> Interact(vector<vector<pieces::Piece*>> board);
    void reset() { Click = false; }

private:
    EventManager &eventManager;
    bool Click = false;
};
    