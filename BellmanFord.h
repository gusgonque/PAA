#ifndef PAA_TRAB1_BELLMANFORD_H
#define PAA_TRAB1_BELLMANFORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"
#include "GrafoMenorCaminho.h"
#include "FilaPilha.h"

// Verifica se o grafo é orientado ou não.
int VerificaBellmanFord (Grafo *G);

// Imprime o menor caminho a partir da origem para o vértice com valor passado como parâmetro.
void ImprimeMenorCaminho(GrafoMenorCaminho **Q, int valor, int origem);

// Algoritmo de BellmanFord, como explicado nos slides.
void BellmanFord(Grafo *grafo, int origem);

#endif
