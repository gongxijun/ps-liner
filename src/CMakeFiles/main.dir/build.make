# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sina/github/liner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sina/github/liner

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/datamain.cc.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/datamain.cc.o: src/datamain.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sina/github/liner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/main.dir/datamain.cc.o"
	cd /Users/sina/github/liner/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/datamain.cc.o -c /Users/sina/github/liner/src/datamain.cc

src/CMakeFiles/main.dir/datamain.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/datamain.cc.i"
	cd /Users/sina/github/liner/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sina/github/liner/src/datamain.cc > CMakeFiles/main.dir/datamain.cc.i

src/CMakeFiles/main.dir/datamain.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/datamain.cc.s"
	cd /Users/sina/github/liner/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sina/github/liner/src/datamain.cc -o CMakeFiles/main.dir/datamain.cc.s

src/CMakeFiles/main.dir/datamain.cc.o.requires:

.PHONY : src/CMakeFiles/main.dir/datamain.cc.o.requires

src/CMakeFiles/main.dir/datamain.cc.o.provides: src/CMakeFiles/main.dir/datamain.cc.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/datamain.cc.o.provides.build
.PHONY : src/CMakeFiles/main.dir/datamain.cc.o.provides

src/CMakeFiles/main.dir/datamain.cc.o.provides.build: src/CMakeFiles/main.dir/datamain.cc.o


src/CMakeFiles/main.dir/murmur_hash3.cc.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/murmur_hash3.cc.o: src/murmur_hash3.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sina/github/liner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/main.dir/murmur_hash3.cc.o"
	cd /Users/sina/github/liner/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/murmur_hash3.cc.o -c /Users/sina/github/liner/src/murmur_hash3.cc

src/CMakeFiles/main.dir/murmur_hash3.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/murmur_hash3.cc.i"
	cd /Users/sina/github/liner/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sina/github/liner/src/murmur_hash3.cc > CMakeFiles/main.dir/murmur_hash3.cc.i

src/CMakeFiles/main.dir/murmur_hash3.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/murmur_hash3.cc.s"
	cd /Users/sina/github/liner/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sina/github/liner/src/murmur_hash3.cc -o CMakeFiles/main.dir/murmur_hash3.cc.s

src/CMakeFiles/main.dir/murmur_hash3.cc.o.requires:

.PHONY : src/CMakeFiles/main.dir/murmur_hash3.cc.o.requires

src/CMakeFiles/main.dir/murmur_hash3.cc.o.provides: src/CMakeFiles/main.dir/murmur_hash3.cc.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/murmur_hash3.cc.o.provides.build
.PHONY : src/CMakeFiles/main.dir/murmur_hash3.cc.o.provides

src/CMakeFiles/main.dir/murmur_hash3.cc.o.provides.build: src/CMakeFiles/main.dir/murmur_hash3.cc.o


src/CMakeFiles/main.dir/trainliner.cc.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/trainliner.cc.o: src/trainliner.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sina/github/liner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/main.dir/trainliner.cc.o"
	cd /Users/sina/github/liner/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/trainliner.cc.o -c /Users/sina/github/liner/src/trainliner.cc

src/CMakeFiles/main.dir/trainliner.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/trainliner.cc.i"
	cd /Users/sina/github/liner/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sina/github/liner/src/trainliner.cc > CMakeFiles/main.dir/trainliner.cc.i

src/CMakeFiles/main.dir/trainliner.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/trainliner.cc.s"
	cd /Users/sina/github/liner/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sina/github/liner/src/trainliner.cc -o CMakeFiles/main.dir/trainliner.cc.s

src/CMakeFiles/main.dir/trainliner.cc.o.requires:

.PHONY : src/CMakeFiles/main.dir/trainliner.cc.o.requires

src/CMakeFiles/main.dir/trainliner.cc.o.provides: src/CMakeFiles/main.dir/trainliner.cc.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/trainliner.cc.o.provides.build
.PHONY : src/CMakeFiles/main.dir/trainliner.cc.o.provides

src/CMakeFiles/main.dir/trainliner.cc.o.provides.build: src/CMakeFiles/main.dir/trainliner.cc.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/datamain.cc.o" \
"CMakeFiles/main.dir/murmur_hash3.cc.o" \
"CMakeFiles/main.dir/trainliner.cc.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

bin/main: src/CMakeFiles/main.dir/datamain.cc.o
bin/main: src/CMakeFiles/main.dir/murmur_hash3.cc.o
bin/main: src/CMakeFiles/main.dir/trainliner.cc.o
bin/main: src/CMakeFiles/main.dir/build.make
bin/main: /usr/local/lib/libzmq.dylib
bin/main: ps-lite/libpslite.a
bin/main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sina/github/liner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/main"
	cd /Users/sina/github/liner/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: bin/main

.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/datamain.cc.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/murmur_hash3.cc.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/trainliner.cc.o.requires

.PHONY : src/CMakeFiles/main.dir/requires

src/CMakeFiles/main.dir/clean:
	cd /Users/sina/github/liner/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /Users/sina/github/liner && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sina/github/liner /Users/sina/github/liner/src /Users/sina/github/liner /Users/sina/github/liner/src /Users/sina/github/liner/src/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/main.dir/depend

