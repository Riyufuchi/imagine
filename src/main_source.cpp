//============================================================================
// Name        : MainSource.cpp
// Author      : Riyufuchi
// Created on  : Jul 13, 2020
// Last Edit   : Dec 04, 2025
// Description : This is programs main
//============================================================================

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>

#include <QApplication>

#include "imagine/tools/general_tools.hpp"
#include "consolelib/tools/console_tools.h"
#include "consolelib/tools/argument_parser.h"
#include "imagine/qt/main_window.h"

using ParsedArguments = consolelib::argVector;

enum BootAction
{
	ABORT,
	DISPLAY_MANUAL,
	CONTINUE,
	ABOUT,
	LIBRARY
};

BootAction checkArgs(ParsedArguments& argPairs);

BootAction abortQuidoArtLaunch()
{
	std::cerr << "Unrecognized action. Aborting!\n";
	return BootAction::ABORT;
}

int main(int argc, char** argv)
{
	bool success = true;
	std::string resultMsg = "";
	ParsedArguments argPairs = consolelib::ArgumentParser::analyze_in_order(argc, argv, success, resultMsg);
	if (!success)
	{
		std::cerr << resultMsg << "\n";
		return 1;
	}

	switch (checkArgs(argPairs))
	{
		case ABORT: return 1;
		case CONTINUE: goto start;
		default: return 0; // For other cases that result in success
	}

	start: QApplication app(argc, argv);
	imagine::MainWindow window;
	window.show();
	return app.exec();
}

BootAction checkArgs(ParsedArguments& argPairs)
{
	if (argPairs.empty())
		return BootAction::CONTINUE;

	const std::vector<std::pair<std::string, BootAction>> checkFor = {
		{"--man", BootAction::DISPLAY_MANUAL},
		{"--help", BootAction::DISPLAY_MANUAL},
		{"--about", BootAction::ABOUT},
		{"--library", BootAction::LIBRARY}
	};

	for (std::pair<std::string, BootAction> arg : checkFor)
	{
		//if (argPairs.contains(arg.first))
		if (consolelib::ArgumentParser::contains(argPairs, arg.first))
			switch (arg.second)
			{
				case DISPLAY_MANUAL: consoleart::general_tools::create_manual(); return arg.second;
				case ABOUT: std::cout << consoleart::general_tools::about_application() << "\n"; return arg.second;
				case LIBRARY: std::cout << consoleart::general_tools::used_libraries() << "\n"; return arg.second;
				default: abortQuidoArtLaunch();
			}
	}

	return BootAction::CONTINUE;
}
