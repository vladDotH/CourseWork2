cmake_minimum_required(VERSION 3.17)
project(gui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(tools)
set(GUI_SRC Viewer.cpp Viewer.h MainWindow.cpp MainWindow.h tools/ToolBar.cpp tools/ToolBar.h tools/CrossSquare.cpp tools/CrossSquare.h tools/Circle.cpp tools/Circle.h tools/Filter.cpp tools/Filter.h tools/Rotator.cpp tools/Rotator.h)
add_library(gui STATIC ${GUI_SRC})
target_link_libraries(gui Qt5::Core Qt5::Widgets Qt5::Gui graphics)
message("GUI module builded")