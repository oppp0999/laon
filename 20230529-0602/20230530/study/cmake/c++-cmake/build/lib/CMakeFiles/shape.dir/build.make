# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/shape.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/shape.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/shape.dir/flags.make

lib/CMakeFiles/shape.dir/shape.cc.o: lib/CMakeFiles/shape.dir/flags.make
lib/CMakeFiles/shape.dir/shape.cc.o: ../lib/shape.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/shape.dir/shape.cc.o"
	cd /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shape.dir/shape.cc.o -c /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/lib/shape.cc

lib/CMakeFiles/shape.dir/shape.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shape.dir/shape.cc.i"
	cd /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/lib/shape.cc > CMakeFiles/shape.dir/shape.cc.i

lib/CMakeFiles/shape.dir/shape.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shape.dir/shape.cc.s"
	cd /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/lib/shape.cc -o CMakeFiles/shape.dir/shape.cc.s

# Object files for target shape
shape_OBJECTS = \
"CMakeFiles/shape.dir/shape.cc.o"

# External object files for target shape
shape_EXTERNAL_OBJECTS =

lib/libshape.a: lib/CMakeFiles/shape.dir/shape.cc.o
lib/libshape.a: lib/CMakeFiles/shape.dir/build.make
lib/libshape.a: lib/CMakeFiles/shape.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libshape.a"
	cd /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/shape.dir/cmake_clean_target.cmake
	cd /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shape.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/shape.dir/build: lib/libshape.a

.PHONY : lib/CMakeFiles/shape.dir/build

lib/CMakeFiles/shape.dir/clean:
	cd /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/shape.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/shape.dir/clean

lib/CMakeFiles/shape.dir/depend:
	cd /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/lib /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/lib /home/hjkim/laon/20230529-0602/20230530/study/cmake/c++-cmake/build/lib/CMakeFiles/shape.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/shape.dir/depend

