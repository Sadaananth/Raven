#include "RavenPImplTemplate.hpp"

#include <stdexcept>

namespace Raven
{

struct RavenPImplTemplatePimpl
{
    RavenPImplTemplatePimpl();

};

RavenPImplTemplatePimpl::RavenPImplTemplatePimpl()
{

}

std::unique_ptr<RavenPImplTemplate> RavenPImplTemplate::mRavenPImplTemplateInstance;

std::unique_ptr<RavenPImplTemplate>& RavenPImplTemplate::instance()
{
    if(!mRavenPImplTemplateInstance) {
        mRavenPImplTemplateInstance = std::unique_ptr<RavenPImplTemplate>(new RavenPImplTemplate());

        if(!mRavenPImplTemplateInstance) {
            throw std::runtime_error("Unable to create instance for RavenPImplTemplate");
        }
    }

    return mRavenPImplTemplateInstance;
}

RavenPImplTemplate::RavenPImplTemplate() : mRavenPImplTemplatePimpl(new RavenPImplTemplatePimpl())
{
    
}

RavenPImplTemplate::~RavenPImplTemplate()
{

}

}
