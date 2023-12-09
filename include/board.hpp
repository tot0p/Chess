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
        Board(Vector2f pos, SDL_Texture* p_texture, int frameWidth, int frameHeight,RenderWindow &window , SDL_Texture* p_tileset, SDL_Texture* SELECTED_FILE,SDL_Texture* MOVE_FILE,SDL_Texture* ATTACK_FILE);


        void update(EventManager &eventManager);
        void render(RenderWindow &window);
        void reset();

        vector<vector<pieces::Piece*>> getBoard();

    private:
        pair<int,int> clickON(pair<int,int> mousePos);
        list<pieces::Piece*> getAllPieces();

        pieces::BoardLetter getBoardLetter();
        pair<bool,bool> isCheckOrCheckMate();

        void DefaultBoard();
        void addHistory(pieces::Move move);

        Case cases[8][8] ;
        Case* selectedCase = nullptr;

        Entity selectedEntity;
        Entity move;
        Entity attack;
        list<pieces::Move> moves;
        pieces::Move lastMove;

        bool Click = false;
        bool TurnOfWhite = true;

        // history of moves
        list<string> history;

        // GUI 
        SDL_Texture* p_tileset;
        Entity* TurnOfWhiteText;
        Entity* TurnOfBlackText;
};