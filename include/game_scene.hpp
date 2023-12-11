#pragma once 

#include "scene.hpp"
#include "board.hpp"
#include "render_window.hpp"
#include "event_manager.hpp"
#include "constants.hpp"
#include "math.hpp"

class GameScene : public Scene
{
    public:
        GameScene(RenderWindow &window,EventManager &eventManager) : board(
        Vector2f(WINDOW_WIDTH / (2 * SCALE_FACTOR) - BOARD_WIDTH / 2, WINDOW_HEIGHT / (2 * SCALE_FACTOR) - BOARD_HEIGHT / 2),
        window.loadTexture(BOARD_FILE),
        BOARD_WIDTH,BOARD_HEIGHT,
        window,
        window.loadTexture(PIECES_FILE),
        window.loadTexture(SELECTED_FILE),
        window.loadTexture(GREEN_FILE),
        window.loadTexture(RED_FILE),
        eventManager
        ) {
        }
        void update(EventManager &eventManager) override {
            board.update(eventManager);
        }
        void render(RenderWindow &window) override {
            board.render(window);
        }
        void reset(EventManager &eventManager) override {
            board.reset(eventManager);
        }
    private:
        Board board;
};