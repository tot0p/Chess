#pragma once

#include <vector>

#include "pieces/piece.hpp"
#include "math.hpp"

using namespace std;

enum class ControllerType
{
    PLAYER,
    AI
};

class Controller {
public:
    Controller(bool isWhite,ControllerType type) : isWhite(isWhite), type(type) {}

    pair<int,int> virtual Interact(vector<vector<pieces::Piece*>> board) = 0;

    bool getIsWhite() const { return isWhite; }
    ControllerType getType() const { return type; }

    void setPosition(Vector2f position) { this->pos = position; }

    virtual void reset() = 0;


protected:
    pair<int,int> clickOn(pair<int,int> mousePos);


private:
    bool isWhite;
    ControllerType type;
    Vector2f pos;
};
    

