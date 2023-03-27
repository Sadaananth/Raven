#include "Application.hpp"
#include "src/Raven/Engine.hpp"

namespace Raven
{

Application::Application()
{
    Engine::instance();
}

Application::~Application()
{

}

void Application::run()
{
    while(true) {
        Engine::instance()->run();
    }
}

}
