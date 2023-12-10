#include "board.hpp"
#include "constants.hpp"
#include "pieces/pawn.hpp"
#include "pieces/knight.hpp"
#include "pieces/bishop.hpp"
#include "pieces/rook.hpp"
#include "pieces/queen.hpp"
#include "pieces/king.hpp"
#include "pieces/check_or_mate.hpp"
#include "pieces/promote.hpp"
#include "font.hpp"
#include <iostream>
#include "controllerLua.hpp"


using namespace std;

Board::Board(Vector2f pos, SDL_Texture* p_texture, int frameWidth, int frameHeight ,RenderWindow &window , SDL_Texture* p_tileset, SDL_Texture* SELECTED_FILE , SDL_Texture* MOVE_FILE , SDL_Texture* ATTACK_FILE,EventManager &eventmanager ,  PartyConfig config) 
        : Entity(pos, p_texture, frameWidth, frameHeight), selectedEntity(pos, SELECTED_FILE, SELECTED_WIDTH, SELECTED_HEIGHT), move(pos, MOVE_FILE,SELECTED_WIDTH, SELECTED_HEIGHT) , attack(pos,ATTACK_FILE,SELECTED_WIDTH,SELECTED_HEIGHT) , TurnOfWhiteText(nullptr), TurnOfBlackText(nullptr), p_tileset(p_tileset) , lastMove() , history() ,controllerWhite(nullptr), controllerBlack(nullptr)
{       

    
    DefaultBoard();

    // promotionPieces initialization
    promotionPieces[0] = new pieces::Queen(pieces::PieceColor::WHITE , p_tileset);
    promotionPieces[1] = new pieces::Rook( pieces::PieceColor::WHITE , p_tileset);
    promotionPieces[2] = new pieces::Bishop(pieces::PieceColor::WHITE , p_tileset);
    promotionPieces[3] = new pieces::Knight(pieces::PieceColor::WHITE, p_tileset);
    promotionPieces[4] = new pieces::Queen(pieces::PieceColor::BLACK , p_tileset);
    promotionPieces[5] = new pieces::Rook( pieces::PieceColor::BLACK , p_tileset);
    promotionPieces[6] = new pieces::Bishop(pieces::PieceColor::BLACK , p_tileset);
    promotionPieces[7] = new pieces::Knight(pieces::PieceColor::BLACK, p_tileset);

    // GUI
    Font font(FONT_FILE,16,{255,255,255,255});
    Vector2f posTurn = {WINDOW_WIDTH/(2 * SCALE_FACTOR) - getWidth()/3,WINDOW_HEIGHT/(2 * SCALE_FACTOR) - getHeight()/2 - 20 };
    TurnOfWhiteText = font.createTextEntity("Turn of white",window,posTurn);
    TurnOfBlackText = font.createTextEntity("Turn of black",window,posTurn);
    
    // controller
    if (config.type == PartyType::PVP) {
        controllerWhite = new ControllerPlayer(true,eventmanager);
        controllerWhite->setPosition(getPosition());
        controllerBlack = new ControllerPlayer(true,eventmanager);
        controllerBlack->setPosition(getPosition());
    }else if (config.type == PartyType::PVE) {
        controllerWhite = new ControllerPlayer(true,eventmanager);
        controllerWhite->setPosition(getPosition());
        controllerBlack = new ControllerLua(false , "assets/ai/test.lua");
        controllerBlack->setPosition(getPosition());
    }


}

