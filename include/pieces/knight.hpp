#pragma once


#include "piece.hpp"
#include "utils.hpp"

namespace pieces
{
    class Knight : public Piece {
        public:
            Knight(PieceColor color, SDL_Texture *tileset) : Piece(1, color, tileset){};
            char getLetter() const  { return PieceLetter::KNIGHT; }
    };

}