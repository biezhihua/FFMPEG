# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FFmpegDemuxerSimple.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FFmpegDemuxerSimple.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FFmpegDemuxerSimple.dir/flags.make

CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o: CMakeFiles/FFmpegDemuxerSimple.dir/flags.make
CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o   -c /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/main.c

CMakeFiles/FFmpegDemuxerSimple.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FFmpegDemuxerSimple.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/main.c > CMakeFiles/FFmpegDemuxerSimple.dir/main.c.i

CMakeFiles/FFmpegDemuxerSimple.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FFmpegDemuxerSimple.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/main.c -o CMakeFiles/FFmpegDemuxerSimple.dir/main.c.s

CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o.requires:

.PHONY : CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o.requires

CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o.provides: CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/FFmpegDemuxerSimple.dir/build.make CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o.provides.build
.PHONY : CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o.provides

CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o.provides.build: CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o


# Object files for target FFmpegDemuxerSimple
FFmpegDemuxerSimple_OBJECTS = \
"CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o"

# External object files for target FFmpegDemuxerSimple
FFmpegDemuxerSimple_EXTERNAL_OBJECTS =

FFmpegDemuxerSimple: CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o
FFmpegDemuxerSimple: CMakeFiles/FFmpegDemuxerSimple.dir/build.make
FFmpegDemuxerSimple: CMakeFiles/FFmpegDemuxerSimple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable FFmpegDemuxerSimple"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FFmpegDemuxerSimple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FFmpegDemuxerSimple.dir/build: FFmpegDemuxerSimple

.PHONY : CMakeFiles/FFmpegDemuxerSimple.dir/build

CMakeFiles/FFmpegDemuxerSimple.dir/requires: CMakeFiles/FFmpegDemuxerSimple.dir/main.c.o.requires

.PHONY : CMakeFiles/FFmpegDemuxerSimple.dir/requires

CMakeFiles/FFmpegDemuxerSimple.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FFmpegDemuxerSimple.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FFmpegDemuxerSimple.dir/clean

CMakeFiles/FFmpegDemuxerSimple.dir/depend:
	cd /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/cmake-build-debug /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/cmake-build-debug /Users/biezhihua/studyspace/FFMPEG/FFmpegDemuxerSimple/cmake-build-debug/CMakeFiles/FFmpegDemuxerSimple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FFmpegDemuxerSimple.dir/depend

