#include "pieces/promote.hpp"

namespace pieces
{

    bool promote(Vector2f posPiece,std::vector<std::vector<Piece *>> board){
        if (board[posPiece.x][posPiece.y]->getLetter() == PieceLetter::PAWN)
            if ((board[posPiece.x][posPiece.y]->getColor() == PieceColor::WHITE && posPiece.y == 0) || (board[posPiece.x][posPiece.y]->getColor() == PieceColor::BLACK && posPiece.y == 7)){
                return true;
        }
        return false;
    }

}