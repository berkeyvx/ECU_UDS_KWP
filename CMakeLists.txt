cmake_minimum_required(VERSION 3.16)
project(iqmine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -fno-omit-frame-pointer -fsanitize=address,undefined -ggdb3")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -Wall -Wextra -fno-omit-frame-pointer -fsanitize=address,undefined -ggdb3")

add_executable(iqmine main.cpp Ecu.cpp Ecu.h EcuUDS.cpp EcuUDS.h EcuKWP.cpp EcuKWP.h Parser.cpp Parser.h)