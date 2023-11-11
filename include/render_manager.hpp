#pragma once

#include "render_window.hpp"
#include "board.hpp"


class RenderManager
{
public:
    RenderManager(RenderWindow &window, Board &board);
    void render();

private:
    RenderWindow &window;
    Board &board;
    Entity* text;
};
