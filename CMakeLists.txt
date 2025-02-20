cmake_minimum_required(VERSION 3.0.0)
project(fisianito VERSION 0.1.0)

include(CTest)
enable_testing()
IF (WIN32)
# Windows specific config
  # Include local sfml cmake config
  set(SFML_DIR "C:/Users/Luu/Downloads/SFML-2.5.1/lib/cmake/SFML")
ENDIF()

find_package(SFML
  COMPONENTS
  system window graphics audio REQUIRED)

include_directories(include)
add_executable(fisianito
  include/Game/Animation.hpp
  include/Game/Bullet.hpp
  include/Game/Collision.hpp
  include/Game/Enemy.hpp
  include/Game/Entity.hpp
  include/Game/Game.hpp
  include/Game/GameTextures.hpp
  include/Game/Maps.hpp
  include/Game/Platform.hpp
  include/Game/Player.hpp
  include/DataStructures/EntityNode.hpp
  src/Game/Animation.cpp
  src/Game/Bullet.cpp
  src/Game/Collision.cpp
  src/Game/Enemy.cpp
  src/Game/Entity.cpp
  src/Game/Game.cpp
  src/Game/GameTextures.cpp
  src/Game/main.cpp
  src/Game/Maps.cpp
  src/Game/Platform.cpp
  src/Game/Player.cpp
)

target_link_libraries(fisianito sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
