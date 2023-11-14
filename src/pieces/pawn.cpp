#include "pieces/pawn.hpp"
#include "pieces/utils.hpp"


#include <list>
#include <vector>
#include "math.hpp"

#include <iostream>

namespace pieces
{
    std::list<Move> Pawn::getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board){
        std::list<Move> moves;
        int x = pos.x;
        int y = pos.y;
        int dy = color == PieceColor::WHITE ? -1 : 1;
        if (y+dy >= 0 && y+dy < 8) {
            if (board[x][y+dy] == nullptr) {
                moves.push_back(Move(x,y+dy,MoveType::NORMAL));
                if (y == (color == PieceColor::WHITE ? 6 : 1) && board[x][y+2*dy] == nullptr) {
                    moves.push_back(Move(x,y+2*dy,MoveType::NORMAL));
                }
            }
            if (x > 0 && board[x-1][y+dy] != nullptr && board[x-1][y+dy]->getColor() != color) {
                moves.push_back(Move(x-1,y+dy,MoveType::ATTACK));
            }
            if (x < 7 && board[x+1][y+dy] != nullptr && board[x+1][y+dy]->getColor() != color) {
                moves.push_back(Move(x+1,y+dy,MoveType::ATTACK));
            }
        }
        return moves;
    }
}

