#pragma once

#include "render_window.hpp"
#include "board.hpp"
#include "debug.hpp"

class RenderManager
{
public:
    RenderManager(RenderWindow &window, Board &board,Debug &debug);
    void render();

private:
    RenderWindow &window;
    Board &board;
    Debug &debug;
};
