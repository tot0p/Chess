#include "font.hpp"
#include <iostream>

Font::Font(const char* p_fontPath, int p_size, SDL_Color p_color)
{
    font = TTF_OpenFont(p_fontPath, p_size);
    if (font == nullptr)
    {
        std::cout << "Failed to load font" << TTF_GetError() << std::endl;
    }
    color = p_color;
}

Font::~Font()
{
    TTF_CloseFont(font);
}

Entity* Font::createTextEntity(const char* p_text, RenderWindow &window, Vector2f pos)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, p_text, color);
    if (surface == nullptr)
    {
        std::cout << "Failed to create surface" << TTF_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(window.getRenderer(), surface);
    if (texture == nullptr)
    {
        std::cout << "Failed to create texture" << TTF_GetError() << std::endl;
        return nullptr;
    }
    SDL_FreeSurface(surface);
    Entity* entity = new Entity(pos, texture, surface->w, surface->h);
    return entity;
}