# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal

# Include any dependencies generated for this target.
include CMakeFiles/imgProcess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/imgProcess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/imgProcess.dir/flags.make

CMakeFiles/imgProcess.dir/imgProcess.cpp.o: CMakeFiles/imgProcess.dir/flags.make
CMakeFiles/imgProcess.dir/imgProcess.cpp.o: imgProcess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/imgProcess.dir/imgProcess.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgProcess.dir/imgProcess.cpp.o -c /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal/imgProcess.cpp

CMakeFiles/imgProcess.dir/imgProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgProcess.dir/imgProcess.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal/imgProcess.cpp > CMakeFiles/imgProcess.dir/imgProcess.cpp.i

CMakeFiles/imgProcess.dir/imgProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgProcess.dir/imgProcess.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal/imgProcess.cpp -o CMakeFiles/imgProcess.dir/imgProcess.cpp.s

CMakeFiles/imgProcess.dir/imgProcess.cpp.o.requires:

.PHONY : CMakeFiles/imgProcess.dir/imgProcess.cpp.o.requires

CMakeFiles/imgProcess.dir/imgProcess.cpp.o.provides: CMakeFiles/imgProcess.dir/imgProcess.cpp.o.requires
	$(MAKE) -f CMakeFiles/imgProcess.dir/build.make CMakeFiles/imgProcess.dir/imgProcess.cpp.o.provides.build
.PHONY : CMakeFiles/imgProcess.dir/imgProcess.cpp.o.provides

CMakeFiles/imgProcess.dir/imgProcess.cpp.o.provides.build: CMakeFiles/imgProcess.dir/imgProcess.cpp.o


# Object files for target imgProcess
imgProcess_OBJECTS = \
"CMakeFiles/imgProcess.dir/imgProcess.cpp.o"

# External object files for target imgProcess
imgProcess_EXTERNAL_OBJECTS =

imgProcess: CMakeFiles/imgProcess.dir/imgProcess.cpp.o
imgProcess: CMakeFiles/imgProcess.dir/build.make
imgProcess: /usr/local/lib/libopencv_stitching.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_superres.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_videostab.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_aruco.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_bgsegm.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_bioinspired.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_ccalib.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_dnn_objdetect.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_dpm.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_face.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_fuzzy.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_hfs.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_img_hash.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_line_descriptor.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_optflow.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_reg.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_rgbd.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_saliency.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_stereo.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_structured_light.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_surface_matching.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_tracking.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_xfeatures2d.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_ximgproc.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_xobjdetect.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_xphoto.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_shape.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_photo.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_calib3d.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_features2d.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_highgui.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_videoio.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_phase_unwrapping.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_dnn.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_video.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_datasets.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_flann.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_ml.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_plot.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_imgcodecs.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_objdetect.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_imgproc.3.4.3.dylib
imgProcess: /usr/local/lib/libopencv_core.3.4.3.dylib
imgProcess: CMakeFiles/imgProcess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable imgProcess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imgProcess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/imgProcess.dir/build: imgProcess

.PHONY : CMakeFiles/imgProcess.dir/build

CMakeFiles/imgProcess.dir/requires: CMakeFiles/imgProcess.dir/imgProcess.cpp.o.requires

.PHONY : CMakeFiles/imgProcess.dir/requires

CMakeFiles/imgProcess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imgProcess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imgProcess.dir/clean

CMakeFiles/imgProcess.dir/depend:
	cd /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal /Users/mattstevenson/Desktop/ECE415/FinalProject/ComputerVisionFinal/CMakeFiles/imgProcess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imgProcess.dir/depend
