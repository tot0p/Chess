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
        cout << "posPiece.x : " << posPiece.x << endl;
        cout << "posPiece.y : " << posPiece.y << endl;
        Piece* piece = board[posPiece.x][posPiece.y];
        // if the piece is a pawn check if he can do a special move PASSANT
        if (piece->getLetter() == PieceLetter::PAWN && lastMove.type != MoveType::NONE && board[lastMove.x][lastMove.y]->getLetter() == PieceLetter::PAWN && board[lastMove.x][lastMove.y]->getColor() != color ){
            cout << "pawn detected" << endl;
            // check if are a pawn of the other color on the left or on the right
            if (posPiece.x -1 >= 0 && lastMove.x == posPiece.x - 1 && lastMove.y == posPiece.y){
                moves.push_back(Move(posPiece.x - 1, color == PieceColor::WHITE ? posPiece.y-1 : posPiece.y+1, MoveType::PASSANT));
            }else if (posPiece.x + 1 < board.size() && lastMove.x == posPiece.x + 1 && lastMove.y == posPiece.y){
                moves.push_back(Move(posPiece.x + 1, color == PieceColor::WHITE ? posPiece.y-1 : posPiece.y+1, MoveType::PASSANT));
            }
        }else if (piece->getLetter() == PieceLetter::KING){
            cout << "king detected" << endl;
            // if the piece is a king check if he can do a special move CASTLING
            if (!piece->getHasMoved()){
                // check if the rook on the left or on the right of the king has not moved
                if (board[0][piece->getColor() == PieceColor::WHITE ? 7 : 0] != nullptr && board[0][piece->getColor() == PieceColor::WHITE ? 7 : 0]->getLetter() == PieceLetter::ROOK && !board[0][piece->getColor() == PieceColor::WHITE ? 7 : 0]->getHasMoved()){
                    // check if the king can move to the left
                    bool canMove = true;
                    for (int i = 1; i < 4; i++){
                        if (board[i][piece->getColor() == PieceColor::WHITE ? 7 : 0] != nullptr){
                            canMove = false;
                        }
                    }
                    if (canMove){
                        moves.push_back(Move(2, piece->getColor() == PieceColor::WHITE ? 7 : 0, MoveType::CASTLING));
                    }
                }
                if (board[7][piece->getColor() == PieceColor::WHITE ? 7 : 0] != nullptr && board[7][piece->getColor() == PieceColor::WHITE ? 7 : 0]->getLetter() == PieceLetter::ROOK && !board[7][piece->getColor() == PieceColor::WHITE ? 7 : 0]->getHasMoved()){
                    // check if the king can move to the right
                    bool canMove = true;
                    for (int i = 5; i < 7; i++){
                        if (board[i][piece->getColor() == PieceColor::WHITE ? 7 : 0] != nullptr){
                            canMove = false;
                        }
                    }
                    if (canMove){
                        moves.push_back(Move(6, piece->getColor() == PieceColor::WHITE ? 7 : 0, MoveType::CASTLING));
                    }
                }
            }
        }
        return moves;
    }
}