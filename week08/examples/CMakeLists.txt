cmake_minimum_required(VERSION 3.12)

# ARM架构下编译
# add_definitions(-DWITH_NEON)
add_definitions(-DWITH_AVX2)
add_definitions(-mavx2)

set(CMAKE_CXX_STANDARD 11)

project(dotp)

ADD_EXECUTABLE(dotp main.cpp matoperation.cpp)

# 对OpenMP的支持
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message("OpenMP found.")
    target_link_libraries(dotp PUBLIC OpenMP::OpenMP_CXX)
endif()

