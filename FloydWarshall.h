#ifndef PAA_TRAB1_FLOYDWARSHALL_H
#define PAA_TRAB1_FLOYDWARSHALL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"
#include "GrafoMenorCaminho.h"

// Verifica se o grafo contem ciclos negativos ou não
int verificaFloydWarshall(Grafo * grafo);

// Aplica o algoritmo de Floyd-Warshall, como nos slides.
void floydWarshall(Grafo *grafo);

#endif
