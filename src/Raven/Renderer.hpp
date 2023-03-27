#pragma once

#include <memory>

namespace Raven
{

class RendererPimpl;

class Renderer
{
public:
    static std::unique_ptr<Renderer>& instance();

    void start();

    ~Renderer();
private:
    Renderer();

    static std::unique_ptr<Renderer> mRendererInstance;

    std::unique_ptr<RendererPimpl> mRendererPimpl;
};

}
