#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

namespace Raven
{

class Entity
{
public:
    Entity();
    ~Entity();

    void setId(uint32_t id);
    uint32_t getId() const;

    void setName(const std::string& name);
    std::string getName() const;

    void loadAsset(const std::string& filename);

    const sf::Sprite& getSprite() const;
private:

    uint32_t mId;
    std::string mName;
    sf::Vector2f mPosition;

    sf::Texture mTexture;
    sf::Sprite mSprite;
};

}
