#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"




class Board : public Entity{
    public:
        Board(Vector2f pos, SDL_Texture* p_texture, int frameWidth, int frameHeight);

};