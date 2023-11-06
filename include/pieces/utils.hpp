#pragma once


namespace pieces
{
    struct BoardLetter
    {
        char cases[8][8];
    };
    
    enum MoveType {
        NORMAL,
        ATTACK,
        CASTLING,
        PASSANT,
        PROMOTION
    };

    struct Move
    {
        int x;
        int y;
        MoveType type;
        Move(int x, int y, MoveType type) : x(x), y(y), type(type){};
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