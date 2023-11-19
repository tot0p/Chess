#include "update_manager.hpp"
#include "event_manager.hpp"
#include "entity.hpp"


UpdateManager::UpdateManager(EventManager &eventManager,std::list<Scene*>& scenes) : eventManager(eventManager) , scenes(scenes) {}


void UpdateManager::update(int scene)
{
    std::list<Scene*>::iterator it = scenes.begin();
    std::advance(it,scene);
    (*it)->update(eventManager);
    // board.update(eventManager);
}

