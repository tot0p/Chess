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
        scenes({SceneCreator::createScene(SceneId::MAIN_MENU,window),SceneCreator::createScene(SceneId::GAME_SCENE,window),SceneCreator::createScene(SceneId::WIN_WHITE,window),SceneCreator::createScene(SceneId::WIN_BLACK,window)}) // Initialisation de la liste des scènes
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
            currentScene = eventManager.getScene();
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


// Charge une musique
Mix_Music *Game::loadMusic(const char *filePath)
{
    Mix_Music *music = Mix_LoadMUS(filePath);
    if (!music)
    {
        std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    return music;
}


Mix_Chunk *Game::loadSound(const char *filePath)
{
    Mix_Chunk *soundEffect = Mix_LoadWAV(filePath);
    if (!soundEffect)
    {
        std::cerr << "Failed to load sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    return soundEffect;
}