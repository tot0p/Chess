#pragma once

#include "piece.hpp"


namespace pieces
{
    class Bishop : public Piece {
        public:
            Bishop(PieceColor color, SDL_Texture *tileset) : Piece(3, color, tileset){};
    };

}