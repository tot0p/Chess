#include "game.hpp"
#include "utils.hpp"
#include "constants.hpp"


// Constructeur
Game::Game()
    : currentTime(utils::hireTimeInSeconds()),           // Initialise currentTime avec le temps actuel
      timeStep(TIME_STEP),                               // Initialisation de timeStep
      window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT), // Initialisation de window
      eventManager(),                                    // Initialisation de eventManager
      board(Vector2f(0,0),window.loadTexture(BOARD_FILE),BOARD_WIDTH,BOARD_HEIGHT),              // Initialisation de board
      renderManager(window,board),                    // Initialisation de renderManager
      updateManager(eventManager,board)                   // Initialisation de updateManager
{
}




// Destructeur
Game::~Game()
{
    cleanUp();
}


void Game::run()
{
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
            updateManager.update(); // Mise à jour de la logique de jeu
            accumulator -= timeStep;
        }


        renderManager.render(); // Rendu
    }
}

void Game::cleanUp()
{
    Mix_CloseAudio(); // Nettoyage des ressources de SDL_mixer
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