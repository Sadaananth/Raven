#include "src/Engine.hpp"

#include "src/Logger.hpp"

using namespace Sada;

int main()
{
    Logger::instance().add_sink(Logger::Sink::console, LogLevel::Debug);

    auto& engineInstance = Raven::Engine::instance();

    LOG_DEBUG << "Inside main";

    return 0;
}
