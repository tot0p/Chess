#include "render_manager.hpp"

using namespace std;

RenderManager::RenderManager(RenderWindow &window,Board &board) : window(window) , board(board) {}

void RenderManager::render()
{
    window.clear();
    window.render(board);
    for (auto &entity : board.getAllPieces())
    {
        window.render(entity);
    }
    window.display();
}
