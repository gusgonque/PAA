#ifndef PAA_TRAB1_DFS_H
#define PAA_TRAB1_DFS_H

#include <stdio.h>
#include "Grafos.h"

typedef struct GrafoDFS {
    Grafo *g;   // Ponteiro para o Grafo usado.
    char cor;   // Usado para indicar em que etapa se econtra aexploração do vértice.
                // B: não explorado.
                // C: explorado, mas ainda sem explorar os adjacentes.
                // P: explorado e vértices adjacentes também explorados.

    int pi;     // Indica quem prescede esse nó no grafo de busca.
    int d;      // Timestamp de descoberta desse nó.
    int f;      // Timestamp de término da exploração desse nó e dos vértices adjacentes a esse.
    ListaVertices *adj; // Ponteiro para a lista de vértices adjacentes a esse;
}GrafoDFS;

// Visita o grafo na posição u, e visita os vértices adjacentes a ele, que estão com a cor = 'B'.
void DFS_visit(GrafoDFS *gDFS, int u, int *t);

// Inicia um GrafoDFS vazio, e a partir do vértice inicial v, percorre o grafo a partir do algoritmo de busca em profundidade.
void DFS(Grafo *g, int v);

#endif //PAA_TRAB1_DFS_H
