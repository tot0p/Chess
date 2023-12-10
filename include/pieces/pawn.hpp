#pragma once

#include "utils.hpp"
#include "piece.hpp"

namespace pieces
{
    class Pawn : public Piece {
        public:
            Pawn(PieceColor color, SDL_Texture *tileset) : Piece(0, color, tileset){};
            char getLetter() const  { return PieceLetter::PAWN; }
            std::list<Move> getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board);

            std::string getName() const { return "Pawn"; }
    };

} 