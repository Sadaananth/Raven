#include "Engine.hpp"

#include "src/Logger.hpp"

#include <stdexcept>

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

Engine::Engine() : mRenderer(Renderer::instance())
{
}

void Engine::run()
{
    mRenderer->start();
}

}
