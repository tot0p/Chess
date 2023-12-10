#pragma once


#include "piece.hpp"
#include "utils.hpp"

namespace pieces
{
    class Knight : public Piece {
        public:
            Knight(PieceColor color, SDL_Texture *tileset) : Piece(1, color, tileset){};
            char getLetter() const  { return PieceLetter::KNIGHT; }
            std::list<Move> getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board);

            std::string getName() const { return "Knight"; }
    };

}