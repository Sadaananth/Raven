#pragma once

#include "WindowManager.hpp"
#include "EntityManager.hpp"

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

    bool isContinue() const;

    static std::unique_ptr<Engine> mEngineInstance;

    std::unique_ptr<WindowManager>& mWindowManager;
    std::unique_ptr<EntityManager>& mEntityManager;
};

}
