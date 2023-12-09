#include "debug.hpp"

#include "constants.hpp"


Debug::Debug(RenderWindow &window) : font(FONT_FILE,16,{255,255,255,255}) , TPS_int(0) , FPS_int(0)
{
    TPS = font.createTextEntity("TPS: 0",window,{0,0});
    FPS = font.createTextEntity("FPS: 0",window,{0,16});
}


void Debug::render(RenderWindow &window)
{
    if (!show){
        return;
    }
    TPS = font.createTextEntity(("TPS: " + to_string(TPS_int)).c_str(),window,{0,0});
    FPS = font.createTextEntity(("FPS: " + to_string(FPS_int)).c_str(),window,{0,16});
    window.render(TPS);
    window.render(FPS);
}

void Debug::update(EventManager &eventManager)
{
    if (eventManager.isKeyPressed(SDL_SCANCODE_F3)){
        f3Pressed = true;
    }else if (f3Pressed && !eventManager.isKeyPressed(SDL_SCANCODE_F3)){
        show = !show;
        f3Pressed = false;
    }
}