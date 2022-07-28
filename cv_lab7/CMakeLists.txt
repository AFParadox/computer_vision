cmake_minimum_required(VERSION 3.0.0)
project(cv_lab7 VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(Code/header)
link_directories(${OpenCV_LINK_DIRS})

add_executable(cv_lab7 Code/main.cpp Code/panoramic_utils.cpp Code/panoramic_img.cpp)


target_link_libraries(cv_lab7 ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
