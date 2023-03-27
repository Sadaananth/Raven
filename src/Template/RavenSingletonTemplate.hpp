#pragma once

#include <memory>

namespace Raven
{

class RavenSingletonTemplate
{
public:
    static std::unique_ptr<RavenSingletonTemplate>& instance();
private:
    RavenSingletonTemplate();

    static std::unique_ptr<RavenSingletonTemplate> mRavenSingletonTemplateInstance;
};

}
