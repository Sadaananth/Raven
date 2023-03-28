#pragma once

#include "Entity.hpp"

#include <memory>
#include <vector>

namespace Raven
{

class EntityManager
{
public:
    static std::unique_ptr<EntityManager>& instance();

    uint32_t registerEntity(const std::string& name);
    void loadEntityAsset(uint32_t id, const std::string& assetpath);

    void draw(sf::RenderWindow& window);
private:
    EntityManager();

    static std::unique_ptr<EntityManager> mEntityManagerInstance;

    std::vector<std::unique_ptr<Entity>> mEntityList;
};

}
