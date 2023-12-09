#pragma once

#include <vector>

#include "pieces/piece.hpp"

using namespace std;

class Controller {
public:
    pair<int,int> virtual Interact(vector<vector<pieces::Piece*>> board) = 0;
};
    

