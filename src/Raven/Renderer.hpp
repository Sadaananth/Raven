#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

namespace Raven
{

struct RendererPimpl;

class Renderer
{
public:
    static std::unique_ptr<Renderer>& instance();

    void setup();
    void execute();

    sf::RenderWindow& getWindow() const;

    bool isAlive() const;
    void setWindowName(const std::string& name);

    ~Renderer();
private:
    Renderer();

    static std::unique_ptr<Renderer> mRendererInstance;

    std::unique_ptr<RendererPimpl> mRendererPimpl;
};

}
