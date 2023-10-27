cmake_minimum_required(VERSION 3.22)
project(SOFT)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/inc)
link_directories(${PROJECT_SOURCE_DIR}/lib)


add_executable(SOFT main.cpp)

target_link_libraries(SOFT glfw3)
target_link_libraries(SOFT vulkan-1)