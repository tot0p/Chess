#pragma once

#include "../entity.hpp"
#include <SDL2/SDL.h>
#include "utils.hpp"
#include "math.hpp"

#include <vector>
#include <list>
#include <iostream>
#include <string>


namespace pieces{


    enum PieceColor
    {
        WHITE,
        BLACK
    };



    class Piece : public Entity
    {
        public:

            Piece(int piece, PieceColor color, SDL_Texture *tileset);
            virtual char getLetter() const { return PieceLetter::EMPTY; }
            PieceColor getColor() const { return color; }

            void UpdateMoved() { hasMoved = true;}
            bool getHasMoved() const { return hasMoved; }

            virtual std::list<Move> getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board) { std::cout << "not implement yet" << std::endl; return std::list<Move>();};




        protected:
            PieceColor color;
            bool hasMoved = false;


    };
}