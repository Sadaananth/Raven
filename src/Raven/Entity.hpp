#pragma once

#include <memory>

namespace Raven
{

struct EntityPimpl;

class Entity
{
public:
    Entity();
    virtual ~Entity() {}

    virtual void update() = 0;

    void setId(uint32_t id);
    uint32_t getId() const;

private:

    std::unique_ptr<EntityPimpl> mEntityPimpl;
};

}
