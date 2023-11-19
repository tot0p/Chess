#pragma once 

#include "scene.hpp"
#include "board.hpp"


class GameScene : public Scene
{
    public:
        GameScene(Board &board) : board(board) {
            
        }
        void update(EventManager &eventManager) override {
            board.update(eventManager);
        }
        void render(RenderWindow &window) override {
            board.render(window);
        }
    private:
        Board& board;
};