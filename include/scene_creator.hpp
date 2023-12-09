#pragma once

#include "scene.hpp"

#include "game_scene.hpp"
#include "main_menu.hpp"
#include "board.hpp"
#include "win_lose_menu.hpp"

enum SceneId
{
    MAIN_MENU,
    GAME_SCENE,
    WIN_WHITE,
    WIN_BLACK,
};

class SceneCreator
{
    public:
        static Scene* createScene(SceneId sceneId, RenderWindow &window,EventManager &eventManager)
        {
            switch (sceneId)
            {
                case MAIN_MENU:
                    return new MainMenu(window);
                case GAME_SCENE:
                    return new GameScene(window,eventManager);
                case WIN_WHITE:
                    return new WinLoseMenu(window,true);
                case WIN_BLACK:
                    return new WinLoseMenu(window,false);
                default:
                    return nullptr;
            }
        }
};