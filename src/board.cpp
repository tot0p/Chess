#include "board.hpp"
#include "constants.hpp"
#include "pieces/pawn.hpp"
#include "pieces/knight.hpp"
#include "pieces/bishop.hpp"
#include "pieces/rook.hpp"
#include "pieces/queen.hpp"
#include "pieces/king.hpp"

#include <iostream>

using namespace std;

Board::Board(Vector2f pos, SDL_Texture* p_texture, int frameWidth, int frameHeight ,SDL_Texture* p_tileset, SDL_Texture* SELECTED_FILE , SDL_Texture* MOVE_FILE) 
        : Entity(pos, p_texture, frameWidth, frameHeight), selectedEntity(pos, SELECTED_FILE, SELECTED_WIDTH, SELECTED_HEIGHT), move(pos, MOVE_FILE,SELECTED_WIDTH, SELECTED_HEIGHT)
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


void Board::update(EventManager &eventmanager) {
    if (selectedCase == nullptr){
        if (eventmanager.isLeftClick()){
            pair<int,int> mousePos = eventmanager.getMousePosition();
            cout << "Mouse : " << mousePos.first << " " << mousePos.second << endl;
            pair<int,int> casePos = clickON(mousePos);
            cout << "Case : " << casePos.first << " " << casePos.second << endl;
            if (casePos.first != -1 && casePos.second != -1)
            {
                if (cases[casePos.first][casePos.second].piece != nullptr)
                {
                    selectedCase = &cases[casePos.first][casePos.second];
                    selectedEntity.setPosition(Vector2f(casePos.first*PIECES_WIDTH + getPosition().x + BOARD_MARGIN, casePos.second*PIECES_HEIGHT + getPosition().y + BOARD_MARGIN));
                }
            }
        }
    }
    
}

void Board::render(RenderWindow &window) {
    window.render(this);
    if (selectedCase != nullptr)
    {
        window.render(&selectedEntity);
    }
    if (selectedCase != nullptr && selectedCase->piece != nullptr)
    for (auto &moveElem : selectedCase->piece->getMoves(Vector2f(selectedCase->x, selectedCase->y), getBoard()))
    {
        Vector2f pos = Vector2f(moveElem.x*PIECES_WIDTH + getPosition().x + BOARD_MARGIN, moveElem.y*PIECES_HEIGHT + getPosition().y + BOARD_MARGIN);
        move.setPosition(pos);
        window.render(move);
    }

    for (auto &entity : getAllPieces())
    {
        window.render(entity);
    }
}

pair<int,int> Board::clickON(pair<int,int> mousePos){
    Vector2f pos = getPosition();
    int x = mousePos.first - pos.x *SCALE_FACTOR - BOARD_MARGIN *SCALE_FACTOR;
    int y = mousePos.second - pos.y *SCALE_FACTOR - BOARD_MARGIN *SCALE_FACTOR;
    cout << "x : " << x << " y : " << y << endl;
    if (x < 0 || y < 0 || x > 8*PIECES_WIDTH*SCALE_FACTOR|| y > 8*PIECES_HEIGHT*SCALE_FACTOR)
    {
        return make_pair(-1,-1);
    }
    else
    {
        return make_pair(x/(PIECES_WIDTH*SCALE_FACTOR), y/(PIECES_HEIGHT*SCALE_FACTOR));
    }
}

pieces::BoardLetter Board::getBoardLetter(){
    pieces::BoardLetter boardLetter;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++) 
        {
            if(cases[i][j].piece != nullptr){
                boardLetter.cases[i][j] = cases[i][j].piece->getLetter();
            }
            else
            {
                boardLetter.cases[i][j] = pieces::PieceLetter::EMPTY;
            }
        }
    }
    return boardLetter;
}

vector<vector<pieces::Piece*>> Board::getBoard() {
    vector<vector<pieces::Piece*>> board;
    for(int i = 0; i < 8; i++)
    {
        vector<pieces::Piece*> tmp;
        for(int j = 0; j < 8; j++) 
        {
            cases[i][j].x = i;
            cases[i][j].y = j;
            tmp.push_back(cases[i][j].piece);
        }
        board.push_back(tmp);
    }
    return board;
}