void Board::DefaultBoard() {
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
    
    pair<int,int> casePos;

    if (TurnOfWhite) {
        casePos = controllerWhite->Interact(getBoard());
    }else{
        casePos = controllerBlack->Interact(getBoard());
    }
        // if not out of the board
        if (casePos.first != -1 && casePos.second != -1)
        {
            if (promotion){
                if (casePos.first == promotionPos.x){
                    if (casePos.second == promotionPos.y){
                        cases[(int)promotionPos.x][(int)promotionPos.y].piece = promotionPieces[ TurnOfWhite ? 0 : 4];
                    }else if (casePos.second == promotionPos.y + ( TurnOfWhite ? 1 : -1)){
                        cases[(int)promotionPos.x][(int)promotionPos.y].piece = promotionPieces[ TurnOfWhite ? 1 : 5];
                    }else if (casePos.second == promotionPos.y + ( TurnOfWhite ? 2 : -2)){
                        cases[(int)promotionPos.x][(int)promotionPos.y].piece = promotionPieces[ TurnOfWhite ? 2 : 6];
                    }else if (casePos.second == promotionPos.y + ( TurnOfWhite ? 3 : -3)){
                        cases[(int)promotionPos.x][(int)promotionPos.y].piece = promotionPieces[ TurnOfWhite ? 3 : 7];
                    }
                    promotion = false;
                    pair<bool,bool> checkOrCheckMate = isCheckOrCheckMate();
                    if (checkOrCheckMate.second)
                    {
                        if (TurnOfWhite)
                        {
                            // Win page for white
                            eventmanager.changeScene(2);
                        }
                        else
                        {   
                            // Win page for black
                            eventmanager.changeScene(3);
                        }
                    }
                    TurnOfWhite = !TurnOfWhite;

                }
            }else
            // if a piece is selected
            if (selectedCase != nullptr)
            {
                bool isMove = false;
                // if a move is selected
                for (auto &moveElem : moves)
                {
                    if (moveElem.x == casePos.first && moveElem.y == casePos.second)
                    {
                        // move the piece
                        lastMove = moveElem;
                        selectedCase->piece->UpdateMoved();
                        addHistory(moveElem);
                        cases[casePos.first][casePos.second].piece = selectedCase->piece;
                        cases[selectedCase->x][selectedCase->y].piece = nullptr;

                        if (moveElem.type == pieces::MoveType::PASSANT) {
                            cases[casePos.first][selectedCase->y].piece = nullptr;
                        }
                        else if (moveElem.type == pieces::MoveType::CASTLING){
                            if (casePos.first == 6){
                                cases[5][casePos.second].piece = cases[7][casePos.second].piece;
                                cases[7][casePos.second].piece = nullptr;
                            }else if (casePos.first == 2){
                                cases[3][casePos.second].piece = cases[0][casePos.second].piece;
                                cases[0][casePos.second].piece = nullptr;
                            }

                        }
                        selectedCase = nullptr;

                        if (pieces::promote(Vector2f(casePos.first,casePos.second),getBoard())){
                            promotion = true;
                            promotionPos = Vector2f(casePos.first,casePos.second);
                        }else{
                            // check if check or checkmate
                            pair<bool,bool> checkOrCheckMate = isCheckOrCheckMate();
                            if (checkOrCheckMate.second)
                            {
                                if (TurnOfWhite)
                                {
                                    // Win page for white
                                    eventmanager.changeScene(2);
                                }
                                else
                                {   
                                    // Win page for black
                                    eventmanager.changeScene(3);
                                }
                            }
                            TurnOfWhite = !TurnOfWhite;
                        }
                        
                        
                        // update the board
                        moves.clear();
                        isMove = true;
                    }
                }
                if (!isMove) selectedCase = nullptr;
            }
            else if (cases[casePos.first][casePos.second].piece != nullptr)
            {
                if (TurnOfWhite){
                    if (cases[casePos.first][casePos.second].piece->getColor() == pieces::PieceColor::WHITE){
                        selectedCase = &cases[casePos.first][casePos.second];
                        moves.clear();
                        // Set position of the red square
                        selectedEntity.setPosition(Vector2f(casePos.first*PIECES_WIDTH + getPosition().x + BOARD_MARGIN, casePos.second*PIECES_HEIGHT + getPosition().y + BOARD_MARGIN));
                    }
                } else {
                    if (cases[casePos.first][casePos.second].piece->getColor() == pieces::PieceColor::BLACK){
                        selectedCase = &cases[casePos.first][casePos.second];
                        moves.clear();
                        // Set position of the red square
                        selectedEntity.setPosition(Vector2f(casePos.first*PIECES_WIDTH + getPosition().x + BOARD_MARGIN, casePos.second*PIECES_HEIGHT + getPosition().y + BOARD_MARGIN));
                    }
                }
            }

        }

    //get moves possible
    if (selectedCase != nullptr && moves.empty()){
        Vector2f pos = Vector2f(selectedCase->x, selectedCase->y);
        moves = pieces::supprUnauthorizedMoves(pos,pieces::addSpecialMoves(pos,selectedCase->piece->getMoves(pos,getBoard()),getBoard(),selectedCase->piece->getColor(),lastMove),getBoard(),selectedCase->piece->getColor());
    }

}

