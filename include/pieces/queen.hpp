#pragma once


#include "piece.hpp"

namespace pieces
{
    class Queen : public Piece {
        public:
            Queen(PieceColor color, SDL_Texture *tileset) : Piece(4, color, tileset){};
    };

}