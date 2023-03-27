#include "src/EntryPoint.hpp"

class Cricket : public Raven::Application
{
public:
    Cricket() {}
    ~Cricket() {}

private:
    
};

std::unique_ptr<Raven::Application>& applicationInstance()
{
    static auto instance = std::unique_ptr<Raven::Application>(new Cricket());
    return instance;
}
