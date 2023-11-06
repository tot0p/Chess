#pragma once

#include "../entity.hpp"
#include <SDL2/SDL.h>


namespace pieces{
    enum PieceColor
    {
        WHITE,
        BLACK
    };




    class Piece : public Entity
    {
        public:

            Piece(int piece, PieceColor color, SDL_Texture *tileset);


        protected:
            PieceColor color;

    };
}