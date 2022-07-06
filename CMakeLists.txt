cmake_minimum_required(VERSION 3.22)
project(integerCalc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(integerCalc main.cpp model/Calculator.cpp model/Calculator.h controller/HandleCalculator.cpp controller/HandleCalculator.h view/WindowCalculator.cpp view/WindowCalculator.h)
target_link_libraries(integerCalc
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

