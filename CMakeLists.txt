cmake_minimum_required(VERSION 3.0.0)
project(fisianito VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SFML
  COMPONENTS
  system window graphics audio REQUIRED)

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

target_link_libraries(fisianito sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
