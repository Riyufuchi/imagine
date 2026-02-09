//==============================================================================
// File       : abstract_notifier.h
// Author     : Riyufuchi
// Created on : Apr 28, 2024
// Last edit  : Feb 09, 2026
// Copyright  : Copyright (c) 2024, Riyufuchi
// Description: consoleart
//==============================================================================

#ifndef _CONSOLE_ART_CLI_CONSOLEM_ESSENGER_H_
#define _CONSOLE_ART_CLI_CONSOLEM_ESSENGER_H_

#include "consolelib/tools/color_tools.h"
#include "consolelib/tools/console_tools.h"
#include "consolelib/consoles.hpp"
//
#include "consoleartlib/images/base/image.h"

namespace consoleart
{

class AbstractNotifier
{
public:
	enum MessageType
	{
		EXCEPTION,
		PROBLEM,
		WARNING,
		SUCCESFUL_TASK,
		INFO,
		NOTIFICATION
	};
public:
	AbstractNotifier();
	virtual ~AbstractNotifier();
	virtual void message_user(const std::string& message) final;
	virtual void message_user(MessageType messageSeverity, const std::string& message) = 0;
	virtual void display_image_info(const consoleartlib::Image& image) = 0;
};
} /* namespace consoleart */
#endif /* CONSOLEART_CLI_CONSOLEMESSENGER_H_ */
