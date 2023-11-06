#include "pieces/piece.hpp"

#include "constants.hpp"

pieces::Piece::Piece(int piece, PieceColor color , SDL_Texture *tileset ) : Entity(Vector2f(0,0), tileset, PIECES_WIDTH, PIECES_HEIGHT), color(color)
{
    setSpriteSheetCoord(piece*PIECES_WIDTH, color*PIECES_HEIGHT);
}