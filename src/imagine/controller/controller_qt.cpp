#include "controller_qt.h"

namespace consoleart
{

ControllerQt::ControllerQt() : Controller(nullptr, nullptr, nullptr)
{}


Controller::IndexDataType consoleart::ControllerQt::selectImageMenu()
{
	return 0;
}

void ControllerQt::showAboutApplicationInfo()
{
}

void ControllerQt::run()
{
}

std::string ControllerQt::inputImageName()
{
	return "";
}

}
