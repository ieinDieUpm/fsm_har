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
CMAKE_BINARY_DIR = /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug

# Include any dependencies generated for this target.
include test/integration/CMakeFiles/test_blink.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/integration/CMakeFiles/test_blink.dir/compiler_depend.make

# Include the progress variables for this target.
include test/integration/CMakeFiles/test_blink.dir/progress.make

# Include the compile flags for this target's objects.
include test/integration/CMakeFiles/test_blink.dir/flags.make

test/integration/CMakeFiles/test_blink.dir/test_blink.c.obj: test/integration/CMakeFiles/test_blink.dir/flags.make
test/integration/CMakeFiles/test_blink.dir/test_blink.c.obj: /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/integration/test_blink.c
test/integration/CMakeFiles/test_blink.dir/test_blink.c.obj: test/integration/CMakeFiles/test_blink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/integration/CMakeFiles/test_blink.dir/test_blink.c.obj"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/integration/CMakeFiles/test_blink.dir/test_blink.c.obj -MF CMakeFiles/test_blink.dir/test_blink.c.obj.d -o CMakeFiles/test_blink.dir/test_blink.c.obj -c /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/integration/test_blink.c

test/integration/CMakeFiles/test_blink.dir/test_blink.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_blink.dir/test_blink.c.i"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/integration/test_blink.c > CMakeFiles/test_blink.dir/test_blink.c.i

test/integration/CMakeFiles/test_blink.dir/test_blink.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_blink.dir/test_blink.c.s"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/integration/test_blink.c -o CMakeFiles/test_blink.dir/test_blink.c.s

test/integration/CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.obj: test/integration/CMakeFiles/test_blink.dir/flags.make
test/integration/CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.obj: /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/port/stm32f4/src/interr.c
test/integration/CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.obj: test/integration/CMakeFiles/test_blink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object test/integration/CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.obj"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/integration/CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.obj -MF CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.obj.d -o CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.obj -c /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/port/stm32f4/src/interr.c

test/integration/CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.i"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/port/stm32f4/src/interr.c > CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.i

test/integration/CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.s"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/port/stm32f4/src/interr.c -o CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.s

# Object files for target test_blink
test_blink_OBJECTS = \
"CMakeFiles/test_blink.dir/test_blink.c.obj" \
"CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.obj"

# External object files for target test_blink
test_blink_EXTERNAL_OBJECTS =

/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf: test/integration/CMakeFiles/test_blink.dir/test_blink.c.obj
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf: test/integration/CMakeFiles/test_blink.dir/__/__/port/stm32f4/src/interr.c.obj
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf: test/integration/CMakeFiles/test_blink.dir/build.make
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf: libplatform.a
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf: libproject.a
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf: libfsm.a
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf: libplatform.a
/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf: test/integration/CMakeFiles/test_blink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf"
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_blink.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/integration/CMakeFiles/test_blink.dir/build: /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/bin/stm32f446re/Debug/test_blink.elf
.PHONY : test/integration/CMakeFiles/test_blink.dir/build

test/integration/CMakeFiles/test_blink.dir/clean:
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration && $(CMAKE_COMMAND) -P CMakeFiles/test_blink.dir/cmake_clean.cmake
.PHONY : test/integration/CMakeFiles/test_blink.dir/clean

test/integration/CMakeFiles/test_blink.dir/depend:
	cd /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/test/integration /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration /home/josueportiz/entornos/iein/MatrixMCU/projects/fsm_har_private/build/stm32f446re/Debug/test/integration/CMakeFiles/test_blink.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/integration/CMakeFiles/test_blink.dir/depend

