# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\2019 autumn\database\BufferandStorageManage"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\2019 autumn\database\BufferandStorageManage\Debug"

# Include any dependencies generated for this target.
include src/CMakeFiles/src_lib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src_lib.dir/flags.make

src/CMakeFiles/src_lib.dir/buffer/Hash.cpp.obj: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/buffer/Hash.cpp.obj: src/CMakeFiles/src_lib.dir/includes_CXX.rsp
src/CMakeFiles/src_lib.dir/buffer/Hash.cpp.obj: ../src/buffer/Hash.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\2019 autumn\database\BufferandStorageManage\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src_lib.dir/buffer/Hash.cpp.obj"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\src_lib.dir\buffer\Hash.cpp.obj -c "E:\2019 autumn\database\BufferandStorageManage\src\buffer\Hash.cpp"

src/CMakeFiles/src_lib.dir/buffer/Hash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/buffer/Hash.cpp.i"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\2019 autumn\database\BufferandStorageManage\src\buffer\Hash.cpp" > CMakeFiles\src_lib.dir\buffer\Hash.cpp.i

src/CMakeFiles/src_lib.dir/buffer/Hash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/buffer/Hash.cpp.s"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\2019 autumn\database\BufferandStorageManage\src\buffer\Hash.cpp" -o CMakeFiles\src_lib.dir\buffer\Hash.cpp.s

src/CMakeFiles/src_lib.dir/buffer/LRU.cpp.obj: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/buffer/LRU.cpp.obj: src/CMakeFiles/src_lib.dir/includes_CXX.rsp
src/CMakeFiles/src_lib.dir/buffer/LRU.cpp.obj: ../src/buffer/LRU.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\2019 autumn\database\BufferandStorageManage\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src_lib.dir/buffer/LRU.cpp.obj"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\src_lib.dir\buffer\LRU.cpp.obj -c "E:\2019 autumn\database\BufferandStorageManage\src\buffer\LRU.cpp"

src/CMakeFiles/src_lib.dir/buffer/LRU.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/buffer/LRU.cpp.i"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\2019 autumn\database\BufferandStorageManage\src\buffer\LRU.cpp" > CMakeFiles\src_lib.dir\buffer\LRU.cpp.i

src/CMakeFiles/src_lib.dir/buffer/LRU.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/buffer/LRU.cpp.s"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\2019 autumn\database\BufferandStorageManage\src\buffer\LRU.cpp" -o CMakeFiles\src_lib.dir\buffer\LRU.cpp.s

src/CMakeFiles/src_lib.dir/buffer/frame.cpp.obj: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/buffer/frame.cpp.obj: src/CMakeFiles/src_lib.dir/includes_CXX.rsp
src/CMakeFiles/src_lib.dir/buffer/frame.cpp.obj: ../src/buffer/frame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\2019 autumn\database\BufferandStorageManage\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src_lib.dir/buffer/frame.cpp.obj"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\src_lib.dir\buffer\frame.cpp.obj -c "E:\2019 autumn\database\BufferandStorageManage\src\buffer\frame.cpp"

src/CMakeFiles/src_lib.dir/buffer/frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/buffer/frame.cpp.i"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\2019 autumn\database\BufferandStorageManage\src\buffer\frame.cpp" > CMakeFiles\src_lib.dir\buffer\frame.cpp.i

src/CMakeFiles/src_lib.dir/buffer/frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/buffer/frame.cpp.s"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\2019 autumn\database\BufferandStorageManage\src\buffer\frame.cpp" -o CMakeFiles\src_lib.dir\buffer\frame.cpp.s

src/CMakeFiles/src_lib.dir/storage/disk.cpp.obj: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/storage/disk.cpp.obj: src/CMakeFiles/src_lib.dir/includes_CXX.rsp
src/CMakeFiles/src_lib.dir/storage/disk.cpp.obj: ../src/storage/disk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\2019 autumn\database\BufferandStorageManage\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/src_lib.dir/storage/disk.cpp.obj"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\src_lib.dir\storage\disk.cpp.obj -c "E:\2019 autumn\database\BufferandStorageManage\src\storage\disk.cpp"

src/CMakeFiles/src_lib.dir/storage/disk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/storage/disk.cpp.i"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\2019 autumn\database\BufferandStorageManage\src\storage\disk.cpp" > CMakeFiles\src_lib.dir\storage\disk.cpp.i

src/CMakeFiles/src_lib.dir/storage/disk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/storage/disk.cpp.s"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\2019 autumn\database\BufferandStorageManage\src\storage\disk.cpp" -o CMakeFiles\src_lib.dir\storage\disk.cpp.s

# Object files for target src_lib
src_lib_OBJECTS = \
"CMakeFiles/src_lib.dir/buffer/Hash.cpp.obj" \
"CMakeFiles/src_lib.dir/buffer/LRU.cpp.obj" \
"CMakeFiles/src_lib.dir/buffer/frame.cpp.obj" \
"CMakeFiles/src_lib.dir/storage/disk.cpp.obj"

# External object files for target src_lib
src_lib_EXTERNAL_OBJECTS =

src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/buffer/Hash.cpp.obj
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/buffer/LRU.cpp.obj
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/buffer/frame.cpp.obj
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/storage/disk.cpp.obj
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/build.make
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\2019 autumn\database\BufferandStorageManage\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libsrc_lib.a"
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && $(CMAKE_COMMAND) -P CMakeFiles\src_lib.dir\cmake_clean_target.cmake
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\src_lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src_lib.dir/build: src/libsrc_lib.a

.PHONY : src/CMakeFiles/src_lib.dir/build

src/CMakeFiles/src_lib.dir/clean:
	cd /d E:\2019AU~1\database\BUFFER~2\Debug\src && $(CMAKE_COMMAND) -P CMakeFiles\src_lib.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/src_lib.dir/clean

src/CMakeFiles/src_lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\2019 autumn\database\BufferandStorageManage" "E:\2019 autumn\database\BufferandStorageManage\src" "E:\2019 autumn\database\BufferandStorageManage\Debug" "E:\2019 autumn\database\BufferandStorageManage\Debug\src" "E:\2019 autumn\database\BufferandStorageManage\Debug\src\CMakeFiles\src_lib.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/src_lib.dir/depend
