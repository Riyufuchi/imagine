//==============================================================================
// File       : abstract_notifier.cpp
// Author     : riyufuchi
// Created on : Apr 28, 2024
// Last edit  : Feb 09, 2026
// Copyright  : Copyright (c) 2024, riyufuchi
// Description: consoleart
//==============================================================================

#include "abstract_notifier.h"

consoleart::AbstractNotifier::AbstractNotifier()
{
}

consoleart::AbstractNotifier::~AbstractNotifier()
{
}

void consoleart::AbstractNotifier::message_user(const std::string& message)
{
	message_user(MessageType::INFO, message);
}

