#include "pieces/knight.hpp"
#include "pieces/utils.hpp"



namespace pieces {
    std::list<Move> Knight::getMoves(Vector2f pos,std::vector<std::vector<Piece*>> board){
        std::list<Move> moves;
        int x = pos.x;
        int y = pos.y;
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8){
                if(board[nx][ny] == nullptr || board[nx][ny]->getColor() != this->getColor()){
                    moves.push_back(Move(nx,ny,board[nx][ny] == nullptr ? MoveType::NORMAL : MoveType::ATTACK));
                }
            }
        }
        return moves;
    }
}