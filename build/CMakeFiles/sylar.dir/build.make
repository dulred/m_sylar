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
CMAKE_SOURCE_DIR = /home/dulred/sylar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dulred/sylar/build

# Include any dependencies generated for this target.
include CMakeFiles/sylar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sylar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sylar.dir/flags.make

CMakeFiles/sylar.dir/sylar/log.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/log.cc.o: ../sylar/log.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dulred/sylar/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sylar.dir/sylar/log.cc.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/log.cc.o -c /home/dulred/sylar/sylar/log.cc

CMakeFiles/sylar.dir/sylar/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/log.cc.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dulred/sylar/sylar/log.cc > CMakeFiles/sylar.dir/sylar/log.cc.i

CMakeFiles/sylar.dir/sylar/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/log.cc.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dulred/sylar/sylar/log.cc -o CMakeFiles/sylar.dir/sylar/log.cc.s

CMakeFiles/sylar.dir/sylar/log.cc.o.requires:
.PHONY : CMakeFiles/sylar.dir/sylar/log.cc.o.requires

CMakeFiles/sylar.dir/sylar/log.cc.o.provides: CMakeFiles/sylar.dir/sylar/log.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/sylar/log.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/sylar/log.cc.o.provides

CMakeFiles/sylar.dir/sylar/log.cc.o.provides.build: CMakeFiles/sylar.dir/sylar/log.cc.o

CMakeFiles/sylar.dir/sylar/util.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/util.cc.o: ../sylar/util.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dulred/sylar/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sylar.dir/sylar/util.cc.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/util.cc.o -c /home/dulred/sylar/sylar/util.cc

CMakeFiles/sylar.dir/sylar/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/util.cc.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dulred/sylar/sylar/util.cc > CMakeFiles/sylar.dir/sylar/util.cc.i

CMakeFiles/sylar.dir/sylar/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/util.cc.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dulred/sylar/sylar/util.cc -o CMakeFiles/sylar.dir/sylar/util.cc.s

CMakeFiles/sylar.dir/sylar/util.cc.o.requires:
.PHONY : CMakeFiles/sylar.dir/sylar/util.cc.o.requires

CMakeFiles/sylar.dir/sylar/util.cc.o.provides: CMakeFiles/sylar.dir/sylar/util.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/sylar/util.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/sylar/util.cc.o.provides

CMakeFiles/sylar.dir/sylar/util.cc.o.provides.build: CMakeFiles/sylar.dir/sylar/util.cc.o

CMakeFiles/sylar.dir/sylar/config.cc.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/config.cc.o: ../sylar/config.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dulred/sylar/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sylar.dir/sylar/config.cc.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/config.cc.o -c /home/dulred/sylar/sylar/config.cc

CMakeFiles/sylar.dir/sylar/config.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/config.cc.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dulred/sylar/sylar/config.cc > CMakeFiles/sylar.dir/sylar/config.cc.i

CMakeFiles/sylar.dir/sylar/config.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/config.cc.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dulred/sylar/sylar/config.cc -o CMakeFiles/sylar.dir/sylar/config.cc.s

CMakeFiles/sylar.dir/sylar/config.cc.o.requires:
.PHONY : CMakeFiles/sylar.dir/sylar/config.cc.o.requires

CMakeFiles/sylar.dir/sylar/config.cc.o.provides: CMakeFiles/sylar.dir/sylar/config.cc.o.requires
	$(MAKE) -f CMakeFiles/sylar.dir/build.make CMakeFiles/sylar.dir/sylar/config.cc.o.provides.build
.PHONY : CMakeFiles/sylar.dir/sylar/config.cc.o.provides

CMakeFiles/sylar.dir/sylar/config.cc.o.provides.build: CMakeFiles/sylar.dir/sylar/config.cc.o

# Object files for target sylar
sylar_OBJECTS = \
"CMakeFiles/sylar.dir/sylar/log.cc.o" \
"CMakeFiles/sylar.dir/sylar/util.cc.o" \
"CMakeFiles/sylar.dir/sylar/config.cc.o"

# External object files for target sylar
sylar_EXTERNAL_OBJECTS =

../bin/libsylar.so: CMakeFiles/sylar.dir/sylar/log.cc.o
../bin/libsylar.so: CMakeFiles/sylar.dir/sylar/util.cc.o
../bin/libsylar.so: CMakeFiles/sylar.dir/sylar/config.cc.o
../bin/libsylar.so: CMakeFiles/sylar.dir/build.make
../bin/libsylar.so: CMakeFiles/sylar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../bin/libsylar.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sylar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sylar.dir/build: ../bin/libsylar.so
.PHONY : CMakeFiles/sylar.dir/build

CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/sylar/log.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/sylar/util.cc.o.requires
CMakeFiles/sylar.dir/requires: CMakeFiles/sylar.dir/sylar/config.cc.o.requires
.PHONY : CMakeFiles/sylar.dir/requires

CMakeFiles/sylar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sylar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sylar.dir/clean

CMakeFiles/sylar.dir/depend:
	cd /home/dulred/sylar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dulred/sylar /home/dulred/sylar /home/dulred/sylar/build /home/dulred/sylar/build /home/dulred/sylar/build/CMakeFiles/sylar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sylar.dir/depend

