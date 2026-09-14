Building with CMake
E++ uses CMake as its build system to ensure cross-platform compatibility across Linux, macOS, Windows, Android, and iOS.

Prerequisites
C++17 Compiler: GCC 7+, Clang 5+, or MSVC 2017+

CMake: Version 3.10 or higher

(Optional) SDL2 Development Libraries: Required only if building with graphics support enabled.

Basic Build (Standard Console Interpreter)
To build the standard command-line interpreter:

Bash
# 1. Create and enter a build directory
mkdir build && cd build

# 2. Configure the project
cmake ..

# 3. Compile the executable
cmake --build .
The compiled binary (eplusplus or eplusplus.exe) will be generated inside the build/ directory.

Building with Graphics Support
If you wish to enable the optional SDL2 graphics interface, pass -DENABLE_GRAPHICS=ON during configuration. CMake will automatically detect your operating system and link the appropriate graphics libraries (OpenGL, GLES, Android log/native system libraries, Frameworks, etc.).

Bash
mkdir build && cd build
cmake -DENABLE_GRAPHICS=ON ..
cmake --build .
Platform-Specific Quick Guides
Linux (Ubuntu / Debian / Arch / Fedora)
Install dependencies and build:

Bash
# Ubuntu/Debian dependencies
sudo apt update && sudo apt install cmake build-essential libsdl2-dev

# Build
mkdir build && cd build
cmake -DENABLE_GRAPHICS=ON ..
cmake --build .
macOS (Homebrew)
Install dependencies and build:

Bash
# Install dependencies
brew install cmake sdl2

# Build
mkdir build && cd build
cmake -DENABLE_GRAPHICS=ON ..
cmake --build .
Windows (MSVC / Visual Studio or MinGW)
Using Developer Command Prompt or PowerShell:

DOS
mkdir build
cd build
cmake -DENABLE_GRAPHICS=ON ..
cmake --build . --config Release
Android (Termux or NDK)
Build directly on device terminals or via toolchain:

Bash
mkdir build && cd build
cmake -DENABLE_GRAPHICS=ON ..
cmake --build .
Testing the Build
Once compiled, test your build with an E++ source file:

Bash
./eplusplus path/to/script.epp
