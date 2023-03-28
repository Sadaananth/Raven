#include "src/EntryPoint.hpp"

#include "src/Logger.hpp"

#include <memory>

using namespace Sada;

class Cricket : public Raven::Application
{
public:
    Cricket();
    ~Cricket() {}

    virtual void setup() override;

    void loadAssets();
private:
    
    uint64_t mGround;
};

Cricket::Cricket()
    : Application("Cricket")
    , mGround(UINT64_MAX)
{
}

void Cricket::setup()
{
    loadAssets();
}

void Cricket::loadAssets()
{
    LOG_INFO << "Begin loading assets";

    mGround = createNewEntity("Ground");
    loadEntityAsset(mGround, "app/assets/Ground.png");

    LOG_INFO << "End loading assets";
}

std::unique_ptr<Raven::Application>& applicationInstance()
{
    static auto instance = std::unique_ptr<Raven::Application>(new Cricket());
    return instance;
}
