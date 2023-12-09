#pragma once

#include "entity.hpp"
#include "font.hpp"

#include "render_window.hpp"
#include "event_manager.hpp"


class Debug {
    public:
        Debug(RenderWindow &window);
        void updateTPS(int TPS) { TPS_int = TPS;};
        void updateFPS(int FPS) { FPS_int = FPS;  };
        void update(EventManager &eventManager);

        void render(RenderWindow &window);
    private:
        Font font;
        Entity *TPS;
        Entity *FPS;
        int TPS_int;
        int FPS_int;
        bool show = false;
        bool f3Pressed = false;
};