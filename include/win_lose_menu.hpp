#pragma once


#include "scene.hpp"
#include "entity.hpp"
#include "event_manager.hpp"


class WinLoseMenu : public Scene
{
    public:
        WinLoseMenu(RenderWindow &window, bool winWhite);
        void update(EventManager &eventManager) override;
        void render(RenderWindow &window) override;
    private:
        Entity* title;
        Entity playAgain;
        Entity quit;
};