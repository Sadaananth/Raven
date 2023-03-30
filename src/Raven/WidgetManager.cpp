#include "WidgetManager.hpp"

#include "Widgets/FpsWidget.hpp"

#include <stdexcept>

namespace Raven
{

std::unique_ptr<WidgetManager> WidgetManager::mWidgetManagerInstance;

std::unique_ptr<WidgetManager>& WidgetManager::instance()
{
    if(!mWidgetManagerInstance) {
        mWidgetManagerInstance = std::unique_ptr<WidgetManager>(new WidgetManager());

        if(!mWidgetManagerInstance) {
            throw std::runtime_error("Unable to create instance for WidgetManager");
        }
    }

    return mWidgetManagerInstance;
}

WidgetManager::WidgetManager()
{

}

void WidgetManager::addWidget(std::shared_ptr<Widget> widget)
{
    mWidgetList.emplace_back(widget);
}

std::vector<std::shared_ptr<Widget>>& WidgetManager::getWidgetList()
{
    return mWidgetList;
}

}
