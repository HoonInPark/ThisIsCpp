# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /Users/changjoonlee/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Users/changjoonlee/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OperOverAssign.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OperOverAssign.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OperOverAssign.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OperOverAssign.dir/flags.make

CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.o: CMakeFiles/OperOverAssign.dir/flags.make
CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.o: /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/OperOverAssign.cpp
CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.o: CMakeFiles/OperOverAssign.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.o -MF CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.o.d -o CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.o -c /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/OperOverAssign.cpp

CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/OperOverAssign.cpp > CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.i

CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/OperOverAssign.cpp -o CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.s

# Object files for target OperOverAssign
OperOverAssign_OBJECTS = \
"CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.o"

# External object files for target OperOverAssign
OperOverAssign_EXTERNAL_OBJECTS =

OperOverAssign: CMakeFiles/OperOverAssign.dir/OperOverAssign.cpp.o
OperOverAssign: CMakeFiles/OperOverAssign.dir/build.make
OperOverAssign: CMakeFiles/OperOverAssign.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OperOverAssign"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OperOverAssign.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OperOverAssign.dir/build: OperOverAssign
.PHONY : CMakeFiles/OperOverAssign.dir/build

CMakeFiles/OperOverAssign.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OperOverAssign.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OperOverAssign.dir/clean

CMakeFiles/OperOverAssign.dir/depend:
	cd /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05 /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05 /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/cmake-build-debug /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/cmake-build-debug /Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter05/cmake-build-debug/CMakeFiles/OperOverAssign.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/OperOverAssign.dir/depend

