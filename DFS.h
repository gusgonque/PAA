#ifndef PAA_TRAB1_DFS_H
#define PAA_TRAB1_DFS_H

#include "Grafos.h"

typedef struct GrafoDFS {
    Grafo *u;
    char *cor;  // usado para indicar em que etapa se econtra aexploração do vértice
                // branco: não explorado
                // cinza: explorado, mas ainda sem explorar os adjacentes
                // preto: explorado e vértices adjacentes também explorados

    int pi;     // indica quem prescede u no grafo de busca
    int d;      // timestamp de descoberta do u
    int f;      // timestamp de término da exploração do u e dos vértices adjacentes a u
}GrafoDFS;

#endif //PAA_TRAB1_DFS_H
