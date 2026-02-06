#ifndef CONTROLLERQT_H
#define CONTROLLERQT_H

#include "controller.h"

namespace imagine
{

class ControllerQt : public consoleart::Controller
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
