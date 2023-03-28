#include "Entity.hpp"

#include <SFML/Graphics.hpp>

#include <string>

namespace Raven
{

struct EntityPimpl
{
    EntityPimpl() {}
    ~EntityPimpl() {}

    uint32_t mId;
    std::string mName;
    sf::Vector2f mPosition;
};

Entity::Entity() : mEntityPimpl(new EntityPimpl())
{

}

void Entity::setId(uint32_t id)
{
    if(mEntityPimpl) {
        mEntityPimpl->mId = id;
    }
}

uint32_t Entity::getId() const
{
    if(mEntityPimpl) {
        return mEntityPimpl->mId;
    }
}

}
