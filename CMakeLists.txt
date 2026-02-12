cmake_minimum_required(VERSION 4.0)
project(Fractals)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Fractals
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mandelbrotwidget.cpp
        mandelbrotwidget.h
)

target_link_libraries(Fractals
        Qt6::Widgets
)
