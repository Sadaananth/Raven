#pragma once

#include "src/Raven/Entity.hpp"
#include <string>

namespace Raven
{

class Application
{
public:
    Application();
    Application(const std::string& applicationName, uint32_t width, uint32_t height);
    virtual ~Application();

    virtual void setup() = 0;

    void run();
    std::shared_ptr<Entity> createNewEntity(const std::string& name);
private:
    std::string mApplicationName;

};

}
