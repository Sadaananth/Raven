#include "EntityManager.hpp"

#include <stdexcept>

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

}
