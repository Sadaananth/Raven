#include "Engine.hpp"
#include "EntityRenderable.hpp"

#include "src/Logger.hpp"

#include <stdexcept>
#include <thread>

namespace Raven
{

using namespace Sada;

std::unique_ptr<Engine> Engine::mEngineInstance;

std::unique_ptr<Engine>& Engine::instance()
{
    if(!mEngineInstance) {
        mEngineInstance = std::unique_ptr<Engine>(new Engine(500, 600));

        if(!mEngineInstance) {
            throw std::runtime_error("Unable to create instance for Engine");
        }
    }

    return mEngineInstance;
}

std::unique_ptr<Engine>& Engine::instance(uint32_t width, uint32_t height)
{
    if(!mEngineInstance) {
        mEngineInstance = std::unique_ptr<Engine>(new Engine(width, height));

        if(!mEngineInstance) {
            throw std::runtime_error("Unable to create instance for Engine");
        }
    }

    return mEngineInstance;
}

Engine::Engine(uint32_t width, uint32_t height)
    : mEntityManager(EntityManager::instance())
    , mRenderer(Renderer::instance())
    , mWidgetManager(WidgetManager::instance())
    , mFpsWidget(std::make_shared<FpsWidget>(width, height))
{
    mWidgetManager->addWidget(std::dynamic_pointer_cast<Widget>(mFpsWidget));
}

bool Engine::isContinue() const
{
    return mRenderer->isAlive();
}

void Engine::run()
{
    sf::Clock clock;
    auto previousTime = clock.getElapsedTime();
    uint64_t frameCount = 0;
    float fps = 0;
    float timediff = 0;
    while(isContinue()) {
        mRenderer->setup();
        mFpsWidget->setInfo(fps, timediff);
        mEntityManager->preLoadTextures();
        for(auto& entity : mEntityManager->getEntityList()) {
            auto entityRenderable = std::dynamic_pointer_cast<EntityRenderable>(entity);
            mRenderer->getWindow().draw(entityRenderable->getSprite());
        }
        
        for(auto& widget : mWidgetManager->getWidgetList()) {
           widget->draw(mRenderer->getWindow());
        }
        mRenderer->execute();

        auto currentTime = clock.getElapsedTime();
        timediff = static_cast<float>((currentTime - previousTime).asMicroseconds()) / 1000;
        previousTime = currentTime;
        fps = static_cast<float>(frameCount++) / static_cast<float>(currentTime.asSeconds());
        // LOG_DEBUG << "Scene rendered " << timediff << "ms. fps=" << fps;
    }
}

}
