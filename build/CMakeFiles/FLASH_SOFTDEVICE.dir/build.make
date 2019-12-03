# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/imar-itt/Downloads/nRF5x_cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/imar-itt/Downloads/nRF5x_cmake/build

# Utility rule file for FLASH_SOFTDEVICE.

# Include the progress variables for this target.
include CMakeFiles/FLASH_SOFTDEVICE.dir/progress.make

CMakeFiles/FLASH_SOFTDEVICE:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/imar-itt/Downloads/nRF5x_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "flashing SoftDevice"
	/opt/SEGGER/NRFJPROG/nrfjprog/nrfjprog --program /opt/SEGGER/nRF5SDK/components/softdevice/s132/hex/s132_nrf52_7.0.1_softdevice.hex -f nrf52 --sectorerase
	sleep 0.5s
	/opt/SEGGER/NRFJPROG/nrfjprog/nrfjprog --reset -f nrf52

FLASH_SOFTDEVICE: CMakeFiles/FLASH_SOFTDEVICE
FLASH_SOFTDEVICE: CMakeFiles/FLASH_SOFTDEVICE.dir/build.make

.PHONY : FLASH_SOFTDEVICE

# Rule to build all files generated by this target.
CMakeFiles/FLASH_SOFTDEVICE.dir/build: FLASH_SOFTDEVICE

.PHONY : CMakeFiles/FLASH_SOFTDEVICE.dir/build

CMakeFiles/FLASH_SOFTDEVICE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FLASH_SOFTDEVICE.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FLASH_SOFTDEVICE.dir/clean

CMakeFiles/FLASH_SOFTDEVICE.dir/depend:
	cd /home/imar-itt/Downloads/nRF5x_cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imar-itt/Downloads/nRF5x_cmake /home/imar-itt/Downloads/nRF5x_cmake /home/imar-itt/Downloads/nRF5x_cmake/build /home/imar-itt/Downloads/nRF5x_cmake/build /home/imar-itt/Downloads/nRF5x_cmake/build/CMakeFiles/FLASH_SOFTDEVICE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FLASH_SOFTDEVICE.dir/depend
