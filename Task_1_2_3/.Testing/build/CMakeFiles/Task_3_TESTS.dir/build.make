# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /snap/cmake/1433/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1433/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/build

# Include any dependencies generated for this target.
include CMakeFiles/Task_3_TESTS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Task_3_TESTS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Task_3_TESTS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_3_TESTS.dir/flags.make

CMakeFiles/Task_3_TESTS.dir/codegen:
.PHONY : CMakeFiles/Task_3_TESTS.dir/codegen

CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.o: CMakeFiles/Task_3_TESTS.dir/flags.make
CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.o: /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/Task_3_TESTS.cpp
CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.o: CMakeFiles/Task_3_TESTS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.o -MF CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.o.d -o CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.o -c /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/Task_3_TESTS.cpp

CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/Task_3_TESTS.cpp > CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.i

CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/Task_3_TESTS.cpp -o CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.s

# Object files for target Task_3_TESTS
Task_3_TESTS_OBJECTS = \
"CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.o"

# External object files for target Task_3_TESTS
Task_3_TESTS_EXTERNAL_OBJECTS =

Task_3_TESTS: CMakeFiles/Task_3_TESTS.dir/Task_3_TESTS.cpp.o
Task_3_TESTS: CMakeFiles/Task_3_TESTS.dir/build.make
Task_3_TESTS: CMakeFiles/Task_3_TESTS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_3_TESTS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task_3_TESTS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_3_TESTS.dir/build: Task_3_TESTS
.PHONY : CMakeFiles/Task_3_TESTS.dir/build

CMakeFiles/Task_3_TESTS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task_3_TESTS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task_3_TESTS.dir/clean

CMakeFiles/Task_3_TESTS.dir/depend:
	cd /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/build /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/build /home/anton/LABS/453501/ОАиП/LR6/Task_1_2_3/.Testing/build/CMakeFiles/Task_3_TESTS.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Task_3_TESTS.dir/depend
