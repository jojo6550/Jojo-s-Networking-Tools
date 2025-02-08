cmake_minimum_required(VERSION 3.10)
project(NetworkingTools)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(NetworkingTools STATIC
  src/ip_converter.cpp
)

target_include_directories(NetworkingTools PUBLIC
  include
)

install(TARGETS NetworkingTools
  LIBRARY DESTINATION C:/Users/User/Documents/Portfolio/Networking-Tools/lib
  ARCHIVE DESTINATION C:/Users/User/Documents/Portfolio/Networking-Tools/lib
)