cmake_minimum_required(VERSION 3.0.0)
project(lab3_1 VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCv_INCLUDE_DIRS})

add_executable(lab3_1 main.cpp)

target_link_libraries(lab3_1 ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
