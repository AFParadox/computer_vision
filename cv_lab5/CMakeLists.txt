cmake_minimum_required(VERSION 3.0.0)
project(cv_lab5 VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_library(
    lab5_library
    src/task1.cpp
    src/task2.cpp
    src/task3.cpp
    src/methods.cpp
    headers/lab5_tasks.hpp
)

target_include_directories(lab5_library PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")

add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
