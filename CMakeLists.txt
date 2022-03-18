cmake_minimum_required(VERSION 3.0.0)
project(rs-datacollect VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(DEPENDENCIES realsense2 ${OpenCV_LIBS})

message( STATUS "OPENCV VERSION: ${OpenCV_VERSION}")

add_executable(rs-datacollect main.cpp cv-helpers.hpp)
target_link_libraries(rs-datacollect ${DEPENDENCIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
