#pragma once


namespace pieces
{
    struct BoardLetter
    {
        char cases[8][8];
    };
    
    enum MoveType {
        NONE,
        NORMAL,
        ATTACK,
        CASTLING,
        PASSANT
    };

    struct Move
    {
        int x;
        int y;
        MoveType type;
        Move(int x, int y, MoveType type) : x(x), y(y), type(type){};
        Move() : x(0), y(0), type(MoveType::NONE){};
    };
    


    enum PieceLetter
    {
        PAWN = 'P',
        KNIGHT = 'N',
        BISHOP = 'B',
        ROOK = 'R',
        QUEEN = 'Q',
        KING = 'K',
        EMPTY = ' '
    };

}