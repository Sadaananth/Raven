#pragma once

#include <memory>

namespace Raven
{

class EntityManager
{
public:
    static std::unique_ptr<EntityManager>& instance();
private:
    EntityManager();

    static std::unique_ptr<EntityManager> mEntityManagerInstance;
};

}
