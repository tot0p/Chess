#pragma once

#include "render_window.hpp"
// #include "board.hpp"
#include "debug.hpp"
#include "scene.hpp"
#include <list>

class RenderManager
{
public:
    RenderManager(RenderWindow &window, std::list<Scene*> &scenes,Debug &debug);
    void render(int scene);

private:
    RenderWindow &window;
    // Board &board;
    Debug &debug;
    std::list<Scene*>& scenes;
};
