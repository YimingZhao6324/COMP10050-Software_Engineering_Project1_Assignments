# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/Makos/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Makos/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Makos/Desktop/Assignment3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Makos/Desktop/Assignment3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment3.dir/flags.make

CMakeFiles/Assignment3.dir/main.c.o: CMakeFiles/Assignment3.dir/flags.make
CMakeFiles/Assignment3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Makos/Desktop/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Assignment3.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment3.dir/main.c.o   -c /cygdrive/c/Users/Makos/Desktop/Assignment3/main.c

CMakeFiles/Assignment3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment3.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Makos/Desktop/Assignment3/main.c > CMakeFiles/Assignment3.dir/main.c.i

CMakeFiles/Assignment3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment3.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Makos/Desktop/Assignment3/main.c -o CMakeFiles/Assignment3.dir/main.c.s

CMakeFiles/Assignment3.dir/avg_and_max.c.o: CMakeFiles/Assignment3.dir/flags.make
CMakeFiles/Assignment3.dir/avg_and_max.c.o: ../avg_and_max.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Makos/Desktop/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Assignment3.dir/avg_and_max.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment3.dir/avg_and_max.c.o   -c /cygdrive/c/Users/Makos/Desktop/Assignment3/avg_and_max.c

CMakeFiles/Assignment3.dir/avg_and_max.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment3.dir/avg_and_max.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Makos/Desktop/Assignment3/avg_and_max.c > CMakeFiles/Assignment3.dir/avg_and_max.c.i

CMakeFiles/Assignment3.dir/avg_and_max.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment3.dir/avg_and_max.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Makos/Desktop/Assignment3/avg_and_max.c -o CMakeFiles/Assignment3.dir/avg_and_max.c.s

# Object files for target Assignment3
Assignment3_OBJECTS = \
"CMakeFiles/Assignment3.dir/main.c.o" \
"CMakeFiles/Assignment3.dir/avg_and_max.c.o"

# External object files for target Assignment3
Assignment3_EXTERNAL_OBJECTS =

Assignment3.exe: CMakeFiles/Assignment3.dir/main.c.o
Assignment3.exe: CMakeFiles/Assignment3.dir/avg_and_max.c.o
Assignment3.exe: CMakeFiles/Assignment3.dir/build.make
Assignment3.exe: /usr/lib/libcunit.dll.a
Assignment3.exe: CMakeFiles/Assignment3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Makos/Desktop/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Assignment3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment3.dir/build: Assignment3.exe

.PHONY : CMakeFiles/Assignment3.dir/build

CMakeFiles/Assignment3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment3.dir/clean

CMakeFiles/Assignment3.dir/depend:
	cd /cygdrive/c/Users/Makos/Desktop/Assignment3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Makos/Desktop/Assignment3 /cygdrive/c/Users/Makos/Desktop/Assignment3 /cygdrive/c/Users/Makos/Desktop/Assignment3/cmake-build-debug /cygdrive/c/Users/Makos/Desktop/Assignment3/cmake-build-debug /cygdrive/c/Users/Makos/Desktop/Assignment3/cmake-build-debug/CMakeFiles/Assignment3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment3.dir/depend

