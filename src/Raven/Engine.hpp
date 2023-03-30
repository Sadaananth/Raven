#pragma once

#include "EntityManager.hpp"
#include "Renderer.hpp"
#include "WidgetManager.hpp"
#include "src/Raven/Widgets/FpsWidget.hpp"

#include <memory>

namespace Raven
{

class Engine
{
public:
    static std::unique_ptr<Engine>& instance();
    static std::unique_ptr<Engine>& instance(uint32_t width, uint32_t height);

    void run();

    void loadEntityAsset(uint32_t id, const std::string& assetpath);
private:
    Engine(uint32_t width, uint32_t height);

    bool isContinue() const;

    static std::unique_ptr<Engine> mEngineInstance;

    std::unique_ptr<EntityManager>& mEntityManager;
    std::unique_ptr<Renderer>& mRenderer;
    std::unique_ptr<WidgetManager>& mWidgetManager;

    std::shared_ptr<FpsWidget> mFpsWidget;
};

}
