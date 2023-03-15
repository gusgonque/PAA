cmake_minimum_required(VERSION 3.24)
project(PAA_Trab1 C)

set(CMAKE_C_STANDARD 11)

include_directories(graphviz)

add_executable(PAA_Trab1 main.c)

add_executable(main main.c DFS.c DFS.h Grafos.c Grafos.h Trab2.c Trab2.h BFS.c BFS.h)