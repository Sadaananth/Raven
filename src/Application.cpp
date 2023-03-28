#include "Application.hpp"
#include "src/Raven/Engine.hpp"

namespace Raven
{

Application::Application()
{
    Engine::instance();
}

Application::Application(const std::string& applicationName = "")
{
    Engine::instance()->setName(applicationName);
}

Application::~Application()
{

}

void Application::run()
{
    Engine::instance()->run();
}

uint32_t Application::createNewEntity(const std::string& name)
{
    return Engine::instance()->createNewEntity(name);
}

void Application::loadEntityAsset(uint32_t id, const std::string& assetpath)
{
    Engine::instance()->loadEntityAsset(id, assetpath);
}

}
