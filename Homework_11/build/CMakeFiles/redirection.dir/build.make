# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arsen/Homeworks_linux/Homework_11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arsen/Homeworks_linux/Homework_11/build

# Include any dependencies generated for this target.
include CMakeFiles/redirection.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/redirection.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/redirection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/redirection.dir/flags.make

CMakeFiles/redirection.dir/redirection.cpp.o: CMakeFiles/redirection.dir/flags.make
CMakeFiles/redirection.dir/redirection.cpp.o: ../redirection.cpp
CMakeFiles/redirection.dir/redirection.cpp.o: CMakeFiles/redirection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arsen/Homeworks_linux/Homework_11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/redirection.dir/redirection.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/redirection.dir/redirection.cpp.o -MF CMakeFiles/redirection.dir/redirection.cpp.o.d -o CMakeFiles/redirection.dir/redirection.cpp.o -c /home/arsen/Homeworks_linux/Homework_11/redirection.cpp

CMakeFiles/redirection.dir/redirection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redirection.dir/redirection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arsen/Homeworks_linux/Homework_11/redirection.cpp > CMakeFiles/redirection.dir/redirection.cpp.i

CMakeFiles/redirection.dir/redirection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redirection.dir/redirection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arsen/Homeworks_linux/Homework_11/redirection.cpp -o CMakeFiles/redirection.dir/redirection.cpp.s

# Object files for target redirection
redirection_OBJECTS = \
"CMakeFiles/redirection.dir/redirection.cpp.o"

# External object files for target redirection
redirection_EXTERNAL_OBJECTS =

redirection: CMakeFiles/redirection.dir/redirection.cpp.o
redirection: CMakeFiles/redirection.dir/build.make
redirection: CMakeFiles/redirection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arsen/Homeworks_linux/Homework_11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable redirection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/redirection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/redirection.dir/build: redirection
.PHONY : CMakeFiles/redirection.dir/build

CMakeFiles/redirection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/redirection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/redirection.dir/clean

CMakeFiles/redirection.dir/depend:
	cd /home/arsen/Homeworks_linux/Homework_11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arsen/Homeworks_linux/Homework_11 /home/arsen/Homeworks_linux/Homework_11 /home/arsen/Homeworks_linux/Homework_11/build /home/arsen/Homeworks_linux/Homework_11/build /home/arsen/Homeworks_linux/Homework_11/build/CMakeFiles/redirection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/redirection.dir/depend

