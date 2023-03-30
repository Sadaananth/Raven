#include "EntityManager.hpp"
#include "EntityRenderable.hpp"

#include "src/Logger.hpp"

#include <stdexcept>
#include <algorithm>

using namespace Sada;

namespace Raven
{

struct EntityManagerPimpl
{
    std::vector<std::shared_ptr<Entity>> mEntityRenderableList;
};

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

EntityManager::EntityManager() : mEntityManagerPimpl(new EntityManagerPimpl())
{
}

std::shared_ptr<Entity> EntityManager::registerEntity(const std::string& name)
{
    std::shared_ptr<Entity> entityRenderable(new EntityRenderable());
    entityRenderable->setId(mEntityManagerPimpl->mEntityRenderableList.size() + 1);
    entityRenderable->setName(name);
    mEntityManagerPimpl->mEntityRenderableList.emplace_back(entityRenderable);

    return entityRenderable;
}

std::vector<std::shared_ptr<Entity>>& EntityManager::getEntityList()
{
    return mEntityManagerPimpl->mEntityRenderableList;
}

void EntityManager::preLoadTextures()
{
    for(auto& entity : mEntityManagerPimpl->mEntityRenderableList) {
        auto entityRenderable = std::dynamic_pointer_cast<EntityRenderable>(entity);
        entityRenderable->loadTexture();
    }
}

}
