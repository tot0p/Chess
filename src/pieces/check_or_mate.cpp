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
}