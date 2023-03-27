#pragma once

#include <memory>

namespace Raven
{

class WindowManagerPimpl;

class WindowManager
{
public:
    static std::unique_ptr<WindowManager>& instance();

    void execute();

    bool isAlive() const;

    ~WindowManager();
private:
    WindowManager();

    static std::unique_ptr<WindowManager> mWindowManagerInstance;

    std::unique_ptr<WindowManagerPimpl> mWindowManagerPimpl;
};

}
