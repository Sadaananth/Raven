#pragma once

#include "Application.hpp"

#include "src/Logger.hpp"

#include <memory>

using namespace Sada;

extern std::unique_ptr<Raven::Application>& applicationInstance();
 
int main()
{
    Logger::instance().add_sink(Logger::Sink::console, LogLevel::Debug);
    auto& application = applicationInstance();

    LOG_DEBUG << "Application is created";

    application->setup();
    application->run();

    return 0;
}
