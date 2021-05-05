cmake_minimum_required(VERSION 3.16)
project(PFCQ)
set(CMAKE_CXX_STANDARD 14)

include_directories(./)
include_directories(SlidingWindow)
add_subdirectory(SlidingWindow)

aux_source_directory(. DIR_SRC)
add_executable(${PROJECT_NAME} ${DIR_SRC})
target_link_libraries(${PROJECT_NAME} SlidingWindow)


