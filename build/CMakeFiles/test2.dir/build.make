# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dulred/project/m_sylar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dulred/project/m_sylar/build

# Include any dependencies generated for this target.
include CMakeFiles/test2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test2.dir/flags.make

CMakeFiles/test2.dir/tests/test2.cc.o: CMakeFiles/test2.dir/flags.make
CMakeFiles/test2.dir/tests/test2.cc.o: ../tests/test2.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dulred/project/m_sylar/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test2.dir/tests/test2.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/tests/test2.cc.o -c /home/dulred/project/m_sylar/tests/test2.cc

CMakeFiles/test2.dir/tests/test2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/tests/test2.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dulred/project/m_sylar/tests/test2.cc > CMakeFiles/test2.dir/tests/test2.cc.i

CMakeFiles/test2.dir/tests/test2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/tests/test2.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dulred/project/m_sylar/tests/test2.cc -o CMakeFiles/test2.dir/tests/test2.cc.s

CMakeFiles/test2.dir/tests/test2.cc.o.requires:
.PHONY : CMakeFiles/test2.dir/tests/test2.cc.o.requires

CMakeFiles/test2.dir/tests/test2.cc.o.provides: CMakeFiles/test2.dir/tests/test2.cc.o.requires
	$(MAKE) -f CMakeFiles/test2.dir/build.make CMakeFiles/test2.dir/tests/test2.cc.o.provides.build
.PHONY : CMakeFiles/test2.dir/tests/test2.cc.o.provides

CMakeFiles/test2.dir/tests/test2.cc.o.provides.build: CMakeFiles/test2.dir/tests/test2.cc.o

# Object files for target test2
test2_OBJECTS = \
"CMakeFiles/test2.dir/tests/test2.cc.o"

# External object files for target test2
test2_EXTERNAL_OBJECTS =

../bin/test2: CMakeFiles/test2.dir/tests/test2.cc.o
../bin/test2: CMakeFiles/test2.dir/build.make
../bin/test2: ../bin/libsylar.so
../bin/test2: CMakeFiles/test2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/test2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test2.dir/build: ../bin/test2
.PHONY : CMakeFiles/test2.dir/build

CMakeFiles/test2.dir/requires: CMakeFiles/test2.dir/tests/test2.cc.o.requires
.PHONY : CMakeFiles/test2.dir/requires

CMakeFiles/test2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test2.dir/clean

CMakeFiles/test2.dir/depend:
	cd /home/dulred/project/m_sylar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dulred/project/m_sylar /home/dulred/project/m_sylar /home/dulred/project/m_sylar/build /home/dulred/project/m_sylar/build /home/dulred/project/m_sylar/build/CMakeFiles/test2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test2.dir/depend

