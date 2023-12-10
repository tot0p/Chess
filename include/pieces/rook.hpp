#pragma once

#include "piece.hpp"

#include "utils.hpp"

namespace pieces
{
    class Rook : public Piece {
        public:
            Rook(PieceColor color, SDL_Texture *tileset) : Piece(2, color, tileset){};
            char getLetter() const  { return PieceLetter::ROOK; }
            std::list<Move> getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board);


            std::string getName() const { return "Rook"; }
    };
}