#include "RavenSingletonTemplate.hpp"

#include <stdexcept>

namespace Raven
{

std::unique_ptr<RavenSingletonTemplate> RavenSingletonTemplate::mRavenSingletonTemplateInstance;

std::unique_ptr<RavenSingletonTemplate>& RavenSingletonTemplate::instance()
{
    if(!mRavenSingletonTemplateInstance) {
        mRavenSingletonTemplateInstance = std::unique_ptr<RavenSingletonTemplate>(new RavenSingletonTemplate());

        if(!mRavenSingletonTemplateInstance) {
            throw std::runtime_error("Unable to create instance for RavenSingletonTemplate");
        }
    }

    return mRavenSingletonTemplateInstance;
}

RavenSingletonTemplate::RavenSingletonTemplate()
{
}

}
