# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tylerdurden/CLionProjects/T16T1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tylerdurden/CLionProjects/T16T1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/T16T1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/T16T1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/T16T1.dir/flags.make

CMakeFiles/T16T1.dir/main.cpp.o: CMakeFiles/T16T1.dir/flags.make
CMakeFiles/T16T1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tylerdurden/CLionProjects/T16T1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/T16T1.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/T16T1.dir/main.cpp.o -c /Users/tylerdurden/CLionProjects/T16T1/main.cpp

CMakeFiles/T16T1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/T16T1.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tylerdurden/CLionProjects/T16T1/main.cpp > CMakeFiles/T16T1.dir/main.cpp.i

CMakeFiles/T16T1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/T16T1.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tylerdurden/CLionProjects/T16T1/main.cpp -o CMakeFiles/T16T1.dir/main.cpp.s

# Object files for target T16T1
T16T1_OBJECTS = \
"CMakeFiles/T16T1.dir/main.cpp.o"

# External object files for target T16T1
T16T1_EXTERNAL_OBJECTS =

T16T1: CMakeFiles/T16T1.dir/main.cpp.o
T16T1: CMakeFiles/T16T1.dir/build.make
T16T1: CMakeFiles/T16T1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tylerdurden/CLionProjects/T16T1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable T16T1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/T16T1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/T16T1.dir/build: T16T1
.PHONY : CMakeFiles/T16T1.dir/build

CMakeFiles/T16T1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/T16T1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/T16T1.dir/clean

CMakeFiles/T16T1.dir/depend:
	cd /Users/tylerdurden/CLionProjects/T16T1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tylerdurden/CLionProjects/T16T1 /Users/tylerdurden/CLionProjects/T16T1 /Users/tylerdurden/CLionProjects/T16T1/cmake-build-debug /Users/tylerdurden/CLionProjects/T16T1/cmake-build-debug /Users/tylerdurden/CLionProjects/T16T1/cmake-build-debug/CMakeFiles/T16T1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/T16T1.dir/depend
