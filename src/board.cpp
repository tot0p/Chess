#include "board.hpp"
#include "constants.hpp"

Board::Board(Vector2f pos, SDL_Texture* p_texture, int frameWidth, int frameHeight) 
        : Entity(pos, p_texture, frameWidth, frameHeight)
{        
    // for(int i = 0; i < 8; i++)
    // {
    //     for(int j = 0; j < 8; j++) 
    //     {
    //         cases[i][j] = Case(Vector2f(i * 64, j * 64), nullptr, PIECES_WIDTH, PIECES_HEIGHT);
    //     }
    // }
}