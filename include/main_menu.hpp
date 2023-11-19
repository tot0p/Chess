#pragma once

#include "scene.hpp"

class MainMenu : public Scene
{
    public:
        MainMenu(RenderWindow &window);
        void update(EventManager &eventManager) override;
        void render(RenderWindow &window) override;
    private:
        Entity* title;
        Entity play;
        Entity quit;
};