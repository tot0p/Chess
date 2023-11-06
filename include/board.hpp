#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"
#include "pieces/piece.hpp"


#include <list>



struct Case{
    int x;
    int y;
    pieces::Piece* piece;
};



class Board : public Entity{
    public:
        Board(Vector2f pos, SDL_Texture* p_texture, int frameWidth, int frameHeight, SDL_Texture* p_tileset);

        list<pieces::Piece*> getAllPieces();

    private:
        Case cases[8][8] ;

};