cmake_minimum_required(VERSION 3.19)
project(iqmine)

set(CMAKE_CXX_STANDARD 14)

add_executable(iqmine main.cpp Ecu.cpp Ecu.h EcuUDS.cpp EcuUDS.h EcuKWP.cpp EcuKWP.h Parser.cpp Parser.h)