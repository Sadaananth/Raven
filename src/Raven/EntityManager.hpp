#pragma once

#include "Entity.hpp"

#include <memory>
#include <vector>

namespace Raven
{

struct EntityManagerPimpl;

class EntityManager
{
public:
    static std::unique_ptr<EntityManager>& instance();

    std::shared_ptr<Entity> registerEntity(const std::string& name);

    std::vector<std::shared_ptr<Entity>>& getEntityList();

    void preLoadTextures();
private:
    EntityManager();

    static std::unique_ptr<EntityManager> mEntityManagerInstance;

    std::unique_ptr<EntityManagerPimpl> mEntityManagerPimpl;
};

}
