cmake_minimum_required(VERSION 3.24)
project(PAA C)

set(CMAKE_C_STANDARD 11)

add_executable(PAA main.c AlgoritmoHuffman.c AlgoritmoHuffman.h ListaAlfabeto.c ListaAlfabeto.h ArvoreBinaria.c ArvoreBinaria.h ListaSimples.c ListaSimples.h)

add_executable(main main.c AlgoritmoHuffman.c AlgoritmoHuffman.h ListaAlfabeto.c ListaAlfabeto.h ArvoreBinaria.c ArvoreBinaria.h ListaSimples.c ListaSimples.h)