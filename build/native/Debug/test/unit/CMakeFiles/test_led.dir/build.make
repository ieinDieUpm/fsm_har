# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /home/josueportiz/Downloads/software/cmake-3.28.0-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/josueportiz/Downloads/software/cmake-3.28.0-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug

# Include any dependencies generated for this target.
include test/unit/CMakeFiles/test_led.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/CMakeFiles/test_led.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/CMakeFiles/test_led.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/CMakeFiles/test_led.dir/flags.make

test/unit/CMakeFiles/test_led.dir/test_led.c.o: test/unit/CMakeFiles/test_led.dir/flags.make
test/unit/CMakeFiles/test_led.dir/test_led.c.o: /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/unit/test_led.c
test/unit/CMakeFiles/test_led.dir/test_led.c.o: test/unit/CMakeFiles/test_led.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/unit/CMakeFiles/test_led.dir/test_led.c.o"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug/test/unit && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/unit/CMakeFiles/test_led.dir/test_led.c.o -MF CMakeFiles/test_led.dir/test_led.c.o.d -o CMakeFiles/test_led.dir/test_led.c.o -c /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/unit/test_led.c

test/unit/CMakeFiles/test_led.dir/test_led.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_led.dir/test_led.c.i"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug/test/unit && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/unit/test_led.c > CMakeFiles/test_led.dir/test_led.c.i

test/unit/CMakeFiles/test_led.dir/test_led.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_led.dir/test_led.c.s"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug/test/unit && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/unit/test_led.c -o CMakeFiles/test_led.dir/test_led.c.s

# Object files for target test_led
test_led_OBJECTS = \
"CMakeFiles/test_led.dir/test_led.c.o"

# External object files for target test_led
test_led_EXTERNAL_OBJECTS =

/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/native/Debug/test_led: test/unit/CMakeFiles/test_led.dir/test_led.c.o
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/native/Debug/test_led: test/unit/CMakeFiles/test_led.dir/build.make
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/native/Debug/test_led: libproject.a
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/native/Debug/test_led: libunity.a
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/native/Debug/test_led: libfsm.a
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/native/Debug/test_led: test/unit/CMakeFiles/test_led.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/native/Debug/test_led"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug/test/unit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_led.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unit/CMakeFiles/test_led.dir/build: /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/native/Debug/test_led
.PHONY : test/unit/CMakeFiles/test_led.dir/build

test/unit/CMakeFiles/test_led.dir/clean:
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug/test/unit && $(CMAKE_COMMAND) -P CMakeFiles/test_led.dir/cmake_clean.cmake
.PHONY : test/unit/CMakeFiles/test_led.dir/clean

test/unit/CMakeFiles/test_led.dir/depend:
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/unit /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug/test/unit /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/native/Debug/test/unit/CMakeFiles/test_led.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/unit/CMakeFiles/test_led.dir/depend
