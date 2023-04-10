#ifndef PAA_TRAB2_BFS_H
#define PAA_TRAB2_BFS_H

#include <stdio.h>
#include "Grafos.h"

typedef struct GrafoBFS {
    Grafo *g;   // Ponteiro para o Grafo usado.
    char cor;   // Usado para indicar em que etapa se econtra aexploração do vértice.
    // B: não explorado.
    // C: explorado, mas ainda sem explorar os adjacentes.
    // P: explorado e vértices adjacentes também explorados.

    int pi;     // Indica quem prescede esse nó no grafo de busca.
    int d;      // Distância do vértice inicial até esse vértice.
    int f;      // Timestamp de término da exploração desse nó e dos vértices adjacentes a esse.
    ListaVertices *adj; // Ponteiro para a lista de vértices adjacentes a esse;
}GrafoBFS;

void BFS_visit(Grafo *g, int s);

#endif //PAA_TRAB2_BFS_H
