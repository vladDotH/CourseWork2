cmake_minimum_required(VERSION 3.15)
project(gui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(toolbar)
set(GUI_SRC viewer/Viewer.cpp viewer/Viewer.h MainWindow.cpp MainWindow.h toolbar/ToolBar.cpp
        toolbar/ToolBar.h toolbar/tools/CrossSquare.cpp toolbar/tools/CrossSquare.h toolbar/tools/Circle.cpp toolbar/tools/Circle.h
        toolbar/tools/Filter.cpp toolbar/tools/Filter.h toolbar/tools/Rotator.cpp toolbar/tools/Rotator.h
        viewer/ImageLabel.cpp viewer/ImageLabel.h toolbar/tools/ColorSetting.cpp toolbar/tools/ColorSetting.h
        toolbar/tools/Tool.cpp toolbar/tools/Tool.h qgraphics/BitMapQ.cpp qgraphics/BitMapQ.h
        qgraphics/Vec2DQ.h qgraphics/ColorQ.h)

add_library(gui STATIC ${GUI_SRC})
target_link_libraries(gui Qt5::Core Qt5::Widgets Qt5::Gui graphics)
message("GUI module builded")