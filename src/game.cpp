#include "game.hpp"
#include "utils.hpp"
#include "constants.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "game_scene.hpp"
#include "main_menu.hpp"

#include "scene_creator.hpp"

// Constructeur
Game::Game()
    : currentTime(utils::hireTimeInSeconds()),           // Initialise currentTime avec le temps actuel
      timeStep(TIME_STEP),                               // Initialisation de timeStep
      window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT), // Initialisation de window
      eventManager(),                                    // Initialisation de eventManager              // Initialisation de board
      renderManager(window,scenes,debug),                    // Initialisation de renderManager
      updateManager(eventManager,scenes),               // Initialisation de updateManager
        debug(window),                              // Initialisation de debug
        scenes({SceneCreator::createScene(SceneId::MAIN_MENU,window,eventManager),SceneCreator::createScene(SceneId::GAME_SCENE,window,eventManager),SceneCreator::createScene(SceneId::WIN_WHITE,window,eventManager),SceneCreator::createScene(SceneId::WIN_BLACK,window,eventManager),SceneCreator::createScene(SceneId::PLAY_MENU,window,eventManager)}) // Initialisation de la liste des scènes
{
}




// Destructeur
Game::~Game()
{
    cleanUp();
}


void Game::run()
{
    int currentScene = 0;
    while (eventManager.isGameRunning())
    {
        // Calcul des frames de logique de jeu par rapport aux frames de rendu
        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;
        currentTime = newTime;
        accumulator += frameTime;


        eventManager.processEvents(); // Gestion des événements


        while (accumulator >= timeStep)
        {
            updateManager.update(currentScene); // Mise à jour de la logique de jeu
            accumulator -= timeStep;
            debug.updateTPS(1.0f / timeStep);
            debug.updateFPS(1.0f / frameTime);
            debug.update(eventManager);
            int tempsScene = eventManager.getScene();
            if (tempsScene != currentScene)
            {
                currentScene = tempsScene;
                // get scene 
                std::list<Scene*>::iterator it = scenes.begin();
                std::advance(it, currentScene);
                (*it)->reset(eventManager);            
            }
        }



        renderManager.render(currentScene); // Rendu   
    }
}

void Game::cleanUp()
{
    Mix_CloseAudio(); // Nettoyage des ressources de SDL_mixer
    TTF_Quit();       // Nettoyage des ressources de SDL_ttf
    window.cleanUp(); // Nettoyage des ressources de la fenêtre de rendu
    IMG_Quit();       // Nettoyage des ressources de SDL_image
    SDL_Quit();       // Nettoyage des ressources de SDL
}


