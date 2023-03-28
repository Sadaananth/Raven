#include "Entity.hpp"

#include "src/Logger.hpp"

#include <string>
#include <fstream>

using namespace Sada;

namespace Raven
{

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::setId(uint32_t id)
{
    mId = id;
}

uint32_t Entity::getId() const
{
    return mId;
}

void Entity::setName(const std::string& name)
{
    mName = name; 
}

std::string Entity::getName() const
{
    return mName;
}

void Entity::loadAsset(const std::string& filename)
{
    if(!mTexture.loadFromFile(filename)) {
        throw std::runtime_error("Failed to load asset " + filename);
    }

    mSprite.setTexture(mTexture);

    LOG_DEBUG << "Asset " << filename << " loaded succesfully";
}

const sf::Sprite& Entity::getSprite() const
{
    return mSprite;
}

}
