#include "EntityManager.hpp"

#include "src/Logger.hpp"

#include <stdexcept>
#include <algorithm>

using namespace Sada;

namespace Raven
{

std::unique_ptr<EntityManager> EntityManager::mEntityManagerInstance;

std::unique_ptr<EntityManager>& EntityManager::instance()
{
    if(!mEntityManagerInstance) {
        mEntityManagerInstance = std::unique_ptr<EntityManager>(new EntityManager());

        if(!mEntityManagerInstance) {
            throw std::runtime_error("Unable to create instance for EntityManager");
        }
    }

    return mEntityManagerInstance;
}

EntityManager::EntityManager()
{
}

uint32_t EntityManager::registerEntity(const std::string& name)
{
    std::unique_ptr<Entity> entity(new Entity());
    entity->setId(mEntityList.size() + 1);
    entity->setName(name);
    mEntityList.emplace_back(std::move(entity));

    return mEntityList.size();
}

void EntityManager::loadEntityAsset(uint32_t id, const std::string& assetpath)
{
    auto itr = std::find_if(mEntityList.begin(), mEntityList.end(), [id](auto& entity) {
        if(id == entity->getId()) {
            return true;
        }

        return false;
    });

    if(itr != mEntityList.end()) {
        (*itr)->loadAsset(assetpath);
    } else {
        LOG_DEBUG << "Entity " << id << " not found";
    }
}

void EntityManager::draw(sf::RenderWindow& window)
{
    for(auto& entity : mEntityList) {
        window.draw(entity->getSprite());
    }
}

}
