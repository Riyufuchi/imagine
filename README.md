# Imagine

- [About](#about)
- [Used libraries](#used-libraries)
- [Compilation](#compilation)
- [Project guide](#project-guide)
- [Donate](#donate)

## About

This is version that uses Qt framework for gui instead of SDL2 as in original ConsoleArt project and brings new features.

### Features

This application works with images and supports even multi-page and animated ones.

Highlighted features:

* Save and search images from database
* Pack images into .dcx
* Convert images to ascii
* Apply some filters
* Apply signatures to images
* Split gif into individual frames
* And more...

## Used libraries

*The libraries below are listed in the order they were added to the project.*

| Name | Used for | Included in this repository |
| :------: | :----------: | :---: |
| [ConsoleLib](https://github.com/Riyufuchi/ConsoleLib) | Console stuff | ✅ |
| [ConsoleArtLib](https://github.com/Riyufuchi/ConsoleArtLib) | Image tools | ✅ |
| [Qt](https://www.qt.io/development/application-development) | GUI | ❌ |
| [SQLite](https://www.sqlite.org/) | Database | ✅ |

## Compilation

### Compiled & Tested on

| OS | Compiler |
| :------: | :----------: |
| Ubuntu | g++ 15.2.0 |
| <s> Windows 10 </s> | <s> MSVC 19.50.35719.0 </s> |

### CMake

   ```bash
   git clone https://github.com/Riyufuchi/QuidoArt.git
   cd QuidoArt
   
   # CMake for Linux, macOS, MinGW, Ninja (single-config)
   cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
   cmake --build build
   
   # CMake for Visual Studio, Xcode, Ninja Multi-Config
   cmake -S . -B build
   cmake --build build --config Release
   ```

## Project guide

- .hpp is used for single file code, that don't have coresponfing .cpp file

## Donate

Few dollars will be enough. If you are planning to use this library in a commercial application, then it would be fair if you would send more, possibly a small share of 5-10% of monthly profits.

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/P5P11WTFL)
