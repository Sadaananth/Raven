#pragma once

#include "Widgets/Widget.hpp"

#include <vector>
#include <memory>

namespace Raven
{

class WidgetManager
{
public:
    static std::unique_ptr<WidgetManager>& instance();

    void addWidget(std::shared_ptr<Widget> widget);
    std::vector<std::shared_ptr<Widget>>& getWidgetList();
private:
    WidgetManager();

    static std::unique_ptr<WidgetManager> mWidgetManagerInstance;

    std::vector<std::shared_ptr<Widget>> mWidgetList;
};

}
