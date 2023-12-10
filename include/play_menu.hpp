#pragma once 

#include "scene.hpp"

class PlayMenu : public Scene
{
    public:
        PlayMenu(RenderWindow &window);
        void update(EventManager &eventManager) override;
        void render(RenderWindow &window) override;
    private:
        Entity* title;
        Entity pvp;
        Entity pve;
        Entity eve;
        Entity back;
};