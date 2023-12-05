#pragma once

#include "../entity.hpp"
#include <SDL2/SDL.h>
#include "utils.hpp"
#include "math.hpp"

#include <vector>
#include <list>
#include <iostream>


namespace pieces{


    enum PieceColor
    {
        WHITE,
        BLACK
    };


    enum HasMoved
    {
        FALSE,
        FIRST,
        TRUE
    };



    class Piece : public Entity
    {
        public:

            Piece(int piece, PieceColor color, SDL_Texture *tileset);
            virtual char getLetter() const { return PieceLetter::EMPTY; }
            PieceColor getColor() const { return color; }

            void UpdateMoved() { hasMoved = HasMoved::FALSE ? HasMoved::FIRST : HasMoved::TRUE; }

            virtual std::list<Move> getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board) { std::cout << "not implement yet" << std::endl; return std::list<Move>();};




        protected:
            PieceColor color;
            HasMoved hasMoved = HasMoved::FALSE;


    };
}