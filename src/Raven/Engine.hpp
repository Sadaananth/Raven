#pragma once

#include "EntityManager.hpp"
#include "Renderer.hpp"

#include <memory>

namespace Raven
{

class Engine
{
public:
    static std::unique_ptr<Engine>& instance();

    void setName(const std::string& name);
    void run();

    uint32_t createNewEntity(const std::string& name);
    void loadEntityAsset(uint32_t id, const std::string& assetpath);
private:
    Engine();

    bool isContinue() const;

    static std::unique_ptr<Engine> mEngineInstance;

    std::unique_ptr<EntityManager>& mEntityManager;
    std::unique_ptr<Renderer>& mRenderer;
};

}
