cmake_minimum_required(VERSION 3.17)
project(cw2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(graphics)
add_subdirectory(graphics)
include_directories(gui)
add_subdirectory(gui)

add_executable(cw2 main.cpp)
target_link_libraries(cw2 graphics gui)
