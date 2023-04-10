#include "FloydWarshall.h"

void floydWarshall(Grafo *grafo) {
    int dist[grafo->numVertices][grafo->numVertices];
    int i, j, k;

    // Inicializa a matriz distancia
    for (i = 0; i < grafo->numVertices; i++) {
        for (j = 0; j < grafo->numVertices; j++) {
            dist[i][j] = INT_MAX;
        }
        dist[i][i] = 0;
    }

    // coloca a distancia inicial baseado nas bordas do grafo
    ListaAresta *p = grafo->listaArestas;
    while (p != NULL) {
        dist[p->u][p->v] = p->peso;
        if (!grafo->orientacao) {
            dist[p->v][p->u] = p->peso;
        }
        p = p->prox;
    }

    // encontra o menor caminho entre todos os pares de vertices
    for (k = 0; k < grafo->numVertices; k++) {
        for (i = 0; i < grafo->numVertices; i++) {
            for (j = 0; j < grafo->numVertices; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // imprime todas as menores distancias
    for (i = 0; i < grafo->numVertices; i++) {
        for (j = 0; j < grafo->numVertices; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}
