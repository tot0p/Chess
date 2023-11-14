#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"
#include "pieces/piece.hpp"
#include "pieces/utils.hpp"

#include "event_manager.hpp"
#include "render_window.hpp"


#include <list>



struct Case{
    int x;
    int y;
    pieces::Piece* piece;
};



class Board : public Entity{
    public:
        Board(Vector2f pos, SDL_Texture* p_texture, int frameWidth, int frameHeight, SDL_Texture* p_tileset, SDL_Texture* SELECTED_FILE,SDL_Texture* MOVE_FILE);


        void update(EventManager &eventManager);
        void render(RenderWindow &window);

        vector<vector<pieces::Piece*>> getBoard();

    private:
        pair<int,int> clickON(pair<int,int> mousePos);
        list<pieces::Piece*> getAllPieces();

        pieces::BoardLetter getBoardLetter();

        Case cases[8][8] ;
        Case* selectedCase = nullptr;

        Entity selectedEntity;
        Entity move;
        list<pieces::Move> moves;

        bool Click = false;

        bool TurnOfWhite = true;

};