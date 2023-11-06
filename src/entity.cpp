#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"

// Constructeur
Entity::Entity(Vector2f pos, SDL_Texture* p_tex, int frameWidth, int frameHeight) :
    position(pos), texture(p_tex), currentFrame{0, 0, frameWidth, frameHeight} {}

Entity::Entity()
{
    position.x = 0;
    position.y = 0;
    texture = nullptr;
    currentFrame = {0, 0, 0, 0};
}




// Déplace l'entité
void Entity::move(float dx, float dy)
{
    position.x += dx;
    position.y += dy;
}

// Clone l'entité
Entity Entity::clone()
{
    Entity clone;
    clone.position = position;
    clone.texture = texture;
    clone.currentFrame = currentFrame;
    return clone;
}