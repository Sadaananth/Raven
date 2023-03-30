#include "EntityRenderable.hpp"

#include "src/Logger.hpp"

namespace Raven
{

using namespace Sada;

void EntityRenderable::loadTexture()
{
    if(!textureUpdated) {
        textureUpdated = true;
        if(!mTexture.loadFromFile(mAssetPath)) {
            throw std::runtime_error("Failed to load asset " + mAssetPath);
        }

        mSprite.setTexture(mTexture);

        auto size = mTexture.getSize();
        auto scalex = (float)mWidth / (float)size.x;
        auto scaley = (float)mHeight / (float)size.y;

        mSprite.setScale(scalex, scaley);
    }
}

const sf::Sprite& EntityRenderable::getSprite() const
{
    return mSprite;
}

}
