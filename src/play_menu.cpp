#include "play_menu.hpp"
#include "constants.hpp"
#include "font.hpp"

PlayMenu::PlayMenu(RenderWindow &window) : 
    title(nullptr),
    pvp(
        Entity(
            Vector2f(WINDOW_WIDTH / (2 * SCALE_FACTOR) - PVP_WIDTH / 2, WINDOW_HEIGHT / (2 * SCALE_FACTOR) - PVP_HEIGHT / 2),
            window.loadTexture(PVP_FILE),
            PVP_WIDTH,
            PVP_HEIGHT
        )
    ),
    pve(
        Entity(
            Vector2f(WINDOW_WIDTH / (2 * SCALE_FACTOR) - PVE_WIDTH / 2, WINDOW_HEIGHT / (2 * SCALE_FACTOR) - PVE_HEIGHT / 2 + 24),
            window.loadTexture(PVE_FILE),
            PVE_WIDTH,
            PVE_HEIGHT
        )
    ),
    eve(
        Entity(
            Vector2f(WINDOW_WIDTH / (2 * SCALE_FACTOR) - EVE_WIDTH / 2, WINDOW_HEIGHT / (2 * SCALE_FACTOR) - EVE_HEIGHT / 2 + 48),
            window.loadTexture(EVE_FILE),
            EVE_WIDTH,
            EVE_HEIGHT
        )
    ),
    back(
        Entity(
            Vector2f(WINDOW_WIDTH / (2 * SCALE_FACTOR) - BACK_WIDTH / 2, WINDOW_HEIGHT / (2 * SCALE_FACTOR) - BACK_HEIGHT / 2 + 72),
            window.loadTexture(BACK_FILE),
            BACK_WIDTH,
            BACK_HEIGHT
        )
    )
{
    Font font =  Font(FONT_FILE,28,{255,255,255,255});
    title = font.createTextEntity("Chess.exe",window,{0,0});

    title->setPosition({WINDOW_WIDTH/(2 * SCALE_FACTOR) - title->getWidth()/2,WINDOW_HEIGHT/(2 * SCALE_FACTOR) - title->getHeight()/2 -PVP_HEIGHT - 20 });
}


void PlayMenu::update(EventManager &eventManager) 
{
    if (eventManager.isLeftClick()) {
        click = true;
    } else if (click and !eventManager.isLeftClick()) {
        pair<int,int> mousePos = eventManager.getMousePosition();
        mousePos.first /= SCALE_FACTOR;
        mousePos.second /= SCALE_FACTOR;
        if (mousePos.first >= pvp.getPosition().x && mousePos.first <= pvp.getPosition().x  + pvp.getWidth() && mousePos.second >= pvp.getPosition().y && mousePos.second <= pvp.getPosition().y + pvp.getHeight() ) {
            eventManager.setConfig(PartyConfig{PartyType::PVP,"Player","Player"});
            eventManager.CancelLeftClick();
            eventManager.changeScene(1);
        }else if (mousePos.first >= pve.getPosition().x && mousePos.first <= pve.getPosition().x + pve.getWidth() && mousePos.second >= pve.getPosition().y && mousePos.second <= pve.getPosition().y + pve.getHeight()) {
            eventManager.CancelLeftClick();
            eventManager.setConfig(PartyConfig{PartyType::PVE,"Player","Player"});
            eventManager.changeScene(1);            
        }else if (mousePos.first >= eve.getPosition().x && mousePos.first <= eve.getPosition().x + eve.getWidth() && mousePos.second >= eve.getPosition().y && mousePos.second <= eve.getPosition().y + eve.getHeight()) {
            eventManager.CancelLeftClick();
            eventManager.setConfig(PartyConfig{PartyType::EVE,"Player","Player"});
            eventManager.changeScene(1);
        }else if (mousePos.first >= back.getPosition().x && mousePos.first <= back.getPosition().x + back.getWidth() && mousePos.second >= back.getPosition().y && mousePos.second <= back.getPosition().y + back.getHeight()) {
            eventManager.CancelLeftClick();
            eventManager.changeScene(0);
        }
    }
}


void PlayMenu::render(RenderWindow &window) 
{
    window.render(title);
    window.render(pvp);
    window.render(pve);
    window.render(eve);
    window.render(back);
}