#include "Application.hpp"
#include "src/Raven/Engine.hpp"
#include "src/Raven/EntityManager.hpp"
#include "src/Raven/Renderer.hpp"

namespace Raven
{

Application::Application()
{
    Engine::instance();
}

Application::Application(const std::string& applicationName, uint32_t width, uint32_t height)
{
    Engine::instance();
    Renderer::instance()->setWindowName(applicationName);
    Renderer::instance()->setSize(width, height);
}

Application::~Application()
{

}

void Application::run()
{
    Engine::instance()->run();
}

std::shared_ptr<Entity> Application::createNewEntity(const std::string& name)
{
    return EntityManager::instance()->registerEntity(name);
}

}
