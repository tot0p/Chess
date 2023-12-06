#include "pieces/utils.hpp"
#include "pieces/check_or_mate.hpp"


namespace pieces {
    // verify if the king of the other color is in check
    bool isCheck(std::vector<std::vector<Piece *>> board,PieceColor color){
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != nullptr && board[i][j]->getColor() == color){
                    std::list<Move> moves = board[i][j]->getMoves(Vector2f(i, j), board);
                    for (Move move : moves){
                        if (board[move.x][move.y] != nullptr && board[move.x][move.y]->getLetter() == PieceLetter::KING){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool isCheckMate(std::vector<std::vector<Piece *>> board,PieceColor color){
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != nullptr && board[i][j]->getColor() != color){
                    std::list<Move> moves = board[i][j]->getMoves(Vector2f(i, j), board);
                    for (Move move : moves){
                        std::vector<std::vector<Piece *>> newBoard = board;
                        newBoard[move.x][move.y] = newBoard[i][j];
                        newBoard[i][j] = nullptr;
                        if (!isCheck(newBoard,color)){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

     std::list<Move> supprUnauthorizedMoves(Vector2f posPiece,std::list<Move> moves,std::vector<std::vector<Piece *>> board,PieceColor color) {
        std::list<Move> authorizedMoves;
        for (Move move : moves){
            std::vector<std::vector<Piece *>> newBoard = board;
            newBoard[move.x][move.y] = newBoard[posPiece.x][posPiece.y];
            newBoard[posPiece.x][posPiece.y] = nullptr;
            if (!isCheck(newBoard,color == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE)){
                authorizedMoves.push_back(move);
            }
        }
        return authorizedMoves;
     }

    std::list<Move> addSpecialMoves(Vector2f posPiece,std::list<Move> moves,std::vector<std::vector<Piece *>> board,PieceColor color,Move lastMove)
    {
        
        cout << "lastMove->x : " << lastMove.x << endl;
        cout << "lastMove->y : " << lastMove.y << endl;
        cout << "lastMove->type : " << lastMove.type << endl;
        cout << "pawn detected" << endl;
        cout << "posPiece.x : " << posPiece.x << endl;
        cout << "posPiece.y : " << posPiece.y << endl;
        Piece* piece = board[posPiece.x][posPiece.y];
        // if the piece is a pawn check if he can do a special move PASSANT
        if (piece->getLetter() == PieceLetter::PAWN && lastMove.type != MoveType::NONE && board[lastMove.x][lastMove.y]->getLetter() == PieceLetter::PAWN && board[lastMove.x][lastMove.y]->getColor() != color ){
            cout << "pawn detected" << endl;
            // check if are a pawn of the other color on the left or on the right
            if (posPiece.x -1 >= 0 && lastMove.x == posPiece.x - 1 && lastMove.y == posPiece.y){
                cout << "left" << endl;
                moves.push_back(Move(posPiece.x - 1, color == PieceColor::WHITE ? posPiece.y-1 : posPiece.y+1, MoveType::PASSANT));
            }else if (posPiece.x + 1 < board.size() && lastMove.x == posPiece.x + 1 && lastMove.y == posPiece.y){
                cout << "right" << endl;
                moves.push_back(Move(posPiece.x + 1, color == PieceColor::WHITE ? posPiece.y-1 : posPiece.y+1, MoveType::PASSANT));
            }

            // if (posPiece.x - 1 >= 0 && board[posPiece.x - 1][posPiece.y] != nullptr && board[posPiece.x - 1][posPiece.y]->getLetter() == PieceLetter::PAWN && board[posPiece.x - 1][posPiece.y]->getColor() != color){
            //     // check if the pawn of the other color has just done a special move
            //     if (board[posPiece.x - 1][posPiece.y]->getHasMoved() == HasMoved::FIRST){
            //         moves.push_back(Move(posPiece.x - 1, posPiece.y, MoveType::PASSANT));
            //     }
            // }
            // if (posPiece.x + 1 < board.size() && board[posPiece.x + 1][posPiece.y] != nullptr && board[posPiece.x + 1][posPiece.y]->getLetter() == PieceLetter::PAWN && board[posPiece.x + 1][posPiece.y]->getColor() != color){
            //     // check if the pawn of the other color has just done a special move
            //     if (board[posPiece.x + 1][posPiece.y]->getHasMoved() == HasMoved::FIRST){
            //         moves.push_back(Move(posPiece.x + 1, posPiece.y, MoveType::PASSANT));
            //     }
            // }
        }else if (piece->getLetter() == PieceLetter::KING){
            // if the piece is a king check if he can do a special move CASTLING
        }
        return moves;
    }
}