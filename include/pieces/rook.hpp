#pragma once

#include "piece.hpp"


namespace pieces
{
    class Rook : public Piece {
        public:
            Rook(PieceColor color, SDL_Texture *tileset) : Piece(2, color, tileset){};
    };

}