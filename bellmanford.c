#include "bellmanford.h"

FilaSimples *criaFS(int valor) {
    FilaSimples *aux = malloc(sizeof(FilaSimples));
    aux->valorNo = valor;
    return aux;
}

FilaSimples *insereFS(FilaSimples *F, int valor) {
    FilaSimples *aux = F;
    if(aux->prox!=NULL)
        aux = aux->prox;
    aux->prox = criaFS(valor);
    return aux->prox;
}

void imprimeFila (FilaSimples* F){
    FilaSimples *aux = F;
    printf("%d",aux->valorNo);
    aux = aux->prox;
    while (aux != NULL){
        printf(" - %d",aux->valorNo);
        aux = aux->prox;
    }
    printf("\n");
}

void BellmanFord(Grafo *grafo, int origem) {
    int i;
    int numVertices = grafo->numVertices;
    int dist[numVertices];
    FilaSimples *caminho = criaFS(origem);

    // Inicializando as distâncias com valor infinito
    for (i = 0; i < numVertices; i++)
        dist[i] = INT_MAX;
    dist[origem] = 0;

    // Relaxando as arestas V-1 vezes
    for (i = 0; i < numVertices-1; i++) {
        ListaAresta *aresta = grafo->listaArestas;
        while (aresta != NULL) {
            int u = aresta->u;
            int v = aresta->v;
            int peso = aresta->peso;
            if (dist[u] != INT_MAX && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                insereFS(caminho, v);
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
            if (dist[u] != INT_MAX && dist[u] + peso < dist[v]) {
                wprintf(L"O grafo contém um ciclo negativo\n");
                return;
            }
            aresta = aresta->prox;
        }
    }

    //Imprimindo a saída
    wprintf(L"Origem: %d\n", origem);
    // Imprimindo as distâncias mínimas
    for (i = 0; i < numVertices; i++) {
        wprintf(L"Destino: %d Distância: %d caminho: ", i, dist[i]);
        imprimeFila (caminho);
    }
}
