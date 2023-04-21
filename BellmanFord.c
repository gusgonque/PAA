#include "BellmanFord.h"

int VerificaBellmanFord (Grafo *G){
    return G->orientacao;
}

void ImprimeMenorCaminho(GrafoMenorCaminho **Q, int valor, int origem) {
    if (Q[valor]->pi != -1) {
        ImprimeMenorCaminho(Q, Q[valor]->pi, origem);
    }
    if(Q[valor]->v != origem)
        wprintf(L"-");
    wprintf(L" %d ", valor);
}

void BellmanFord(Grafo *grafo, int origem) {
    if(VerificaBellmanFord(grafo) == 0) {
        wprintf(L"Não é possível aplicar o algoritmo de Bellman-Ford - Grafo não é orientado.\n");
        return;
    }

    int i;
    int numVertices = grafo->numVertices;
    GrafoMenorCaminho ** Q = InicializaOrigem(grafo, origem);

    // Relaxando as arestas V-1 vezes
    for (i = 0; i < numVertices-1; i++) {
        ListaAresta *aresta = grafo->listaArestas;
        while (aresta != NULL) {
            int u = aresta->u;
            int v = aresta->v;
            int peso = aresta->peso;
            if (Q[u]->d != INT_MAX && Q[u]->d + peso < Q[v]->d) {
                Q[v]->d = Q[u]->d + peso;
                Q[v]->pi = Q[u]->v;
            }
            aresta = aresta->prox;
        }
    }

    // Verificando se há ciclos negativos
    for (i = 0; i < numVertices-1; i++) {
        ListaAresta *aresta = grafo->listaArestas;
        while (aresta != NULL) {
            int u = aresta->u;
            int v = aresta->v;
            int peso = aresta->peso;
            if (Q[u]->d != INT_MAX && Q[u]->d + peso < Q[v]->d) {
                wprintf(L"O grafo contém um ciclo negativo. Retornando ao menu anterior.\n");
                return;
            }
            aresta = aresta->prox;
        }
    }

    wprintf(L"Origem: %d\n", origem);
    for (i = 0; i < grafo->numVertices; ++i) {
        if(Q[i]->d == INT_MAX)
            wprintf(L"Destino: %d Distância: -- Caminho: --\n", i, Q[i]->d);
        else {
            wprintf(L"Destino: %d Distância: %d Caminho: ", i, Q[i]->d);
            ImprimeMenorCaminho(Q, i, origem);
            wprintf(L"\n");
        }
    }
}
