#include "EntityRenderable.hpp"

#include "src/Logger.hpp"

namespace Raven
{

using namespace Sada;

void EntityRenderable::loadTexture()
{
    // if(!mTexture.create(500, 400)) {
    //     throw std::runtime_error("Unable to create texture");
    // }

    if(!mTexture.loadFromFile(mAssetPath)) {
        throw std::runtime_error("Failed to load asset " + mAssetPath);
    }

    mSprite.setTexture(mTexture);
    mSprite.setScale(mWidth, mHeight);
}

const sf::Sprite& EntityRenderable::getSprite() const
{
    return mSprite;
}

}
