#pragma once

#include "piece.hpp"

namespace pieces
{
    class Pawn : public Piece {
        public:
            Pawn(PieceColor color, SDL_Texture *tileset) : Piece(0, color, tileset){};
    };

} 