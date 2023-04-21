#ifndef PAA_TRAB1_DIJKSTRA_H
#define PAA_TRAB1_DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include "Grafos.h"
#include "GrafoMenorCaminho.h"
#include "FilaPilha.h"

// Verifica se o grafo é orientado
int VerificaDijkstra (Grafo *G);

// Extrai o valor do vértice com menor distância para a origem, de um vetor com os valores de todos os vértices que não foram extraidos ainda.
int ExtraiMinimo(int *q, GrafoMenorCaminho **Q, int *tq);

// Aplica o algoritmo de Dijkstra, como nos slides.
void Dijkstra(Grafo * G, int s);

// Imprime o caminho passado como parâmetro S.
void ImprimeCaminho(GrafoMenorCaminho ** QRaiz, FilaSimples * S, int s);

#endif