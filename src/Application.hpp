#pragma once

#include <string>

namespace Raven
{

class Application
{
public:
    Application();
    Application(const std::string& applicationName);
    virtual ~Application();

    virtual void setup() = 0;

    void run();
    uint32_t createNewEntity(const std::string& name);
    void loadEntityAsset(uint32_t id, const std::string& assetpath);
private:
    std::string mApplicationName;

};

}
