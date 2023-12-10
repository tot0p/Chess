#include "controller.hpp"
#include "constants.hpp"


pair<int,int> Controller::clickOn(pair<int,int> mousePos)
{
    int x = mousePos.first - pos.x *SCALE_FACTOR - BOARD_MARGIN *SCALE_FACTOR;
    int y = mousePos.second - pos.y *SCALE_FACTOR - BOARD_MARGIN *SCALE_FACTOR;
    if (x < 0 || y < 0 || x > 8*PIECES_WIDTH*SCALE_FACTOR|| y > 8*PIECES_HEIGHT*SCALE_FACTOR)
    {
        return make_pair(-1,-1);
    }
    else
    {
        return make_pair(x/(PIECES_WIDTH*SCALE_FACTOR), y/(PIECES_HEIGHT*SCALE_FACTOR));
    }
}