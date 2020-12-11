cmake_minimum_required(VERSION 3.10)

project(game)

set(SOURCE_FILES main.cpp World.cpp World.h Entity.cpp Entity.h Player.cpp Player.h Enemy.cpp Enemy.h Bullet.cpp Bullet.h Powerup.h Powerup.cpp Texture_manager.cpp Texture_manager.h Level.cpp Level.h)

set(CMAKE_CXX_STANDARD 17)

if (DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".*prog/gcc/6.1.0.*"))
   set(CMAKE_CXX_COMPILER /sw/gcc-6.1.0/bin/g++)

   if (DEFINED ENV{SFML_ROOT})
      list(APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
      endif()
endif()

set(SFML_MODULES network graphics window system)

find_package(SFML 2 COMPONENTS ${SFML_MODULES})
include_directories(${SFML_INCLUDE_DIR})

if (NOT (${SFML_FOUND} STREQUAL "TRUE"))
set(SFML_LIBRARIES "")
foreach(i ${SFML_MODULES})
list(APPEND SFML_LIBRARIES "sfml-${i}")
endforeach(i)
endif()

add_executable(game ${SOURCE_FILES})
target_link_libraries(game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
