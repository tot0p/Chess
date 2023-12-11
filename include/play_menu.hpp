#pragma once 

#include "scene.hpp"

class PlayMenu : public Scene
{
    public:
        PlayMenu(RenderWindow &window);
        void update(EventManager &eventManager) override;
        void render(RenderWindow &window) override;
        void reset(EventManager &eventManager) override { click = false; }
    private:
        Entity* title;
        Entity pvp;
        Entity pve;
        Entity eve;
        Entity back;
        bool click = false;
};