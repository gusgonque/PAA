#ifndef PAA_TRAB1_GRAFOMENORCAMINHO_H
#define PAA_TRAB1_GRAFOMENORCAMINHO_H

#include <stdio.h>
#include <stdlib.h>
#include "Grafos.h"
#include "FilaPilha.h"

typedef struct GrafoMenorCaminho{
    Grafo *g;           // Ponteiro para o Grafo usado.
    int v;          // Valor do vértice
    int d;              // Custo estimado do menor caminho até esse vértice
    int pi;             // Predecessor deste vértice no menor caminho
    ListaVertices *adj; // Ponteiro para a lista de vértices adjacentes a esse;
}GrafoMenorCaminho;

// Aplica a função Relax, como nos slides, para algoritmos de menor caminho
void Relax (GrafoMenorCaminho *u, GrafoMenorCaminho *v);

// Inicializa a função InicializaOrigem, como nos slides, para algoritmos de menor caminho
GrafoMenorCaminho ** InicializaOrigem (Grafo *g, int origem);

#endif //PAA_TRAB1_GRAFOMENORCAMINHO_H
