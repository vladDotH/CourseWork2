cmake_minimum_required(VERSION 3.15)
project(graphics)

set(LIB_SRC BitMap.cpp BitMap.h Vector.cpp Vector.h Color.cpp Color.h)
add_library(graphics STATIC ${LIB_SRC})
message("Graphics module builded")