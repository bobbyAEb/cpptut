# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wen/slam/cpptut/lec3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wen/slam/cpptut/lec3/build

# Include any dependencies generated for this target.
include src/CMakeFiles/bin_main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/bin_main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/bin_main.dir/flags.make

src/CMakeFiles/bin_main.dir/test.cpp.o: src/CMakeFiles/bin_main.dir/flags.make
src/CMakeFiles/bin_main.dir/test.cpp.o: ../src/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wen/slam/cpptut/lec3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/bin_main.dir/test.cpp.o"
	cd /Users/wen/slam/cpptut/lec3/build/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bin_main.dir/test.cpp.o -c /Users/wen/slam/cpptut/lec3/src/test.cpp

src/CMakeFiles/bin_main.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bin_main.dir/test.cpp.i"
	cd /Users/wen/slam/cpptut/lec3/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wen/slam/cpptut/lec3/src/test.cpp > CMakeFiles/bin_main.dir/test.cpp.i

src/CMakeFiles/bin_main.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bin_main.dir/test.cpp.s"
	cd /Users/wen/slam/cpptut/lec3/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wen/slam/cpptut/lec3/src/test.cpp -o CMakeFiles/bin_main.dir/test.cpp.s

# Object files for target bin_main
bin_main_OBJECTS = \
"CMakeFiles/bin_main.dir/test.cpp.o"

# External object files for target bin_main
bin_main_EXTERNAL_OBJECTS =

src/bin_main: src/CMakeFiles/bin_main.dir/test.cpp.o
src/bin_main: src/CMakeFiles/bin_main.dir/build.make
src/bin_main: src/CMakeFiles/bin_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wen/slam/cpptut/lec3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin_main"
	cd /Users/wen/slam/cpptut/lec3/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bin_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/bin_main.dir/build: src/bin_main

.PHONY : src/CMakeFiles/bin_main.dir/build

src/CMakeFiles/bin_main.dir/clean:
	cd /Users/wen/slam/cpptut/lec3/build/src && $(CMAKE_COMMAND) -P CMakeFiles/bin_main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/bin_main.dir/clean

src/CMakeFiles/bin_main.dir/depend:
	cd /Users/wen/slam/cpptut/lec3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wen/slam/cpptut/lec3 /Users/wen/slam/cpptut/lec3/src /Users/wen/slam/cpptut/lec3/build /Users/wen/slam/cpptut/lec3/build/src /Users/wen/slam/cpptut/lec3/build/src/CMakeFiles/bin_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/bin_main.dir/depend
