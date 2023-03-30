#pragma once

#include <memory>

namespace Raven
{

class Entity
{
public:
    Entity();
    virtual ~Entity();

    void setId(uint32_t id);
    uint32_t getId() const;

    void setName(const std::string& name);
    std::string getName() const;

    void setSize(uint32_t width, uint32_t height);

    void loadAsset(const std::string& filename);
protected:

    uint32_t mId;
    std::string mName;
    std::string mAssetPath;
    uint32_t mWidth;
    uint32_t mHeight;
};

}
