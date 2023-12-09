#pragma once

#include "../math.hpp"
#include "piece.hpp"
#include <list>

namespace pieces
{

    bool promote(Vector2f posPiece,std::vector<std::vector<Piece *>> board);

} 
