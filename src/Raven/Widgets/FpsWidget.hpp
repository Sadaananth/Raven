#pragma once

#include "Widget.hpp"

namespace Raven
{

class FpsWidget : public Widget
{
public:
    FpsWidget(uint32_t game_width, uint32_t game_height);
    ~FpsWidget();

    void setInfo(float fps, float time);

    virtual void draw(sf::RenderWindow& window) override;
private:
    sf::Text mText;
    sf::Font mFont;
};

}
