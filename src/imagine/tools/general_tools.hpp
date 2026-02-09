//==============================================================================
// File       : GeneralTools.hpp
// Author     : riyufuchi
// Created on : Nov 23, 2023
// Last edit  : Feb 04, 2026
// Copyright  : Copyright (c) Riyufuchi
// Description: consoleart
//==============================================================================

#ifndef _CONSOLE_ART_GENERAL_TOOLS_HPP_
#define _CONSOLE_ART_GENERAL_TOOLS_HPP_

#include <iostream>
#include <string>

#include "consolelib/console_lib.h"
#include "consolelib/tools/console_tools.h"

#define _COPYRIGHT_HEADER "Riyufuchi (c) 2020 - 2025\n"

#define _APP_NAME "Imagine"
#define _APP_VERSION "0.3 - Alpha"

#ifdef DEBUG
	#define _CONSOLE_ART_VERSION _APP_NAME " v" _APP_VERSION " (debug)"
#else
	#define _CONSOLE_ART_VERSION _APP_NAME " v" _APP_VERSION
#endif

namespace consoleart::general_tools
{

inline const std::vector<std::string> FILTER_TEXTS = { "Matrix", "Purplefier", "Purplefier soft", "Purplefier shading", "Purplefier shading soft" };
inline constexpr const char* IMAGINE_APP_VERSION = _CONSOLE_ART_VERSION;

inline void create_manual()
{
	std::cout << _COPYRIGHT_HEADER;
	std::string args[] = {
		"Arguments| Actions",
		"-p --path [path]| Specify workspace folder",
		"--loadAll| Loads all images in workspace (should be after --path)",
		"--image [path...]| Loads given image or images (in workspace if defined)",
		"--about| Shows details about this application",
		"--benchmark [path (optional)]| Starts simple benchmark that loads and convert image (default file: bench.pcx)",
		"--library| Shows info about ConsoleLib and other used libraries besides standard and platform depended",
		"--compare [image1] [image2]| Compare dimensions of the two given images",
	};
	consolelib::console_tools::create_manual(args, sizeof(args)/sizeof(args[0]));
}

inline std::string used_libraries()
{
	std::stringstream info;
	info << "Used libraries:\n" << consolelib::aboutLibrary();
	std::string libs[] = {
		"Name| Used for",
		"stb| Complex images",
		"Qt| GUI",
	};
	info << "\n" << consolelib::console_tools::create_table(libs, sizeof(libs)/sizeof(libs[0]));
	return info.str();
}

inline std::string about_application()
{
	std::stringstream aboutStringStream;
	aboutStringStream << _COPYRIGHT_HEADER;
	aboutStringStream << "This version was compiled on: " << __DATE__ << " " << __TIME__ << "\n";
	aboutStringStream << "C++ version: " << __cplusplus << "\n\n";

	aboutStringStream << "This is an C++ application for converting images into ASCII/UNICODE.\n\n";

	aboutStringStream << "How to use:\n";
	aboutStringStream << "1. Select font (in your console/terminal) where all characters have same width\n";
	aboutStringStream << "2. Load and select image\n";
	aboutStringStream << "3. Convert image\n";
	aboutStringStream << "4. In order to view the image, make font smaller.\nSize 2 is recommended for bigger images, however this depends on size of given image\n\n";

	aboutStringStream << "Supported image formats\n";
	std::string args[] = {
		"Format| Bits; Notes",
		"PCX| 24, 32; VGA palate",
		"BMP| 24, 32; Bottom left corner start oriented, Uncompressed BGRA",
		"PPM| 24;",
		"PNG| 24, 32;",
		"JPG| 24, 32;",
		"GIF| 24; first frame only",
		"HDR| 24, 32; basic implementation"
	};
	aboutStringStream << consolelib::console_tools::create_table(args, sizeof(args)/sizeof(args[0])) << "\n";
	aboutStringStream << used_libraries();
	return aboutStringStream.str();
}

inline std::string create_arg_error_message(const std::string& argument)
{
	return "Invalid or unknown " + argument + " inputed.\nUse --man or --help for help.\n";
}

} // Namespace
#endif /* _CONSOLE_ART_GENERAL_TOOLS_HPP_ */
