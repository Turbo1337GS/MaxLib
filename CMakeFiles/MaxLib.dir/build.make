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
CMAKE_SOURCE_DIR = /home/turbo/Pulpit/github/MaxLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/turbo/Pulpit/github/MaxLib

# Include any dependencies generated for this target.
include CMakeFiles/MaxLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MaxLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MaxLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MaxLib.dir/flags.make

CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.o: CMakeFiles/MaxLib.dir/flags.make
CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.o: src/GiString/GiString.cpp
CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.o: CMakeFiles/MaxLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/turbo/Pulpit/github/MaxLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.o -MF CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.o.d -o CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.o -c /home/turbo/Pulpit/github/MaxLib/src/GiString/GiString.cpp

CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turbo/Pulpit/github/MaxLib/src/GiString/GiString.cpp > CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.i

CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turbo/Pulpit/github/MaxLib/src/GiString/GiString.cpp -o CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.s

CMakeFiles/MaxLib.dir/src/demo.cpp.o: CMakeFiles/MaxLib.dir/flags.make
CMakeFiles/MaxLib.dir/src/demo.cpp.o: src/demo.cpp
CMakeFiles/MaxLib.dir/src/demo.cpp.o: CMakeFiles/MaxLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/turbo/Pulpit/github/MaxLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MaxLib.dir/src/demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MaxLib.dir/src/demo.cpp.o -MF CMakeFiles/MaxLib.dir/src/demo.cpp.o.d -o CMakeFiles/MaxLib.dir/src/demo.cpp.o -c /home/turbo/Pulpit/github/MaxLib/src/demo.cpp

CMakeFiles/MaxLib.dir/src/demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MaxLib.dir/src/demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turbo/Pulpit/github/MaxLib/src/demo.cpp > CMakeFiles/MaxLib.dir/src/demo.cpp.i

CMakeFiles/MaxLib.dir/src/demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MaxLib.dir/src/demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turbo/Pulpit/github/MaxLib/src/demo.cpp -o CMakeFiles/MaxLib.dir/src/demo.cpp.s

# Object files for target MaxLib
MaxLib_OBJECTS = \
"CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.o" \
"CMakeFiles/MaxLib.dir/src/demo.cpp.o"

# External object files for target MaxLib
MaxLib_EXTERNAL_OBJECTS =

bin/MaxLib: CMakeFiles/MaxLib.dir/src/GiString/GiString.cpp.o
bin/MaxLib: CMakeFiles/MaxLib.dir/src/demo.cpp.o
bin/MaxLib: CMakeFiles/MaxLib.dir/build.make
bin/MaxLib: CMakeFiles/MaxLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/turbo/Pulpit/github/MaxLib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/MaxLib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MaxLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MaxLib.dir/build: bin/MaxLib
.PHONY : CMakeFiles/MaxLib.dir/build

CMakeFiles/MaxLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MaxLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MaxLib.dir/clean

CMakeFiles/MaxLib.dir/depend:
	cd /home/turbo/Pulpit/github/MaxLib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/turbo/Pulpit/github/MaxLib /home/turbo/Pulpit/github/MaxLib /home/turbo/Pulpit/github/MaxLib /home/turbo/Pulpit/github/MaxLib /home/turbo/Pulpit/github/MaxLib/CMakeFiles/MaxLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MaxLib.dir/depend
