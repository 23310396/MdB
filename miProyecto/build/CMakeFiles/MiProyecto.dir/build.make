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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/MdB/miProyecto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/MdB/miProyecto/build

# Include any dependencies generated for this target.
include CMakeFiles/MiProyecto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MiProyecto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MiProyecto.dir/flags.make

CMakeFiles/MiProyecto.dir/src/main.cpp.o: CMakeFiles/MiProyecto.dir/flags.make
CMakeFiles/MiProyecto.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/MdB/miProyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MiProyecto.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiProyecto.dir/src/main.cpp.o -c /workspaces/MdB/miProyecto/src/main.cpp

CMakeFiles/MiProyecto.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiProyecto.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/MdB/miProyecto/src/main.cpp > CMakeFiles/MiProyecto.dir/src/main.cpp.i

CMakeFiles/MiProyecto.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiProyecto.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/MdB/miProyecto/src/main.cpp -o CMakeFiles/MiProyecto.dir/src/main.cpp.s

# Object files for target MiProyecto
MiProyecto_OBJECTS = \
"CMakeFiles/MiProyecto.dir/src/main.cpp.o"

# External object files for target MiProyecto
MiProyecto_EXTERNAL_OBJECTS =

MiProyecto: CMakeFiles/MiProyecto.dir/src/main.cpp.o
MiProyecto: CMakeFiles/MiProyecto.dir/build.make
MiProyecto: CMakeFiles/MiProyecto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/MdB/miProyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MiProyecto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MiProyecto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MiProyecto.dir/build: MiProyecto

.PHONY : CMakeFiles/MiProyecto.dir/build

CMakeFiles/MiProyecto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MiProyecto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MiProyecto.dir/clean

CMakeFiles/MiProyecto.dir/depend:
	cd /workspaces/MdB/miProyecto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/MdB/miProyecto /workspaces/MdB/miProyecto /workspaces/MdB/miProyecto/build /workspaces/MdB/miProyecto/build /workspaces/MdB/miProyecto/build/CMakeFiles/MiProyecto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MiProyecto.dir/depend

