#include "pieces/bishop.hpp"
#include "pieces/utils.hpp"



namespace pieces
{
    std::list<Move> Bishop::getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board){
        std::list<Move> moves;
        int x = pos.x;
        int y = pos.y;
        int i = 1;
        while (x+i < 8 && y+i < 8) {
            if (board[x+i][y+i] == nullptr) {
                moves.push_back(Move(x+i,y+i,MoveType::NORMAL));
            } else if (board[x+i][y+i]->getColor() != color) {
                moves.push_back(Move(x+i,y+i,MoveType::ATTACK));
                break;
            } else {
                break;
            }
            i++;
        }
        i = 1;
        while (x-i >= 0 && y-i >= 0) {
            if (board[x-i][y-i] == nullptr) {
                moves.push_back(Move(x-i,y-i,MoveType::NORMAL));
            } else if (board[x-i][y-i]->getColor() != color) {
                moves.push_back(Move(x-i,y-i,MoveType::ATTACK));
                break;
            } else {
                break;
            }
            i++;
            
        }
        i = 1;
        while (x+i < 8 && y-i >= 0) {
            if (board[x+i][y-i] == nullptr) {
                moves.push_back(Move(x+i,y-i,MoveType::NORMAL));
            } else if (board[x+i][y-i]->getColor() != color) {
                moves.push_back(Move(x+i,y-i,MoveType::ATTACK));
                break;
            } else {
                break;
            }
            i++;
        }
        i = 1;
        while (x-i >= 0 && y+i < 8) {
            if (board[x-i][y+i] == nullptr) {
                moves.push_back(Move(x-i,y+i,MoveType::NORMAL));
            } else if (board[x-i][y+i]->getColor() != color) {
                moves.push_back(Move(x-i,y+i,MoveType::ATTACK));
                break;
            } else {
                break;
            }
            i++;
        }
        std::cout << "Bishop moves: " << moves.size() << std::endl;
        return moves;
    }
} 