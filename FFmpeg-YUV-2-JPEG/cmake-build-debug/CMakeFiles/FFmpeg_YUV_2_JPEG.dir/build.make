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
CMAKE_SOURCE_DIR = /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FFmpeg_YUV_2_JPEG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FFmpeg_YUV_2_JPEG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FFmpeg_YUV_2_JPEG.dir/flags.make

CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o: CMakeFiles/FFmpeg_YUV_2_JPEG.dir/flags.make
CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o   -c /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/main.c

CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/main.c > CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.i

CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/main.c -o CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.s

CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o.requires:

.PHONY : CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o.requires

CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o.provides: CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/FFmpeg_YUV_2_JPEG.dir/build.make CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o.provides.build
.PHONY : CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o.provides

CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o.provides.build: CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o


# Object files for target FFmpeg_YUV_2_JPEG
FFmpeg_YUV_2_JPEG_OBJECTS = \
"CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o"

# External object files for target FFmpeg_YUV_2_JPEG
FFmpeg_YUV_2_JPEG_EXTERNAL_OBJECTS =

FFmpeg_YUV_2_JPEG: CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o
FFmpeg_YUV_2_JPEG: CMakeFiles/FFmpeg_YUV_2_JPEG.dir/build.make
FFmpeg_YUV_2_JPEG: CMakeFiles/FFmpeg_YUV_2_JPEG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable FFmpeg_YUV_2_JPEG"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FFmpeg_YUV_2_JPEG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FFmpeg_YUV_2_JPEG.dir/build: FFmpeg_YUV_2_JPEG

.PHONY : CMakeFiles/FFmpeg_YUV_2_JPEG.dir/build

CMakeFiles/FFmpeg_YUV_2_JPEG.dir/requires: CMakeFiles/FFmpeg_YUV_2_JPEG.dir/main.c.o.requires

.PHONY : CMakeFiles/FFmpeg_YUV_2_JPEG.dir/requires

CMakeFiles/FFmpeg_YUV_2_JPEG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FFmpeg_YUV_2_JPEG.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FFmpeg_YUV_2_JPEG.dir/clean

CMakeFiles/FFmpeg_YUV_2_JPEG.dir/depend:
	cd /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/cmake-build-debug /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/cmake-build-debug /Users/biezhihua/studyspace/FFMPEG/FFmpeg-YUV-2-JPEG/cmake-build-debug/CMakeFiles/FFmpeg_YUV_2_JPEG.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FFmpeg_YUV_2_JPEG.dir/depend

