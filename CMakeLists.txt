cmake_minimum_required(VERSION 3.20)
project(Imagine LANGUAGES C CXX)

#
# C++ Standard
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# Warnings
#
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	add_compile_options(-Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_options(/W4)
endif()

#
# Other settings
#
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_definitions(NOMINMAX)
endif()

#
# Optimization
#
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	set(CMAKE_CXX_FLAGS_RELEASE "-O3")
	set(CMAKE_C_FLAGS_RELEASE "-O3")
	#
	set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -DDEBUG")
	set(CMAKE_C_FLAGS_DEBUG "-O0 -g -DDEBUG")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(CMAKE_CXX_FLAGS_RELEASE "/O2")
	set(CMAKE_C_FLAGS_RELEASE "/O2")
	#
	set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi /DDEBUG")
	set(CMAKE_C_FLAGS_DEBUG "/Od /Zi /DDEBUG")
endif()

#
# PREBUILT STATIC LIBRARIES
#

#
# ConsoleLib
#
set(CONSOLE_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConsoleLib)

# Create an IMPORTED target for the .a file
add_library(ConsoleLib STATIC IMPORTED)

# Point the IMPORTED target to the actual file
# Windows binary is compiled using mingw g++
if (WIN32)
	set_target_properties(ConsoleLib PROPERTIES
	IMPORTED_LOCATION ${CONSOLE_LIB_DIR}/windows/libConsoleLib.a
	INTERFACE_INCLUDE_DIRECTORIES ${CONSOLE_LIB_DIR})
else()
	set_target_properties(ConsoleLib PROPERTIES
	IMPORTED_LOCATION ${CONSOLE_LIB_DIR}/linux/libConsoleLib.a
	INTERFACE_INCLUDE_DIRECTORIES ${CONSOLE_LIB_DIR})
endif()

#
# ConsoleArtLib
#
add_library(ConsoleArtLib STATIC IMPORTED)

set(CONSOLE_ART_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConsoleArtLib)

# Point the IMPORTED target to the actual file
if (WIN32)

else()
	set_target_properties(ConsoleArtLib PROPERTIES
	IMPORTED_LOCATION ${CONSOLE_ART_LIB_DIR}/linux/libConsoleArtLib.a
	INTERFACE_INCLUDE_DIRECTORIES ${CONSOLE_ART_LIB_DIR})
endif()

#
# Qt
#
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

#
# Application
#
file(MAKE_DIRECTORY build)

file(GLOB_RECURSE APP_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

qt_standard_project_setup()

qt_add_executable(imagine ${APP_SOURCES})

# Link everything
target_include_directories(imagine PRIVATE ${CONSOLE_LIB_DIR}/inc)
target_include_directories(imagine PRIVATE ${GENERAL_LIB_DIR}/ConsoleArtLib/includes)

target_link_libraries(imagine PRIVATE ConsoleArtLib ConsoleLib)
target_link_libraries(imagine PRIVATE Qt6::Core Qt6::Widgets)

#
# Documentation
#
# Path to LaTeX source folder
set(LATEX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/latex-doc)
set(MAIN_TEX QuidoArt.tex)
set(OUTPUT_PDF ${CMAKE_CURRENT_BINARY_DIR}/QuidoArt.pdf)

# Custom target to build docs
add_custom_target(docs
	COMMAND ${CMAKE_COMMAND} -E chdir ${LATEX_DIR} lualatex ${MAIN_TEX}
	COMMAND ${CMAKE_COMMAND} -E chdir ${LATEX_DIR} makeglossaries QuidoArt
	COMMAND ${CMAKE_COMMAND} -E chdir ${LATEX_DIR} lualatex ${MAIN_TEX}
	COMMAND ${CMAKE_COMMAND} -E chdir ${LATEX_DIR} lualatex ${MAIN_TEX}
	COMMENT "Building PDF documentation with lualatex and makeglossaries"
)

