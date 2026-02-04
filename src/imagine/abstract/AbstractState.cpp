//==============================================================================
// File       : AbstractState.cpp
// Author     : riyufuchi
// Created on : Mar 3, 2025
// Last edit  : Mar 3, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consoleart
//==============================================================================

#include "AbstractState.h"

namespace consoleart {

AbstractState::AbstractState(Controller& controller) : controller(controller)
{
}

AbstractState::~AbstractState()
{
}
} /* namespace consoleart */
