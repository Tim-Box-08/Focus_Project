# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ttoto\CLionProjects\Focus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ttoto\CLionProjects\Focus\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Focus.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Focus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Focus.dir/flags.make

CMakeFiles/Focus.dir/main.c.obj: CMakeFiles/Focus.dir/flags.make
CMakeFiles/Focus.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ttoto\CLionProjects\Focus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Focus.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Focus.dir\main.c.obj   -c C:\Users\ttoto\CLionProjects\Focus\main.c

CMakeFiles/Focus.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Focus.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ttoto\CLionProjects\Focus\main.c > CMakeFiles\Focus.dir\main.c.i

CMakeFiles/Focus.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Focus.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ttoto\CLionProjects\Focus\main.c -o CMakeFiles\Focus.dir\main.c.s

CMakeFiles/Focus.dir/input_output.c.obj: CMakeFiles/Focus.dir/flags.make
CMakeFiles/Focus.dir/input_output.c.obj: ../input_output.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ttoto\CLionProjects\Focus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Focus.dir/input_output.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Focus.dir\input_output.c.obj   -c C:\Users\ttoto\CLionProjects\Focus\input_output.c

CMakeFiles/Focus.dir/input_output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Focus.dir/input_output.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ttoto\CLionProjects\Focus\input_output.c > CMakeFiles\Focus.dir\input_output.c.i

CMakeFiles/Focus.dir/input_output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Focus.dir/input_output.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ttoto\CLionProjects\Focus\input_output.c -o CMakeFiles\Focus.dir\input_output.c.s

CMakeFiles/Focus.dir/game_init.c.obj: CMakeFiles/Focus.dir/flags.make
CMakeFiles/Focus.dir/game_init.c.obj: ../game_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ttoto\CLionProjects\Focus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Focus.dir/game_init.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Focus.dir\game_init.c.obj   -c C:\Users\ttoto\CLionProjects\Focus\game_init.c

CMakeFiles/Focus.dir/game_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Focus.dir/game_init.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ttoto\CLionProjects\Focus\game_init.c > CMakeFiles\Focus.dir\game_init.c.i

CMakeFiles/Focus.dir/game_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Focus.dir/game_init.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ttoto\CLionProjects\Focus\game_init.c -o CMakeFiles\Focus.dir\game_init.c.s

CMakeFiles/Focus.dir/turn.c.obj: CMakeFiles/Focus.dir/flags.make
CMakeFiles/Focus.dir/turn.c.obj: ../turn.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ttoto\CLionProjects\Focus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Focus.dir/turn.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Focus.dir\turn.c.obj   -c C:\Users\ttoto\CLionProjects\Focus\turn.c

CMakeFiles/Focus.dir/turn.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Focus.dir/turn.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ttoto\CLionProjects\Focus\turn.c > CMakeFiles\Focus.dir\turn.c.i

CMakeFiles/Focus.dir/turn.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Focus.dir/turn.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ttoto\CLionProjects\Focus\turn.c -o CMakeFiles\Focus.dir\turn.c.s

# Object files for target Focus
Focus_OBJECTS = \
"CMakeFiles/Focus.dir/main.c.obj" \
"CMakeFiles/Focus.dir/input_output.c.obj" \
"CMakeFiles/Focus.dir/game_init.c.obj" \
"CMakeFiles/Focus.dir/turn.c.obj"

# External object files for target Focus
Focus_EXTERNAL_OBJECTS =

Focus.exe: CMakeFiles/Focus.dir/main.c.obj
Focus.exe: CMakeFiles/Focus.dir/input_output.c.obj
Focus.exe: CMakeFiles/Focus.dir/game_init.c.obj
Focus.exe: CMakeFiles/Focus.dir/turn.c.obj
Focus.exe: CMakeFiles/Focus.dir/build.make
Focus.exe: CMakeFiles/Focus.dir/linklibs.rsp
Focus.exe: CMakeFiles/Focus.dir/objects1.rsp
Focus.exe: CMakeFiles/Focus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ttoto\CLionProjects\Focus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Focus.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Focus.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Focus.dir/build: Focus.exe

.PHONY : CMakeFiles/Focus.dir/build

CMakeFiles/Focus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Focus.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Focus.dir/clean

CMakeFiles/Focus.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ttoto\CLionProjects\Focus C:\Users\ttoto\CLionProjects\Focus C:\Users\ttoto\CLionProjects\Focus\cmake-build-debug C:\Users\ttoto\CLionProjects\Focus\cmake-build-debug C:\Users\ttoto\CLionProjects\Focus\cmake-build-debug\CMakeFiles\Focus.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Focus.dir/depend

