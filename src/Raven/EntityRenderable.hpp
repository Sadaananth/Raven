#pragma once

#include "Entity.hpp"

#include <SFML/Graphics.hpp>

namespace Raven
{

class EntityRenderable : public Entity
{
public:
    const sf::Sprite& getSprite() const;

    void loadTexture();

private:

    sf::Vector2f mPosition;
    sf::Texture mTexture;
    sf::Sprite mSprite;
};

}
