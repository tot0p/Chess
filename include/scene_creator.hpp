#pragma once

#include "scene.hpp"

#include "game_scene.hpp"
#include "main_menu.hpp"
#include "board.hpp"

enum SceneId
{
    MAIN_MENU,
    GAME_SCENE
};

class SceneCreator
{
    public:
        static Scene* createScene(SceneId sceneId, RenderWindow &window, Board &board)
        {
            switch (sceneId)
            {
                case MAIN_MENU:
                    return new MainMenu(window);
                case GAME_SCENE:
                    return new GameScene(board);
                default:
                    return nullptr;
            }
        }
};