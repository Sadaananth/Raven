#pragma once

#include "Renderer.hpp"

#include <memory>

namespace Raven
{

class Engine
{
public:
    static std::unique_ptr<Engine>& instance();

    void run();
private:
    Engine();

    static std::unique_ptr<Engine> mEngineInstance;

    std::unique_ptr<Renderer>& mRenderer;
};

}
