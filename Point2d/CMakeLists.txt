cmake_minimum_required(VERSION 3.10)
project(Point2dExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_library(Point2d
    src/point2d.cpp)

# Incluye el directorio donde está point2d.h
include_directories(include)

# Crea el ejecutable con ambos archivos fuente
add_executable(Point2dExample
    src/main.cpp
)
target_link_libraries(Point2dExample Point2d)