#pragma once 

#include <SDL2/SDL_mixer.h>


Mix_Music* loadMusic(const char *filePath);
Mix_Chunk *loadSound(const char *filePath);