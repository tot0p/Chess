#include <iostream>
#include "render_window.hpp"
#include "math.hpp"
#include "constants.hpp"

// Cette fonction est appelée lors de la création d'un objet RenderWindow
RenderWindow::RenderWindow(const char *title, int width, int height)
    : window(SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)),
      renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
// SDL_CreateRenderer sert à créer un renderer (un moteur de rendu)
// SDL_RENDERER_PRESENTVSYNC sert à synchroniser le rendu avec le rafraîchissement de l'écran
{
    if (window == nullptr)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }
    if (renderer == nullptr)
    {
        std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;
    }
}



SDL_Texture *RenderWindow::loadTexture(const char *file_path)
{
    SDL_Texture *texture = nullptr; // Utilisation de nullptr au lieu de NULL
    texture = IMG_LoadTexture(renderer, file_path);


    if (texture == nullptr) // Utilisation de nullptr au lieu de NULL
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;


    return texture;
}




// Cette fonction sert à nettoyer la mémoire
void RenderWindow::cleanUp()
{
    SDL_DestroyRenderer(renderer); // Nettoyage du renderer
    SDL_DestroyWindow(window);     // Nettoyage de la fenêtre
}


void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
    SDL_Rect dst;

    Vector2f pos = p_entity.getPosition();

    dst.x = pos.x *SCALE_FACTOR;
    dst.y = pos.y *SCALE_FACTOR;
    dst.w = p_entity.getCurrentFrame().w * SCALE_FACTOR;
    dst.h = p_entity.getCurrentFrame().h * SCALE_FACTOR;

    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst);
}

void RenderWindow::render(Entity *p_entity){
    SDL_Rect dst;

    Vector2f pos = p_entity->getPosition();

    dst.x = pos.x *SCALE_FACTOR;
    dst.y = pos.y *SCALE_FACTOR;
    dst.w = p_entity->getCurrentFrame().w * SCALE_FACTOR;
    dst.h = p_entity->getCurrentFrame().h * SCALE_FACTOR;

    SDL_Rect src;
    src.x = p_entity->getCurrentFrame().x;
    src.y = p_entity->getCurrentFrame().y;
    src.w = p_entity->getCurrentFrame().w;
    src.h = p_entity->getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_entity->getTexture(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}