cmake_minimum_required(VERSION 3.15)
project(cw)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(graphics)
add_subdirectory(graphics)
include_directories(gui)
add_subdirectory(gui)

add_executable(cw main.cpp)
target_link_libraries(cw graphics gui)
