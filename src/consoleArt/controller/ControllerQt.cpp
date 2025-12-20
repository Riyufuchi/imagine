#include "ControllerQt.h"

namespace consoleart
{

ControllerQt::ControllerQt() : Controller(new NotifierTFD(), nullptr, nullptr)
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
