cmake_minimum_required(VERSION 3.24)
project(PAA C)

set(CMAKE_C_STANDARD 11)

add_executable(PAA main.c AlgoritmoHuffman.c AlgoritmoHuffman.h ListaFreq.c ListaFreq.h ArvoreFreq.c ArvoreFreq.h ListaCod.c ListaCod.h)

add_executable(main main.c AlgoritmoHuffman.c AlgoritmoHuffman.h ListaFreq.c ListaFreq.h ArvoreFreq.c ArvoreFreq.h ListaCod.c ListaCod.h)