#pragma once

#include "entity.hpp"
#include "font.hpp"

#include "render_window.hpp"


class Debug {
    public:
        Debug(RenderWindow &window);
        void updateTPS(int TPS) { TPS_int = TPS;};
        void updateFPS(int FPS) { FPS_int = FPS;  };

        void render(RenderWindow &window);
    private:
        Font font;
        Entity *TPS;
        Entity *FPS;
        int TPS_int;
        int FPS_int;
};