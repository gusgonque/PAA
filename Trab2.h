#ifndef PAA_TRAB1_TRAB2_H
#define PAA_TRAB1_TRAB2_H

#include <stdio.h>
#include "Grafos.h"
#include "DFS.h"
#include "BFS.h"
#include "BellmanFord.h"
#include "Dijkstra.h"
#include "FloydWarshall.h"

// Abre o arquivo passado como parâmetro
FILE *abreArquivo (char *fileName, char *mode);

// Carrega o grafo de um arquivo .txt
Grafo *carregaArquivoGrafo();

#endif //PAA_TRAB1_TRAB2_H
