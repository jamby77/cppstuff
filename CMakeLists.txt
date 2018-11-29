cmake_minimum_required(VERSION 3.10)
project(splitWords)
set(CMAKE_CXX_STANDARD 17)                     # setting the language standard
set(SOURCE_FILES */*.cpp)
add_executable(words split-words/words.cpp)
