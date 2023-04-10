#ifndef PAA_TRAB1_BELLMANFORD_H
#define PAA_TRAB1_BELLMANFORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"

typedef struct noFilaSimples{
    int valorNo;
    struct noFilaSimples *prox;
} FilaSimples;

void BellmanFord(Grafo *grafo, int origem);

#endif
