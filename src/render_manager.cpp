#include "render_manager.hpp"
#include "font.hpp"

using namespace std;

RenderManager::RenderManager(RenderWindow &window,Board &board) : window(window) , board(board) {
    Font font = Font("assets/fonts/Roboto-Black.ttf", 20, SDL_Color{255, 255, 255, 255});
    if (font.getFont() == nullptr)
    {
        cout << "Failed to load font" << TTF_GetError() << endl;
    }
    text = font.createTextEntity("Hello World", window, Vector2f{0, 0});
    if (text == nullptr)
    {
        cout << "Failed to create text entity" << endl;
    }
}

void RenderManager::render()
{
    window.clear();
    board.render(window);
    window.render(text);
    window.display();
}
