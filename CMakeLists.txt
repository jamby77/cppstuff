cmake_minimum_required(VERSION 3.10)
project(iva)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(hw1
        hw1/fmicoin.cpp
        hw1/helpers.cpp
        hw1/helpers.h
        hw1/transacitons.h
        hw1/transactions.cpp
        hw1/wallet.cpp
        hw1/wallet.h)
add_executable(hw2
        hw2/txtmd.cpp hw2/LinesArray.h hw2/LinesArray.cpp hw2/MdTransformer.cpp hw2/MdTransformer.h)
