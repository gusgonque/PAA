cmake_minimum_required(VERSION 3.24)
project(PAA_Trab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(PAA_Trab1 main.c PAA-Trab1.c PAA-Trab1.h ListaArvore.c ListaArvore.h ArvoreBinaria.c ArvoreBinaria.h)

add_executable(main main.c)