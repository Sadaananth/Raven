#pragma once

#include <memory>

namespace Raven
{

class Engine
{
public:
    static std::unique_ptr<Engine>& instance();
private:
    Engine();

    static std::unique_ptr<Engine> mEngineInstance;
};

}
