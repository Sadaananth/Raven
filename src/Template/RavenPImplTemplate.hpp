#pragma once

#include <memory>

namespace Raven
{

struct RavenPImplTemplatePimpl;

class RavenPImplTemplate
{
public:
    static std::unique_ptr<RavenPImplTemplate>& instance();

    ~RavenPImplTemplate();
private:
    RavenPImplTemplate();

    static std::unique_ptr<RavenPImplTemplate> mRavenPImplTemplateInstance;

    std::unique_ptr<RavenPImplTemplatePimpl> mRavenPImplTemplatePimpl;
};

}
