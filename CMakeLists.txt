cmake_minimum_required(VERSION 3.21)
project(findWordGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(findWordGame main.cpp PrintMessageHang.cpp PrintMessageHang.h DrawFigure.cpp DrawFigure.h LoopThroughWord.cpp LoopThroughWord.h)
