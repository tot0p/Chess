#pragma once

#include "event_manager.hpp"
#include "render_window.hpp"

#include <iostream>


// regarder factory pattern

class Scene
{
    public:
        virtual void update(EventManager &eventManager) { std::cout << "Scene::update" << std::endl;};
        virtual void render(RenderWindow &window) { std::cout << "Scene::render" << std::endl;};

        virtual void reset(EventManager &eventManager) {};
    
};



