cmake_minimum_required(VERSION 3.0.0)
project(lab2_2 VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCv_INCLUDE_DIRS})

add_executable(lab2_2 main.cpp minmax_filters.cpp)

target_link_libraries(lab2_2 ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
