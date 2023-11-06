#pragma once


#include "piece.hpp"

namespace pieces
{
    class Knight : public Piece {
        public:
            Knight(PieceColor color, SDL_Texture *tileset) : Piece(1, color, tileset){};
    };

}