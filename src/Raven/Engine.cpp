#include "Engine.hpp"

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
        mEngineInstance = std::unique_ptr<Engine>(new Engine());

        if(!mEngineInstance) {
            throw std::runtime_error("Unable to create instance for Engine");
        }
    }

    return mEngineInstance;
}

Engine::Engine()
    : mEntityManager(EntityManager::instance())
    , mRenderer(Renderer::instance())
{
}

bool Engine::isContinue() const
{
    return mRenderer->isAlive();
}

void Engine::setName(const std::string& name)
{
    mRenderer->setWindowName(name);
}

void Engine::run()
{
    while(isContinue()) {
        mRenderer->setup();
        mEntityManager->draw(mRenderer->getWindow());
        mRenderer->execute();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

uint32_t Engine::createNewEntity(const std::string& name)
{
    return mEntityManager->registerEntity(name);
}

void Engine::loadEntityAsset(uint32_t id, const std::string& assetpath)
{
    return mEntityManager->loadEntityAsset(id, assetpath);
}

}
