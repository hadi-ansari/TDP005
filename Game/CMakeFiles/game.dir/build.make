# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/hadan326/clion-2020.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hadan326/clion-2020.2.5/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hadan326/CLionProjects/tdp005/Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hadan326/CLionProjects/tdp005/Game

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadan326/CLionProjects/tdp005/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/main.cpp.o -c /home/hadan326/CLionProjects/tdp005/Game/main.cpp

CMakeFiles/game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadan326/CLionProjects/tdp005/Game/main.cpp > CMakeFiles/game.dir/main.cpp.i

CMakeFiles/game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadan326/CLionProjects/tdp005/Game/main.cpp -o CMakeFiles/game.dir/main.cpp.s

CMakeFiles/game.dir/World.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/World.cpp.o: World.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadan326/CLionProjects/tdp005/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/World.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/World.cpp.o -c /home/hadan326/CLionProjects/tdp005/Game/World.cpp

CMakeFiles/game.dir/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/World.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadan326/CLionProjects/tdp005/Game/World.cpp > CMakeFiles/game.dir/World.cpp.i

CMakeFiles/game.dir/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/World.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadan326/CLionProjects/tdp005/Game/World.cpp -o CMakeFiles/game.dir/World.cpp.s

CMakeFiles/game.dir/Entity.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/Entity.cpp.o: Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadan326/CLionProjects/tdp005/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/Entity.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/Entity.cpp.o -c /home/hadan326/CLionProjects/tdp005/Game/Entity.cpp

CMakeFiles/game.dir/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/Entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadan326/CLionProjects/tdp005/Game/Entity.cpp > CMakeFiles/game.dir/Entity.cpp.i

CMakeFiles/game.dir/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/Entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadan326/CLionProjects/tdp005/Game/Entity.cpp -o CMakeFiles/game.dir/Entity.cpp.s

CMakeFiles/game.dir/Player.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/Player.cpp.o: Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadan326/CLionProjects/tdp005/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/Player.cpp.o -c /home/hadan326/CLionProjects/tdp005/Game/Player.cpp

CMakeFiles/game.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadan326/CLionProjects/tdp005/Game/Player.cpp > CMakeFiles/game.dir/Player.cpp.i

CMakeFiles/game.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadan326/CLionProjects/tdp005/Game/Player.cpp -o CMakeFiles/game.dir/Player.cpp.s

CMakeFiles/game.dir/Enemy.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/Enemy.cpp.o: Enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadan326/CLionProjects/tdp005/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/Enemy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/Enemy.cpp.o -c /home/hadan326/CLionProjects/tdp005/Game/Enemy.cpp

CMakeFiles/game.dir/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/Enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadan326/CLionProjects/tdp005/Game/Enemy.cpp > CMakeFiles/game.dir/Enemy.cpp.i

CMakeFiles/game.dir/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/Enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadan326/CLionProjects/tdp005/Game/Enemy.cpp -o CMakeFiles/game.dir/Enemy.cpp.s

CMakeFiles/game.dir/Bullet.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/Bullet.cpp.o: Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadan326/CLionProjects/tdp005/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/Bullet.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/Bullet.cpp.o -c /home/hadan326/CLionProjects/tdp005/Game/Bullet.cpp

CMakeFiles/game.dir/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/Bullet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadan326/CLionProjects/tdp005/Game/Bullet.cpp > CMakeFiles/game.dir/Bullet.cpp.i

CMakeFiles/game.dir/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/Bullet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadan326/CLionProjects/tdp005/Game/Bullet.cpp -o CMakeFiles/game.dir/Bullet.cpp.s

CMakeFiles/game.dir/Powerup.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/Powerup.cpp.o: Powerup.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadan326/CLionProjects/tdp005/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/Powerup.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/Powerup.cpp.o -c /home/hadan326/CLionProjects/tdp005/Game/Powerup.cpp

CMakeFiles/game.dir/Powerup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/Powerup.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadan326/CLionProjects/tdp005/Game/Powerup.cpp > CMakeFiles/game.dir/Powerup.cpp.i

CMakeFiles/game.dir/Powerup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/Powerup.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadan326/CLionProjects/tdp005/Game/Powerup.cpp -o CMakeFiles/game.dir/Powerup.cpp.s

CMakeFiles/game.dir/Texture_manager.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/Texture_manager.cpp.o: Texture_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hadan326/CLionProjects/tdp005/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.dir/Texture_manager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/Texture_manager.cpp.o -c /home/hadan326/CLionProjects/tdp005/Game/Texture_manager.cpp

CMakeFiles/game.dir/Texture_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/Texture_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hadan326/CLionProjects/tdp005/Game/Texture_manager.cpp > CMakeFiles/game.dir/Texture_manager.cpp.i

CMakeFiles/game.dir/Texture_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/Texture_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hadan326/CLionProjects/tdp005/Game/Texture_manager.cpp -o CMakeFiles/game.dir/Texture_manager.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/main.cpp.o" \
"CMakeFiles/game.dir/World.cpp.o" \
"CMakeFiles/game.dir/Entity.cpp.o" \
"CMakeFiles/game.dir/Player.cpp.o" \
"CMakeFiles/game.dir/Enemy.cpp.o" \
"CMakeFiles/game.dir/Bullet.cpp.o" \
"CMakeFiles/game.dir/Powerup.cpp.o" \
"CMakeFiles/game.dir/Texture_manager.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/main.cpp.o
game: CMakeFiles/game.dir/World.cpp.o
game: CMakeFiles/game.dir/Entity.cpp.o
game: CMakeFiles/game.dir/Player.cpp.o
game: CMakeFiles/game.dir/Enemy.cpp.o
game: CMakeFiles/game.dir/Bullet.cpp.o
game: CMakeFiles/game.dir/Powerup.cpp.o
game: CMakeFiles/game.dir/Texture_manager.cpp.o
game: CMakeFiles/game.dir/build.make
game: /usr/lib/x86_64-linux-gnu/libsfml-network.so.2.5.1
game: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
game: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
game: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hadan326/CLionProjects/tdp005/Game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/hadan326/CLionProjects/tdp005/Game && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hadan326/CLionProjects/tdp005/Game /home/hadan326/CLionProjects/tdp005/Game /home/hadan326/CLionProjects/tdp005/Game /home/hadan326/CLionProjects/tdp005/Game /home/hadan326/CLionProjects/tdp005/Game/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

