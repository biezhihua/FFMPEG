# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/flags.make

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/flags.make
CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o -c /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/main.cpp

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/main.cpp > CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.i

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/main.cpp -o CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.s

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o.requires

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o.provides: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/build.make CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o.provides

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o.provides.build: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o


CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/flags.make
CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o: ../ffmpeg_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o   -c /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/ffmpeg_utils.c

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/ffmpeg_utils.c > CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.i

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/ffmpeg_utils.c -o CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.s

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o.requires:

.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o.requires

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o.provides: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o.requires
	$(MAKE) -f CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/build.make CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o.provides.build
.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o.provides

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o.provides.build: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o


CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/flags.make
CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o: ../ffmpeg_mediametadataretriever.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o   -c /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/ffmpeg_mediametadataretriever.c

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/ffmpeg_mediametadataretriever.c > CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.i

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/ffmpeg_mediametadataretriever.c -o CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.s

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o.requires:

.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o.requires

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o.provides: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o.requires
	$(MAKE) -f CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/build.make CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o.provides.build
.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o.provides

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o.provides.build: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o


# Object files for target NativeMediaMetadataRetrieverDemo
NativeMediaMetadataRetrieverDemo_OBJECTS = \
"CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o" \
"CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o" \
"CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o"

# External object files for target NativeMediaMetadataRetrieverDemo
NativeMediaMetadataRetrieverDemo_EXTERNAL_OBJECTS =

NativeMediaMetadataRetrieverDemo: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o
NativeMediaMetadataRetrieverDemo: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o
NativeMediaMetadataRetrieverDemo: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o
NativeMediaMetadataRetrieverDemo: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/build.make
NativeMediaMetadataRetrieverDemo: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable NativeMediaMetadataRetrieverDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/build: NativeMediaMetadataRetrieverDemo

.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/build

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/requires: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/main.cpp.o.requires
CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/requires: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_utils.c.o.requires
CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/requires: CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/ffmpeg_mediametadataretriever.c.o.requires

.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/requires

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/clean

CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/depend:
	cd /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/cmake-build-debug /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/cmake-build-debug /Users/biezhihua/studyspace/FFMPEG/FFmpegMediaMetadataRetriever/cmake-build-debug/CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NativeMediaMetadataRetrieverDemo.dir/depend

