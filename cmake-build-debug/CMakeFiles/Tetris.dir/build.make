# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\CLion Project\Tetris"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\CLion Project\Tetris\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Tetris.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tetris.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tetris.dir/flags.make

CMakeFiles/Tetris.dir/main.c.obj: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/main.c.obj: ../main.c
CMakeFiles/Tetris.dir/main.c.obj: CMakeFiles/Tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CLion Project\Tetris\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Tetris.dir/main.c.obj"
	D:\Program_Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Tetris.dir/main.c.obj -MF CMakeFiles\Tetris.dir\main.c.obj.d -o CMakeFiles\Tetris.dir\main.c.obj -c "D:\CLion Project\Tetris\main.c"

CMakeFiles/Tetris.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tetris.dir/main.c.i"
	D:\Program_Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\CLion Project\Tetris\main.c" > CMakeFiles\Tetris.dir\main.c.i

CMakeFiles/Tetris.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tetris.dir/main.c.s"
	D:\Program_Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\CLion Project\Tetris\main.c" -o CMakeFiles\Tetris.dir\main.c.s

CMakeFiles/Tetris.dir/tetris.c.obj: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/tetris.c.obj: ../tetris.c
CMakeFiles/Tetris.dir/tetris.c.obj: CMakeFiles/Tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CLion Project\Tetris\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Tetris.dir/tetris.c.obj"
	D:\Program_Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Tetris.dir/tetris.c.obj -MF CMakeFiles\Tetris.dir\tetris.c.obj.d -o CMakeFiles\Tetris.dir\tetris.c.obj -c "D:\CLion Project\Tetris\tetris.c"

CMakeFiles/Tetris.dir/tetris.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tetris.dir/tetris.c.i"
	D:\Program_Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\CLion Project\Tetris\tetris.c" > CMakeFiles\Tetris.dir\tetris.c.i

CMakeFiles/Tetris.dir/tetris.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tetris.dir/tetris.c.s"
	D:\Program_Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\CLion Project\Tetris\tetris.c" -o CMakeFiles\Tetris.dir\tetris.c.s

# Object files for target Tetris
Tetris_OBJECTS = \
"CMakeFiles/Tetris.dir/main.c.obj" \
"CMakeFiles/Tetris.dir/tetris.c.obj"

# External object files for target Tetris
Tetris_EXTERNAL_OBJECTS =

Tetris.exe: CMakeFiles/Tetris.dir/main.c.obj
Tetris.exe: CMakeFiles/Tetris.dir/tetris.c.obj
Tetris.exe: CMakeFiles/Tetris.dir/build.make
Tetris.exe: CMakeFiles/Tetris.dir/linklibs.rsp
Tetris.exe: CMakeFiles/Tetris.dir/objects1.rsp
Tetris.exe: CMakeFiles/Tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\CLion Project\Tetris\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Tetris.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tetris.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tetris.dir/build: Tetris.exe
.PHONY : CMakeFiles/Tetris.dir/build

CMakeFiles/Tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tetris.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tetris.dir/clean

CMakeFiles/Tetris.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\CLion Project\Tetris" "D:\CLion Project\Tetris" "D:\CLion Project\Tetris\cmake-build-debug" "D:\CLion Project\Tetris\cmake-build-debug" "D:\CLion Project\Tetris\cmake-build-debug\CMakeFiles\Tetris.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Tetris.dir/depend
