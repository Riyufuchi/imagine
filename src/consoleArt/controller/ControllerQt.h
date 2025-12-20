#ifndef CONTROLLERQT_H
#define CONTROLLERQT_H

#include "Controller.h"
#include "../gui/tinyFileDialogs/NotifierTFD.h"

namespace consoleart
{

class ControllerQt : public Controller
{
public:
	ControllerQt();
	// Controller interface
protected:
	virtual IndexDataType selectImageMenu() override;
	virtual void showAboutApplicationInfo() override;
public:
	virtual void run() override;
	virtual std::string inputImageName() override;
};

}

#endif // CONTROLLERQT_H
