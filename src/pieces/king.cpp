#include "pieces/king.hpp"
#include "pieces/utils.hpp"


namespace pieces {
    std::list<Move> King::getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board){
        std::list<Move> moves;
        int x = pos.x;
        int y = pos.y;
        if (x >0) {
            if (y > 0) {
                if (board[x-1][y-1] == nullptr || board[x-1][y-1]->getColor() != color) {
                    moves.push_back(Move(x-1,y-1,board[x-1][y-1] == nullptr ? MoveType::NORMAL : MoveType::ATTACK));
                }
            }
            if (y < 7) {
                if (board[x-1][y+1] == nullptr || board[x-1][y+1]->getColor() != color) {
                    moves.push_back(Move(x-1,y+1,board[x-1][y+1] == nullptr ? MoveType::NORMAL : MoveType::ATTACK));
                }
            }
            if (board[x-1][y] == nullptr || board[x-1][y]->getColor() != color) {
                moves.push_back(Move(x-1,y,board[x-1][y] == nullptr ? MoveType::NORMAL : MoveType::ATTACK));
            }
        }
        if (x < 7){
            if (y > 0) {
                if (board[x+1][y-1] == nullptr || board[x+1][y-1]->getColor() != color) {
                    moves.push_back(Move(x+1,y-1,board[x+1][y-1] == nullptr ? MoveType::NORMAL : MoveType::ATTACK));
                }
            }
            if (y < 7) {
                if (board[x+1][y+1] == nullptr || board[x+1][y+1]->getColor() != color) {
                    moves.push_back(Move(x+1,y+1,board[x+1][y+1] == nullptr ? MoveType::NORMAL : MoveType::ATTACK));
                }
            }
            if (board[x+1][y] == nullptr || board[x+1][y]->getColor() != color) {
                moves.push_back(Move(x+1,y,board[x+1][y] == nullptr ? MoveType::NORMAL : MoveType::ATTACK));
            }
        }
        if (y > 0) {
            if (board[x][y-1] == nullptr || board[x][y-1]->getColor() != color) {
                moves.push_back(Move(x,y-1,board[x][y-1] == nullptr ? MoveType::NORMAL : MoveType::ATTACK));
            }
        }
        if (y < 7) {
            if (board[x][y+1] == nullptr || board[x][y+1]->getColor() != color) {
                moves.push_back(Move(x,y+1,board[x][y+1] == nullptr ? MoveType::NORMAL : MoveType::ATTACK));
            }
        }
        return moves;
    }
}