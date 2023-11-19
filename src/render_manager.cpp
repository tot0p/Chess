#include "render_manager.hpp"


RenderManager::RenderManager(RenderWindow &window,std::list<Scene*>& scenes,Debug &debug) : window(window)  , scenes(scenes), debug(debug) {
}

void RenderManager::render(int scene)
{
    window.clear();
    // board.render(window);
    //render scenes at index scene
    std::list<Scene*>::iterator it = scenes.begin();
    std::advance(it,scene);
    (*it)->render(window);
    debug.render(window);
    window.display();
}
