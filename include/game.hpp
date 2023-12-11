#pragma once

#include <SDL2/SDL_mixer.h>

#include "event_manager.hpp"
#include "update_manager.hpp"
#include "render_manager.hpp"
#include "render_window.hpp"
#include "board.hpp"
#include "debug.hpp"
#include "scene.hpp"

#include <list>

class Game
{
public:
    Game();
    ~Game(); // Ajout du destructeur
    void run();

    


private:
    void cleanUp(); // Ajout de la méthode cleanUp


    float currentTime, accumulator{0.0f}, timeStep; // Membres pour le calcul des frames de logique de jeu
    RenderWindow window; // Ajout de la fenêtre de rendu
    EventManager eventManager; // Ajout du gestionnaire d'événements
    UpdateManager updateManager; // Ajout du gestionnaire de mise à jour de la logique de jeu
    RenderManager renderManager; // Ajout du gestionnaire de rendu
    Debug debug; // Ajout du gestionnaire de debug
    std::list<Scene*> scenes; // Ajout de la liste des scènes
};
