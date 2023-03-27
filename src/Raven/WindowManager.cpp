#include "WindowManager.hpp"

#include "src/Logger.hpp"

#include <SFML/Graphics.hpp>

#include <stdexcept>

namespace Raven
{

using namespace Sada;

class WindowManagerPimpl
{
public:
    WindowManagerPimpl();

    void execute();

    bool isWindowOpen() const;
private:
    sf::RenderWindow mRenderWindow;
};

WindowManagerPimpl::WindowManagerPimpl() : mRenderWindow(sf::VideoMode(600, 400), "Render")
{

}

void WindowManagerPimpl::execute()
{
    mRenderWindow.clear();
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

bool WindowManagerPimpl::isWindowOpen() const
{
    return mRenderWindow.isOpen();
}

std::unique_ptr<WindowManager> WindowManager::mWindowManagerInstance;

std::unique_ptr<WindowManager>& WindowManager::instance()
{
    if(!mWindowManagerInstance) {
        mWindowManagerInstance = std::unique_ptr<WindowManager>(new WindowManager());

        if(!mWindowManagerInstance) {
            throw std::runtime_error("Unable to create instance for WindowManager");
        }
    }

    return mWindowManagerInstance;
}

WindowManager::WindowManager() : mWindowManagerPimpl(new WindowManagerPimpl())
{
    
}

WindowManager::~WindowManager()
{

}

void WindowManager::execute()
{
    if(mWindowManagerPimpl) {
        mWindowManagerPimpl->execute();
    }
}

bool WindowManager::isAlive() const
{
    if(mWindowManagerPimpl) {
        return mWindowManagerPimpl->isWindowOpen();
    }

    return false;
}

}
