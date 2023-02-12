#include "BFS.h"

void BFS_visit(Grafo *g, int s){
    ListaVertices *Q = NULL;
    GrafoBFS *gBFS = malloc(g->numVertices * sizeof  (GrafoBFS));
    ListaVertices *lAux = NULL;

    for (int i = 0; i < g->numVertices; ++i) {
        gBFS[i].cor = 'B';
        gBFS[i].f = -1;
        gBFS[i].pi = -1;
        gBFS[i].d = -1;
        gBFS[i].adj = g->listaVertices[i];
        gBFS[i].g = g;
    }
    gBFS[s].cor = 'C';
    printf(" [%d] ", s);
    gBFS[s].d = 0;
    gBFS[s].pi = -1;
    Q = insereVertice(Q,s,-1);
    while (Q != NULL){
        s = Q->valorNo;
        lAux = g->listaVertices[s];
        while (lAux != NULL){
            if(gBFS[lAux->valorNo].cor == 'B'){
                gBFS[lAux->valorNo].cor = 'C';
                printf("- [%d] ", lAux->valorNo);
                gBFS[lAux->valorNo].d = gBFS[s].d + 1;
                gBFS[lAux->valorNo].pi = s;
                Q = insereVertice(Q,lAux->valorNo,-1);
            }
            lAux = lAux->prox;
        }
        Q = removeCabecaListaVertices(Q);
        gBFS[s].cor = 'P';
    }
    printf("\n");
}