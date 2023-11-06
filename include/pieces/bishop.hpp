#pragma once

#include "piece.hpp"
#include "utils.hpp"


namespace pieces
{
    class Bishop : public Piece {
        public:
            Bishop(PieceColor color, SDL_Texture *tileset) : Piece(3, color, tileset){};
            char getLetter() const  { return PieceLetter::BISHOP; }
    };

}