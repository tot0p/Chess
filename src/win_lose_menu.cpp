#include "win_lose_menu.hpp"
#include "constants.hpp"
#include "font.hpp"

WinLoseMenu::WinLoseMenu(RenderWindow &window, bool winWhite) : 
    title(nullptr), 
    playAgain({WINDOW_WIDTH/(2 * SCALE_FACTOR) - PLAY_WIDTH/2 ,WINDOW_HEIGHT/(2 *SCALE_FACTOR) - PLAY_HEIGHT/2},window.loadTexture(PLAY_FILE),PLAY_WIDTH,PLAY_HEIGHT), 
    quit({WINDOW_WIDTH/(2 * SCALE_FACTOR) - QUIT_WIDTH/2,WINDOW_HEIGHT/(2 * SCALE_FACTOR) - QUIT_HEIGHT/2 + QUIT_HEIGHT + 10},window.loadTexture(QUIT_FILE),QUIT_WIDTH,QUIT_HEIGHT) 
{
    Font font =  Font(FONT_FILE,20,{255,255,255,255});
    if (winWhite)
        title = font.createTextEntity("White Wins!",window,{0,0});
    else
        title = font.createTextEntity("Black Wins!",window,{0,0});

    title->setPosition({WINDOW_WIDTH/(2 * SCALE_FACTOR) - title->getWidth()/2,WINDOW_HEIGHT/(2 * SCALE_FACTOR) - title->getHeight()/2 -PLAY_HEIGHT - 20 });
}

void WinLoseMenu::update(EventManager &EventManager)
{
    if (EventManager.isLeftClick()) {
        pair<int,int> mousePos = EventManager.getMousePosition();
        mousePos.first /= SCALE_FACTOR;
        mousePos.second /= SCALE_FACTOR;
        if (mousePos.first >= playAgain.getPosition().x && mousePos.first <= playAgain.getPosition().x  + playAgain.getWidth() && mousePos.second >= playAgain.getPosition().y && mousePos.second <= playAgain.getPosition().y + playAgain.getHeight() ) {
            EventManager.changeScene(1);
        }else if (mousePos.first >= quit.getPosition().x && mousePos.first <= quit.getPosition().x + quit.getWidth() && mousePos.second >= quit.getPosition().y && mousePos.second <= quit.getPosition().y + quit.getHeight()) {
            EventManager.quit();
        }
    }
};

void WinLoseMenu::render(RenderWindow &window)
{
    window.render(*title);
    window.render(playAgain);
    window.render(quit);
};
