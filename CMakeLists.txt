cmake_minimum_required(VERSION 3.0.0)
project(fisianito VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SFML
<<<<<<< HEAD
  COMPONENTS 
    system window graphics audio REQUIRED)

include_directories(include)
add_executable(fisianito 
            src/main.cpp
            src/Game.cpp
            src/Player.cpp
            src/Entity.cpp
            include/Game.hpp
            include/Player.hpp
            include/Entity.hpp
            )
=======
  COMPONENTS
  system window graphics audio REQUIRED)

include_directories(include)
add_executable(fisianito
  include/Game/Animation.hpp
  include/Game/Collision.hpp
  include/Game/Entity.hpp
  include/Game/Game.hpp
  include/Game/GameTextures.hpp
  include/Game/Platform.hpp
  include/Game/Player.hpp
  include/DataStructures/EntityNode.hpp
  src/Game/Animation.cpp
  src/Game/Collision.cpp
  src/Game/Entity.cpp
  src/Game/Game.cpp
  src/Game/GameTextures.cpp
  src/Game/main.cpp
  src/Game/Platform.cpp
  src/Game/Player.cpp
)

>>>>>>> origin/debug
target_link_libraries(fisianito sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
