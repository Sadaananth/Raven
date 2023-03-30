#include "Renderer.hpp"

#include "src/Logger.hpp"

#include <stdexcept>

namespace Raven
{

using namespace Sada;

struct RendererPimpl
{
    RendererPimpl();

    void setup();
    void execute();

    bool isWindowOpen() const;

    sf::RenderWindow mRenderWindow;
};

RendererPimpl::RendererPimpl() : mRenderWindow(sf::VideoMode(600, 400), "Raven")
{

}

void RendererPimpl::setup()
{
    mRenderWindow.clear();
}

void RendererPimpl::execute()
{
    mRenderWindow.display();
    sf::Event event;

    while(mRenderWindow.isOpen() && mRenderWindow.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                LOG_DEBUG << "Close event received";
                mRenderWindow.close();
                break;
            default:
                break;
        }
    }
}

bool RendererPimpl::isWindowOpen() const
{
    return mRenderWindow.isOpen();
}

std::unique_ptr<Renderer> Renderer::mRendererInstance;

std::unique_ptr<Renderer>& Renderer::instance()
{
    if(!mRendererInstance) {
        mRendererInstance = std::unique_ptr<Renderer>(new Renderer());

        if(!mRendererInstance) {
            throw std::runtime_error("Unable to create instance for Renderer");
        }
    }

    return mRendererInstance;
}

Renderer::Renderer() : mRendererPimpl(new RendererPimpl())
{
    
}

Renderer::~Renderer()
{

}

void Renderer::setup()
{
    if(mRendererPimpl) {
        mRendererPimpl->execute();
    }
}

void Renderer::execute()
{
    if(mRendererPimpl) {
        mRendererPimpl->execute();
    }
}

bool Renderer::isAlive() const
{
    if(mRendererPimpl) {
        return mRendererPimpl->isWindowOpen();
    }

    return false;
}

void Renderer::setWindowName(const std::string& name)
{
    if(mRendererPimpl) {
        mRendererPimpl->mRenderWindow.setTitle(name);
    }
}

void Renderer::setSize(uint32_t width, uint32_t height)
{
    if(mRendererPimpl) {
        mRendererPimpl->mRenderWindow.setSize(sf::Vector2u(width, height));
    }
}

sf::RenderWindow& Renderer::getWindow() const
{
    if(mRendererPimpl) {
        return mRendererPimpl->mRenderWindow;
    }    
}

}
