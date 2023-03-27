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
    : mWindowManager(WindowManager::instance())
    , mEntityManager(EntityManager::instance())
{
}

bool Engine::isContinue() const
{
    return mWindowManager->isAlive();
}

void Engine::run()
{
    while(isContinue()) {
        mWindowManager->execute();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

}
