#include "render_manager.hpp"
#include "font.hpp"

using namespace std;

RenderManager::RenderManager(RenderWindow &window,Board &board,Debug &debug) : window(window) , board(board) , debug(debug) {
}

void RenderManager::render()
{
    window.clear();
    board.render(window);
    debug.render(window);
    window.display();
}
