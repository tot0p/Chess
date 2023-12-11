#include "song.hpp"
#include <iostream>

// Charge une musique
Mix_Music *loadMusic(const char *filePath)
{
    Mix_Music *music = Mix_LoadMUS(filePath);
    if (!music)
    {
        std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    return music;
}


Mix_Chunk *loadSound(const char *filePath)
{
    // load sound effect by mp3
    Mix_Chunk *soundEffect = Mix_LoadWAV(filePath);
    if (!soundEffect)
    {
        std::cerr << "Failed to load sound effect! SDL_mixer Error: " << Mix_GetError() << " in " << filePath << std::endl;
    }
    return soundEffect;
}