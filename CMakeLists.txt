cmake_minimum_required(VERSION 3.10)

project(sfSnake VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(main ${SOURCES})

target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)