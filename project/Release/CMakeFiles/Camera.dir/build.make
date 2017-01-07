# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/sy26_camera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/sy26_camera/Release

# Include any dependencies generated for this target.
include CMakeFiles/Camera.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Camera.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Camera.dir/flags.make

CMakeFiles/Camera.dir/camera.cpp.o: CMakeFiles/Camera.dir/flags.make
CMakeFiles/Camera.dir/camera.cpp.o: ../camera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/sy26_camera/Release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Camera.dir/camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Camera.dir/camera.cpp.o -c /home/pi/sy26_camera/camera.cpp

CMakeFiles/Camera.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Camera.dir/camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/sy26_camera/camera.cpp > CMakeFiles/Camera.dir/camera.cpp.i

CMakeFiles/Camera.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Camera.dir/camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/sy26_camera/camera.cpp -o CMakeFiles/Camera.dir/camera.cpp.s

CMakeFiles/Camera.dir/camera.cpp.o.requires:
.PHONY : CMakeFiles/Camera.dir/camera.cpp.o.requires

CMakeFiles/Camera.dir/camera.cpp.o.provides: CMakeFiles/Camera.dir/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/Camera.dir/build.make CMakeFiles/Camera.dir/camera.cpp.o.provides.build
.PHONY : CMakeFiles/Camera.dir/camera.cpp.o.provides

CMakeFiles/Camera.dir/camera.cpp.o.provides.build: CMakeFiles/Camera.dir/camera.cpp.o

# Object files for target Camera
Camera_OBJECTS = \
"CMakeFiles/Camera.dir/camera.cpp.o"

# External object files for target Camera
Camera_EXTERNAL_OBJECTS =

Camera: CMakeFiles/Camera.dir/camera.cpp.o
Camera: CMakeFiles/Camera.dir/build.make
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_videostab.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_video.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_ts.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_superres.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_stitching.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_photo.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_ocl.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_objdetect.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_ml.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_legacy.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_imgproc.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_highgui.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_gpu.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_flann.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_features2d.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_core.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_contrib.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_calib3d.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libboost_program_options.so
Camera: /usr/lib/arm-linux-gnueabihf/libboost_system.so
Camera: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_photo.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_legacy.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_video.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_objdetect.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_ml.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_calib3d.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_features2d.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_highgui.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_imgproc.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_flann.so.2.4.9
Camera: /usr/lib/arm-linux-gnueabihf/libopencv_core.so.2.4.9
Camera: CMakeFiles/Camera.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Camera"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Camera.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Camera.dir/build: Camera
.PHONY : CMakeFiles/Camera.dir/build

CMakeFiles/Camera.dir/requires: CMakeFiles/Camera.dir/camera.cpp.o.requires
.PHONY : CMakeFiles/Camera.dir/requires

CMakeFiles/Camera.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Camera.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Camera.dir/clean

CMakeFiles/Camera.dir/depend:
	cd /home/pi/sy26_camera/Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/sy26_camera /home/pi/sy26_camera /home/pi/sy26_camera/Release /home/pi/sy26_camera/Release /home/pi/sy26_camera/Release/CMakeFiles/Camera.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Camera.dir/depend

