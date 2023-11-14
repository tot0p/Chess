#pragma once


#include <vector>
#include "piece.hpp"


namespace pieces
{
    bool isCheck( std::vector<std::vector<Piece *>> board,PieceColor color);
    bool isCheckMate(std::vector<std::vector<Piece *>> board,PieceColor color);
}