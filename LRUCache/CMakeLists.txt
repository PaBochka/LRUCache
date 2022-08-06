cmake_minimum_required(VERSION 3.14)

project(LRUCache LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LRUCache
  main.cpp
  lrucache.h lrucache.cpp
)
