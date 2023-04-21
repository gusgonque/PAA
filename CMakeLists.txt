cmake_minimum_required(VERSION 3.24)
project(PAA_Trab1 C)

set(CMAKE_C_STANDARD 11)

# Adicione o diretório de inclusão e as bibliotecas do Graphviz
include_directories("C:/Program Files/Graphviz/include")
link_directories("C:/Program Files/Graphviz/lib")

add_executable(main main.c DFS.c Grafos.c Trab2.c BFS.c BellmanFord.c Dijkstra.c FloydWarshall.c GrafoMenorCaminho.c GrafoMenorCaminho.h FilaPilha.c FilaPilha.h Kurskal.c)

# Vincule as bibliotecas do Graphviz ao seu programa
target_link_libraries(main cgraph gvc)
