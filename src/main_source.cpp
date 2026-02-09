//============================================================================
// Name        : main_source.cpp
// Author      : Riyufuchi
// Created on  : Jul 13, 2020
// Last Edit   : Feb 09, 2026
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

BootAction check_arguments(ParsedArguments& arg_pairs);

BootAction abort_application_launch()
{
	std::cerr << "Unrecognized action. Aborting!\n";
	return BootAction::ABORT;
}

int main(int argc, char** argv)
{
	bool success = true;
	std::string result_message = "";
	ParsedArguments arg_pairs = consolelib::ArgumentParser::analyze_in_order(argc, argv, success, result_message);
	if (!success)
	{
		std::cerr << result_message << "\n";
		return 1;
	}

	switch (check_arguments(arg_pairs))
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

BootAction check_arguments(ParsedArguments& arg_pairs)
{
	if (arg_pairs.empty())
		return BootAction::CONTINUE;

	const std::vector<std::pair<std::string, BootAction>> check_for_args = {
		{"--man", BootAction::DISPLAY_MANUAL},
		{"--help", BootAction::DISPLAY_MANUAL},
		{"--about", BootAction::ABOUT},
		{"--library", BootAction::LIBRARY}
	};

	for (std::pair<std::string, BootAction> arg : check_for_args)
	{
		if (consolelib::ArgumentParser::contains(arg_pairs, arg.first))
			switch (arg.second)
			{
				case DISPLAY_MANUAL: consoleart::general_tools::create_manual(); return arg.second;
				case ABOUT: std::cout << consoleart::general_tools::about_application() << "\n"; return arg.second;
				case LIBRARY: std::cout << consoleart::general_tools::used_libraries() << "\n"; return arg.second;
				default: abort_application_launch();
			}
	}

	return BootAction::CONTINUE;
}
