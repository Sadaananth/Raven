#pragma once

#include <memory>

namespace Raven
{

class EntityPimpl;

class Entity
{
public:
    Entity();
    virtual ~Entity() {}

private:

    std::unique_ptr<EntityPimpl> mEntityPimpl;
};

}
