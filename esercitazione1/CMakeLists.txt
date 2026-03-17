# versione minima di CMake
cmake_minimum_required(VERSION 3.20)

# Nome del progetto
project(esercitazione1) 

# Impostare lo standard C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Flag per la compilazione
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

# Creazione eseguibili
add_executable(printargs printargs.cpp)
add_executable(media media.cpp)