void Board::render(RenderWindow &window) {
    // render the board
    window.render(this);

    // render gui selected
    if (selectedCase != nullptr)
    {
        window.render(&selectedEntity);
    }
    if (selectedCase != nullptr && selectedCase->piece != nullptr)
    // render gui moves
    for (auto &moveElem : moves)
    {
        Vector2f pos = Vector2f(moveElem.x*PIECES_WIDTH + getPosition().x + BOARD_MARGIN, moveElem.y*PIECES_HEIGHT + getPosition().y + BOARD_MARGIN);
        if (moveElem.type == pieces::MoveType::ATTACK)
        {
            attack.setPosition(pos);
            window.render(attack);
        }
        else
        {
            move.setPosition(pos);
            window.render(move);
        }
    }

    // render pieces
    for (auto &entity : getAllPieces())
    {
        window.render(entity);
    }

    // render gui turn
    if (TurnOfWhite)
    {
        window.render(TurnOfWhiteText);
    }
    else
    {
        window.render(TurnOfBlackText);
    }

    if (promotion){

        if (TurnOfWhite){
            for (int i = 0; i < 4; i++){
                promotionPieces[i]->setPosition(Vector2f(promotionPos.x*PIECES_WIDTH + getPosition().x + BOARD_MARGIN ,promotionPos.y*PIECES_HEIGHT + getPosition().y + BOARD_MARGIN+ i*PIECES_HEIGHT));
                window.render(promotionPieces[i]);
            }
        }else{
            for (int i = 4; i < 8; i++){
                promotionPieces[i]->setPosition(Vector2f(promotionPos.x*PIECES_WIDTH + getPosition().x + BOARD_MARGIN ,promotionPos.y*PIECES_HEIGHT + getPosition().y + BOARD_MARGIN - (i-4)*PIECES_HEIGHT));
                window.render(promotionPieces[i]);
            }
        }
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

pair<bool,bool> Board::isCheckOrCheckMate() {
    bool isCheck = false;
    bool isCheckMate = false;
    std::vector<std::vector<pieces::Piece *>> board = getBoard();
    if (TurnOfWhite){
        isCheck = pieces::isCheck(board, pieces::PieceColor::WHITE);
        isCheckMate = pieces::isCheckMate(board, pieces::PieceColor::WHITE);
    } else {
        isCheck = pieces::isCheck(board, pieces::PieceColor::BLACK);
        isCheckMate = pieces::isCheckMate(board, pieces::PieceColor::BLACK);
    }
    return make_pair(isCheck, isCheckMate);
}

void Board::reset() {
    TurnOfWhite = true;
    selectedCase = nullptr;
    moves.clear();
    lastMove = pieces::Move();
    history.clear();
    promotion = false;
    promotionPos = Vector2f();

    controllerWhite->reset();
    controllerBlack->reset();


    
    DefaultBoard();
};

void Board::addHistory(pieces::Move) {
    string move = "";
    if (lastMove.type == pieces::MoveType::CASTLING){
        if (lastMove.x == 6){
            move += "O-O";
        }else if (lastMove.x == 2){
            move += "O-O-O";
        }
       
    }else{
        if (selectedCase->piece->getLetter() != pieces::PieceLetter::PAWN){
            move += selectedCase->piece->getLetter();
        }
        if (lastMove.type == pieces::MoveType::ATTACK){
            move += "x";
        }
        move += (char)(lastMove.x + 'a');
        move += (char)(lastMove.y + '1');
    }
    history.push_back(move);
    cout << "history : " << move << endl;
    for (auto &elem : history)
    {
        cout << elem << endl;
    }
}