#include "Entity.hpp"

#include <SFML/Graphics.hpp>

#include <string>

namespace Raven
{

class EntityPimpl
{
public:
    EntityPimpl() {}
    ~EntityPimpl() {}

private:
    uint32_t mId;
    std::string mName;
    sf::Vector2f mPosition;
};

Entity::Entity() : mEntityPimpl(new EntityPimpl())
{

}

}
