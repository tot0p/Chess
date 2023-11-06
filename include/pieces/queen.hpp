#pragma once


#include "piece.hpp"
#include "utils.hpp"

namespace pieces
{
    class Queen : public Piece {
        public:
            Queen(PieceColor color, SDL_Texture *tileset) : Piece(4, color, tileset){};
            char getLetter() const  { return PieceLetter::QUEEN; }
    };

}