#pragma once


#include "piece.hpp"

namespace pieces
{
    class King : public Piece {
        public:
            King(PieceColor color, SDL_Texture *tileset) : Piece(5, color, tileset){};
    };

}