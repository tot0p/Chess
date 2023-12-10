#include "controllerPlayer.hpp"


pair<int,int> ControllerPlayer::Interact(vector<vector<pieces::Piece*>> board)
{
    bool OneClick = false;
    if (eventManager.isLeftClick())
    {
        Click = true;
    }else if (!eventManager.isLeftClick() && Click)
    {
        Click = false;
        OneClick = true;
    }

    if (OneClick)
    {
        return clickOn(eventManager.getMousePosition());
    }else
    {
        return make_pair(-1,-1);
    }
        

        
}