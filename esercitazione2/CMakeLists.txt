# versione minima di CMake
cmake_minimum_required(VERSION 3.20)

# Nome del progetto
project(esercitazione1) 

# Impostare lo standard C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Flag per la compilazione
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Creazione eseguibili
add_executable(algo algoritmi.cpp)
add_executable(bubble bubblesort.cpp)
