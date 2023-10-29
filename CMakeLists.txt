cmake_minimum_required(VERSION 3.16)

project(neptune LANGUAGES C CXX)

set(SOURCES ${CMAKE_SOURCE_DIR}/src/main.cc
            ${CMAKE_SOURCE_DIR}/src/StringView.cc
            )
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

qt_add_executable(neptune ${SOURCES})

add_compile_options(neptune -g)
target_link_libraries(neptune PRIVATE Qt6::Core Qt6::Widgets)
target_include_directories(neptune PRIVATE include)
