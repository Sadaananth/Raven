#pragma once

#include <SFML/Graphics.hpp>

namespace Raven
{

class Widget
{
public:
    Widget(uint32_t game_width, uint32_t game_height);
    virtual ~Widget();

    virtual void draw(sf::RenderWindow& window);

    sf::RectangleShape mWidget;
};

}
