#include "GrafoMenorCaminho.h"

void Relax (GrafoMenorCaminho *u, GrafoMenorCaminho *v) {
    ListaVertices *aux = v->adj;
    while (aux->valorNo != u->v){
        aux = aux->prox;
    }
    if( v->d > (u->d + aux->peso) ){      // custo pode ser diminuído
        v->d = (u->d + aux->peso);        // atualiza o custo
        v->pi = u->v;                      // armazena o predecessor
    }
}

GrafoMenorCaminho ** InicializaOrigem (Grafo *g, int origem){
    GrafoMenorCaminho ** aux = malloc(g->numVertices * sizeof(GrafoMenorCaminho*));
    for (int i = 0; i < g->numVertices; ++i) {
        aux[i] = malloc(sizeof(GrafoMenorCaminho));
        aux[i]->g = g;
        aux[i]->v = i;
        aux[i]->d = INT_MAX;
        aux[i]->pi = -1;
        aux[i]->adj = g->listaVertices[i];
    }
    aux[origem]->d = 0;                    // distância da origem para ela mesma é zero
    return aux;
}