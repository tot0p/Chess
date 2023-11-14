#include "pieces/queen.hpp"


namespace pieces {
    std::list<Move> Queen::getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board){
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
        i = 1;
        while (x+i < 8) {
            if (board[x+i][y] == nullptr) {
                moves.push_back(Move(x+i,y,MoveType::NORMAL));
            } else if (board[x+i][y]->getColor() != color) {
                moves.push_back(Move(x+i,y,MoveType::ATTACK));
                break;
            } else {
                break;
            }
            i++;
        }
        i = 1;
        while (x-i >= 0) {
            if (board[x-i][y] == nullptr) {
                moves.push_back(Move(x-i,y,MoveType::NORMAL));
            } else if (board[x-i][y]->getColor() != color) {
                moves.push_back(Move(x-i,y,MoveType::ATTACK));
                break;
            } else {
                break;
            }
            i++;
        }
        i = 1;
        while (y+i < 8) {
            if (board[x][y+i] == nullptr) {
                moves.push_back(Move(x,y+i,MoveType::NORMAL));
            } else if (board[x][y+i]->getColor() != color) {
                moves.push_back(Move(x,y+i,MoveType::ATTACK));
                break;
            } else {
                break;
            }
            i++;
        }
        i = 1;
        while (y-i >= 0) {
            if (board[x][y-i] == nullptr) {
                moves.push_back(Move(x,y-i,MoveType::NORMAL));
            } else if (board[x][y-i]->getColor() != color) {
                moves.push_back(Move(x,y-i,MoveType::ATTACK));
                break;
            } else {
                break;
            }
            i++;
        }
        std::cout << "Queen moves: " << moves.size() << std::endl;
        return moves;
    }
}