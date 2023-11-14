#pragma once


#include "piece.hpp"
#include "utils.hpp"

namespace pieces
{
    class King : public Piece {
        public:
            King(PieceColor color, SDL_Texture *tileset) : Piece(5, color, tileset){};
            char getLetter() const  { return PieceLetter::KING; }
            std::list<Move> getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board);
    };

}