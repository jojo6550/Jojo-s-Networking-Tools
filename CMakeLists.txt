# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(NetworkingTools)

add_library(NetworkingTools STATIC
    src/ip_converter.cpp
)

target_include_directories(NetworkingTools PUBLIC
    include
)

target_link_libraries(NetworkingTools
    PUBLIC
        stdc++
)