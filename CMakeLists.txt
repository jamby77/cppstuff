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
        hw2/txtmd.cpp hw2/LinesArray.h hw2/LinesArray.cpp hw2/MdTransformer.cpp hw2/MdTransformer.h hw2/File.cpp hw2/File.h)
add_executable(temp
        lessons/pointers.cpp
        lessons/sel-sort.cpp lessons/dyn-array.cpp lessons/dyn-array.h lessons/quiz-6.cpp lessons/quiz-6.h)
add_executable(lesson7 lessons/lesson7/calc.cpp lessons/lesson7/main.cpp lessons/lesson7/calc.h lessons/lesson7/quiz711.cpp lessons/lesson7/quiz711.h)
add_executable(lesson8 lessons/lesson8/quiz82.h lessons/lesson8/quiz82.cpp lessons/lesson8/main.cpp lessons/lesson8/Point2d.cpp lessons/lesson8/Point2d.h lessons/lesson8/Monster.cpp lessons/lesson8/Monster.h lessons/lesson8/MonsterGenerator.cpp lessons/lesson8/MonsterGenerator.h lessons/lesson8/BlackJack.cpp lessons/lesson8/BlackJack.h)
add_executable(lesson9 lessons/lesson9/Fraction.cpp lessons/lesson9/Fraction.h lessons/lesson9/main.cpp lessons/lesson9/Car.cpp lessons/lesson9/Car.h lessons/lesson9/GradeMap.cpp lessons/lesson9/GradeMap.h lessons/lesson9/Matrix.cpp lessons/lesson9/Matrix.h lessons/lesson9/Accumulator.cpp lessons/lesson9/Accumulator.h lessons/lesson9/MyString.cpp lessons/lesson9/MyString.h lessons/lesson9/Average.cpp lessons/lesson9/Average.h lessons/lesson9/IntArray.cpp lessons/lesson9/IntArray.h)
add_executable(lesson11 lessons/lesson11/Fruit.cpp lessons/lesson11/Fruit.h lessons/lesson11/main.cpp lessons/lesson11/Apple.cpp lessons/lesson11/Apple.h lessons/lesson11/Banana.cpp lessons/lesson11/Banana.h lessons/lesson11/GrannySmith.cpp lessons/lesson11/GrannySmith.h lessons/lesson11/Creature.cpp lessons/lesson11/Creature.h lessons/lesson11/Player.cpp lessons/lesson11/Player.h)
