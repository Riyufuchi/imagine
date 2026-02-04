//==============================================================================
// File       : AbstractState.h
// Author     : riyufuchi
// Created on : Mar 03, 2025
// Last edit  : Nov 21, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consoleart
//==============================================================================

#ifndef CONSOLEART_ABSTRACT_ABSTRACTSTATE_H_
#define CONSOLEART_ABSTRACT_ABSTRACTSTATE_H_

#include "../controller/controller.h"

namespace consoleart
{
class AbstractState
{
protected:
	Controller& controller;
public:
	AbstractState(Controller& controller);
	virtual ~AbstractState();
};
} /* namespace consoleart */
#endif /* CONSOLEART_ABSTRACT_ABSTRACTSTATE_H_ */
