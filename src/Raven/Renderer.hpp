#pragma once

#include <memory>

namespace Raven
{

class RendererPimpl;

class Renderer
{
public:
    static std::unique_ptr<Renderer>& instance();

    void execute();

    bool isAlive() const;

    ~Renderer();
private:
    Renderer();

    static std::unique_ptr<Renderer> mRendererInstance;

    std::unique_ptr<RendererPimpl> mRendererPimpl;
};

}
