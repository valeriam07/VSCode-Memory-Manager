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
CMAKE_COMMAND = /home/valeria/CLion-2019.3.4/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/valeria/CLion-2019.3.4/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/VSPointer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VSPointer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VSPointer.dir/flags.make

CMakeFiles/VSPointer.dir/library.cpp.o: CMakeFiles/VSPointer.dir/flags.make
CMakeFiles/VSPointer.dir/library.cpp.o: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VSPointer.dir/library.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VSPointer.dir/library.cpp.o -c /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/library.cpp

CMakeFiles/VSPointer.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VSPointer.dir/library.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/library.cpp > CMakeFiles/VSPointer.dir/library.cpp.i

CMakeFiles/VSPointer.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VSPointer.dir/library.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/library.cpp -o CMakeFiles/VSPointer.dir/library.cpp.s

# Object files for target VSPointer
VSPointer_OBJECTS = \
"CMakeFiles/VSPointer.dir/library.cpp.o"

# External object files for target VSPointer
VSPointer_EXTERNAL_OBJECTS =

libVSPointer.so: CMakeFiles/VSPointer.dir/library.cpp.o
libVSPointer.so: CMakeFiles/VSPointer.dir/build.make
libVSPointer.so: CMakeFiles/VSPointer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libVSPointer.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VSPointer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VSPointer.dir/build: libVSPointer.so

.PHONY : CMakeFiles/VSPointer.dir/build

CMakeFiles/VSPointer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VSPointer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VSPointer.dir/clean

CMakeFiles/VSPointer.dir/depend:
	cd /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/cmake-build-debug /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/cmake-build-debug /home/valeria/CLionProjects/Proyecto-I-Datos-II/VSPointer/cmake-build-debug/CMakeFiles/VSPointer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VSPointer.dir/depend

