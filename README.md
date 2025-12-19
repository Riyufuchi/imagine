# QuidoArt

- [About](#about)
- [Used libraries](#used-libraries)
- [Documentation](#documentation)
- [Compilation](#compilation)
- [Project guide](#project-guide)
- [Donate](#donate)

## About

This is version that uses Qt framework for gui instead of SDL2 original ConsoleArt project. 

This application works with images and supports even multi-page and animated ones.

Highlighted features:

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
| [stb](https://github.com/nothings/stb) | Working with complex picture formats | ✅ |
| [tinyfiledialogs](http://tinyfiledialogs.sourceforge.net) | Crossplatform dialogs | ✅ |

## Documentation

**!!! Not yet added to the repository!!!**

 ```bash
    # Make sure you have LaTeX installed

    # On Debian/Ubuntu
    sudo apt install texlive-full

    # On macOS
    brew install --cask mactex

    # On Windows
    # Get the installer from https://www.tug.org/texlive/windows.html

    # Get the repository - how to is in section Git and Make
    # Build the PDF documentation
    # (CMake runs LaTeX twice so Table of Contents and references are correct)
    cd latex-doc/
    cmake ..
    cmake --build . --target docs
   ```

## Compilation

### Compiled & Tested on

| OS | Compiler |
| :------: | :----------: |
| Ubuntu | g++ 15.2.0 |
| Windows 10 | MSVC 19.50.35719.0 |

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
