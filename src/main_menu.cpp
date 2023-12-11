#include "main_menu.hpp"
#include "constants.hpp"
#include "font.hpp"

#include <iostream>

MainMenu::MainMenu(RenderWindow &window)
    : play(Entity(Vector2f(0,0),window.loadTexture(PLAY_FILE),PLAY_WIDTH,PLAY_HEIGHT)), quit(Entity(Vector2f(0,0),window.loadTexture(QUIT_FILE),QUIT_WIDTH,QUIT_HEIGHT))
{
    Font font =  Font(FONT_FILE,28,{255,255,255,255});
    title = font.createTextEntity("Chess.exe",window,{0,0});

    title->setPosition({WINDOW_WIDTH/(2 * SCALE_FACTOR) - title->getWidth()/2,WINDOW_HEIGHT/(2 * SCALE_FACTOR) - title->getHeight()/2 -PLAY_HEIGHT - 20 });

    play.setPosition({WINDOW_WIDTH/(2 * SCALE_FACTOR) - PLAY_WIDTH/2 ,WINDOW_HEIGHT/(2 *SCALE_FACTOR) - PLAY_HEIGHT/2});
    quit.setPosition({WINDOW_WIDTH/(2 * SCALE_FACTOR) - QUIT_WIDTH/2,WINDOW_HEIGHT/(2 * SCALE_FACTOR) - QUIT_HEIGHT/2 + QUIT_HEIGHT + 10});
    
}

void MainMenu::update(EventManager &eventManager)  {

    if (eventManager.isLeftClick()) {
        pair<int,int> mousePos = eventManager.getMousePosition();
        mousePos.first /= SCALE_FACTOR;
        mousePos.second /= SCALE_FACTOR;
        if (mousePos.first >= play.getPosition().x && mousePos.first <= play.getPosition().x  + play.getWidth() && mousePos.second >= play.getPosition().y && mousePos.second <= play.getPosition().y + play.getHeight() ) {
            eventManager.changeScene(4);
            eventManager.CancelLeftClick();
        }else if (mousePos.first >= quit.getPosition().x && mousePos.first <= quit.getPosition().x + quit.getWidth() && mousePos.second >= quit.getPosition().y && mousePos.second <= quit.getPosition().y + quit.getHeight()) {
            eventManager.quit();
        }
    }
}


void MainMenu::render(RenderWindow &window) 
{
    window.render(title);
    window.render(play);
    window.render(quit);
}