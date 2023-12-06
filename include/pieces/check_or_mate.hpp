#pragma once


#include <vector>
#include "piece.hpp"
#include <list>
#include "../math.hpp"


namespace pieces
{
    bool isCheck( std::vector<std::vector<Piece *>> board,PieceColor color);
    bool isCheckMate(std::vector<std::vector<Piece *>> board,PieceColor color);

    std::list<Move> supprUnauthorizedMoves(Vector2f posPiece,std::list<Move> moves,std::vector<std::vector<Piece *>> board,PieceColor color);
    std::list<Move> addSpecialMoves(Vector2f posPiece,std::list<Move> moves,std::vector<std::vector<Piece *>> board,PieceColor color,Move lastMove);
}