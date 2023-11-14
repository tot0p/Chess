#include "pieces/utils.hpp"
#include "pieces/check_or_mate.hpp"


namespace pieces {
    bool isCheck(std::vector<std::vector<Piece *>> board,PieceColor color){
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != nullptr && board[i][j]->getColor() == color){
                    std::list<Move> moves = board[i][j]->getMoves(Vector2f(i, j), board);
                    std::cout << "Check l'echec par "<< (board[i][j] != nullptr ?  board[i][j]->getLetter() : ' ')  << std::endl;
                    for (Move move : moves){
                        std::cout << "Move : " << move.x << " " << move.y << "Piece : " << (board[move.x][move.y] != nullptr ?board[move.x][move.y]->getLetter()  :' ' ) << std::endl;
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
        return false;
    }
}