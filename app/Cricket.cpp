#include "src/EntryPoint.hpp"

#include "src/Logger.hpp"

#include <memory>

using namespace Sada;

constexpr uint32_t GameWidth = 600;
constexpr uint32_t GameHeight = 480;

class Cricket : public Raven::Application
{
public:
    Cricket();
    ~Cricket() {}

    virtual void setup() override;

    void loadAssets();
private:
    
    std::shared_ptr<Raven::Entity> mGroundEntity;
};

Cricket::Cricket()
    : Application("Cricket", GameWidth, GameHeight)
    , mGroundEntity(nullptr)
{
}

void Cricket::setup()
{
    loadAssets();
}

void Cricket::loadAssets()
{
    LOG_INFO << "Begin loading assets";

    mGroundEntity = createNewEntity("Ground");
    mGroundEntity->setSize(GameWidth, GameHeight);
    mGroundEntity->loadAsset("app/assets/Ground.png");

    LOG_INFO << "End loading assets";
}

std::unique_ptr<Raven::Application>& applicationInstance()
{
    static auto instance = std::unique_ptr<Raven::Application>(new Cricket());
    return instance;
}
