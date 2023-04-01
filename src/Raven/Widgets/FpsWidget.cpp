#include "FpsWidget.hpp"

#include <sstream>

namespace Raven
{

FpsWidget::FpsWidget(uint32_t game_width, uint32_t game_height) : Widget(game_width, game_height)
{
    mWidget.setSize(sf::Vector2f(200, 60));
    // mWidget.setPosition(sf::Vector2f(20, game_height - 150));
    mWidget.setPosition(sf::Vector2f(0, 0));
    mWidget.setFillColor(sf::Color::Cyan);

    if(!mFont.loadFromFile("src/Raven/assets/arial.ttf")) {
        throw std::runtime_error("Unable to load font");
    }

    mText.setFont(mFont);
    mText.setFillColor(sf::Color::Black);
    mText.setPosition(sf::Vector2f(0, 0));
    // mText.setPosition(sf::Vector2f(25, game_height - 160));
}

void FpsWidget::setInfo(float fps, float time)
{
    std::stringstream ss;
    ss << "fps:" << fps << "\ntime:" << time << "ms";
    mText.setString(ss.str());
}

FpsWidget::~FpsWidget()
{

}

void FpsWidget::draw(sf::RenderWindow& window)
{
    window.draw(mWidget);
    window.draw(mText);
}

}
