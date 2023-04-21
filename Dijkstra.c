#include "Dijkstra.h"

int VerificaDijkstra (Grafo *G){
    ListaAresta * aux = G->listaArestas;
    for (int i = 0; i < G->numVertices; ++i) {
        if (aux->peso < 0)
            return 0;
    }
    return 1;
}

int ExtraiMinimo(int *q, GrafoMenorCaminho **Q, int *tq) {
    int menor = 0;
    int j=0;
    for (int i = 0; i < *tq; ++i) {
        if(Q[q[i]]->d<Q[q[j]]->d) {
            menor = q[i];
            j = i;
        }
    }
    (*tq)--;
    for ( ; j < *tq; ++j) {
        q[j] = q[j+1];
    }
    return menor;
}

void Dijkstra(Grafo * G, int s){
    if(VerificaDijkstra(G) == 0) {
        wprintf(L"Não é possível aplicar o algoritmo de Dijkstra - Grafo possui arestas de peso negativo.\n");
        return;
    }

    FilaSimples * S = NULL;

    GrafoMenorCaminho ** Q = InicializaOrigem(G, s);

    int * q = malloc(G->numVertices * sizeof(int));
    for (int i = 0; i < G->numVertices; ++i)
        q[i] = Q[i]->v;

    int u;
    int *tq = malloc(sizeof(int));
    *tq = G->numVertices;

    while (*tq > 0) {
        u = ExtraiMinimo(q, Q, tq);
        ListaVertices *aux = G->listaVertices[u];
        S = insereFS(S,u);
        while (aux != NULL){
            Relax(Q[u], Q[aux->valorNo]);
            aux = aux->prox;
        }
    }

    wprintf(L"Origem: %d\n", s);
    for (int i = 0; i < G->numVertices; ++i) {
        if(Q[i]->d == INT_MAX)
            wprintf(L"Destino: %d Distância: -- Caminho: --\n", i, Q[i]->d);
        else {
            wprintf(L"Destino: %d Distância: %d Caminho: ", i, Q[i]->d);
            ImprimeCaminho(Q, S, i);
        }
    }
}

void ImprimeCaminho(GrafoMenorCaminho ** QRaiz, FilaSimples * S, int s){
    PilhaSimples *P = NULL;
    int u = s;
    while (u != -1) {
        P = inserePS(P, u);
        u = QRaiz[u]->pi;
    }
    while (P!=NULL) {
        wprintf(L" %d ", P->valorNo);
        P = removePS(P);
        if(P!=NULL)
            wprintf(L"-");
    }
    wprintf(L"\n");
}
