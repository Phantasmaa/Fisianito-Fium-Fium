cmake_minimum_required(VERSION 3.0.0)
project(fisianito VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SFML
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
target_link_libraries(fisianito sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
