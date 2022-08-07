cmake_minimum_required(VERSION 3.0.0)
project(fisianito VERSION 0.1.0)

include(CTest)
enable_testing()

IF (WIN32)
# Windows specific config
  # Include local sfml cmake config
  set(SFML_DIR "C:/Users/Luu/Downloads/SFML-2.5.1/lib/cmake/SFML")
ENDIF()

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache


include_directories(include)
add_executable(fisianito
  include/Animation.hpp
  include/Collision.hpp
  include/Entity.hpp
  include/Game.hpp
  include/GameTextures.hpp
  include/Platform.hpp
  include/Player.hpp
  src/Animation.cpp
  src/Collision.cpp
  src/Entity.cpp
  src/Game.cpp
  src/GameTextures.cpp
  src/main.cpp
  src/Platform.cpp
  src/Player.cpp
)

target_link_libraries(fisianito sfml-graphics sfml-audio)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
