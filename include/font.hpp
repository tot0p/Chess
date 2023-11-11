#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "render_window.hpp"
#include "entity.hpp"


class Font
{
    public:
        Font(const char* p_fontPath, int p_size, SDL_Color p_color);
        ~Font();

        TTF_Font* getFont() { return font; }
        SDL_Color getColor() { return color; }
        

        Entity* createTextEntity(const char* p_text, RenderWindow &window, Vector2f pos);

    private:
        TTF_Font* font{nullptr};
        SDL_Color color;
};