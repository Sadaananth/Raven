#include "Renderer.hpp"

#include "src/Logger.hpp"

#include <SFML/Graphics.hpp>

#include <stdexcept>

namespace Raven
{

using namespace Sada;

class RendererPimpl
{
public:
    RendererPimpl();

    void start();
private:
    sf::RenderWindow mRenderWindow;
};

RendererPimpl::RendererPimpl() : mRenderWindow(sf::VideoMode(600, 400), "Render")
{

}

void RendererPimpl::start()
{
    mRenderWindow.clear();
    mRenderWindow.display();
    sf::Event event;

    while(mRenderWindow.pollEvent(event)) {
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

void Renderer::start()
{
    if(mRendererPimpl) {
        mRendererPimpl->start();
    }
}

}
