#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <utility>

#include "math.hpp"

class Entity {
    public:
        Entity(Vector2f pos, SDL_Texture* p_texture, int frameWidth, int frameHeight);
        Entity();
        Entity clone();

        Vector2f getPosition() { return position; }
        void setPosition(Vector2f pos) { position = pos; }
        SDL_Texture* getTexture() { return texture; }
        SDL_Rect getCurrentFrame() { return currentFrame; }
        void setTexture(SDL_Texture* p_texture) { texture = p_texture; }
        void setSpriteSheetCoord(int x, int y) { currentFrame.x = x; currentFrame.y = y; }

        void move(float dx, float dy);

    private:
        Vector2f position;
        SDL_Texture* texture;
        SDL_Rect currentFrame;
};