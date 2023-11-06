#include "board.hpp"
#include "constants.hpp"
#include "pieces/pawn.hpp"
#include "pieces/knight.hpp"
#include "pieces/bishop.hpp"
#include "pieces/rook.hpp"
#include "pieces/queen.hpp"
#include "pieces/king.hpp"

Board::Board(Vector2f pos, SDL_Texture* p_texture, int frameWidth, int frameHeight ,SDL_Texture* p_tileset ) 
        : Entity(pos, p_texture, frameWidth, frameHeight)
{        
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++) 
        {
            cases[i][j].x = i;
            cases[i][j].y = j;
            if (j == 0 || j == 1 || j == 6 || j == 7)
            {
                if (j == 0 || j == 7)
                {
                    if (i == 0 || i == 7)
                    {
                        cases[i][j].piece = new pieces::Rook( j == 0 ? pieces::PieceColor::BLACK : pieces::PieceColor::WHITE, p_tileset);
                    }
                    else if (i == 1 || i == 6)
                    {
                        cases[i][j].piece = new pieces::Knight( j == 0 ? pieces::PieceColor::BLACK : pieces::PieceColor::WHITE, p_tileset);
                    }
                    else if (i == 2 || i == 5)
                    {
                        cases[i][j].piece = new pieces::Bishop( j == 0 ? pieces::PieceColor::BLACK : pieces::PieceColor::WHITE, p_tileset);
                    }
                    else if (i == 4)
                    {
                        cases[i][j].piece = new pieces::King( j == 0 ? pieces::PieceColor::BLACK : pieces::PieceColor::WHITE, p_tileset);
                    }
                    else if (i == 3)
                    {
                        cases[i][j].piece = new pieces::Queen( j == 0 ? pieces::PieceColor::BLACK : pieces::PieceColor::WHITE, p_tileset);
                    }
                }
                else
                {
                    cases[i][j].piece = new pieces::Pawn( j == 1 ? pieces::PieceColor::BLACK : pieces::PieceColor::WHITE, p_tileset);
                }
            }
            else
            cases[i][j].piece = nullptr;
        }
    }
}

list<pieces::Piece*> Board::getAllPieces() {
    list<pieces::Piece*> pieces;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++) 
        {
            if(cases[i][j].piece != nullptr){
                pieces::Piece *tmp = cases[i][j].piece;
                Vector2f pos = getPosition();
                tmp->setPosition(Vector2f(i*PIECES_WIDTH + pos.x + BOARD_MARGIN, j*PIECES_HEIGHT + pos.y + BOARD_MARGIN));
                pieces.push_back(tmp);
            }
        }
    }
    return pieces;
}