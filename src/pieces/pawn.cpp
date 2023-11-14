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
        if (color == PieceColor::WHITE)
        {
            if (y == 6)
            {
                if (board[x][y - 1] == nullptr)
                {
                    moves.push_back(Move(x, y - 1, MoveType::NORMAL));
                    if (board[x][y - 2] == nullptr)
                    {
                        moves.push_back(Move(x, y - 2, MoveType::NORMAL));
                    }
                }
            }
            else
            {
                if (board[x][y - 1] == nullptr)
                {
                    moves.push_back(Move(x, y - 1, MoveType::NORMAL));
                }
            }
            if (x > 0 && board[x - 1][y - 1] != nullptr && board[x - 1][y - 1]->getColor() != color)
            {
                moves.push_back(Move(x - 1, y - 1, MoveType::ATTACK));
            }
            if (x < 7 && board[x + 1][y - 1] != nullptr && board[x + 1][y - 1]->getColor() != color)
            {
                moves.push_back(Move(x + 1, y - 1, MoveType::ATTACK));
            }
        }
        else
        {
            if (y == 1)
            {
                if (board[x][y + 1] == nullptr)
                {
                    moves.push_back(Move(x, y + 1, MoveType::NORMAL));
                    if (board[x][y + 2] == nullptr)
                    {
                        moves.push_back(Move(x, y + 2, MoveType::NORMAL));
                    }
                }
            }
            else
            {
                if (board[x][y + 1] == nullptr)
                {
                    moves.push_back(Move(x, y + 1, MoveType::NORMAL));
                }
            }
            if (x > 0 && board[x - 1][y + 1] != nullptr && board[x - 1][y + 1]->getColor() != color)
            {
                moves.push_back(Move(x - 1, y + 1,MoveType::ATTACK));
            }
            if (x < 7 && board[x + 1][y + 1] != nullptr && board[x + 1][y + 1]->getColor() != color)
            {
                moves.push_back(Move(x + 1, y + 1,MoveType::ATTACK));
            }
        }
        return moves;
    }
}

