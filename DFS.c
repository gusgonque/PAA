#include "DFS.h"

void DFS_visit(GrafoDFS *gDFS, int u, int *t) {
    ListaVertices *lAux = gDFS[u].adj;

    gDFS[u].cor = 'C';
    printf(" [%d] ",u);
    (*t) ++;
    gDFS[u].d = *t;

    while (lAux != NULL){
        if(gDFS[lAux->valorNo].cor == 'B'){
            printf("-");
            gDFS[lAux->valorNo].pi = u;
            DFS_visit(gDFS, lAux->valorNo, t);
        }
        lAux = lAux->prox;
    }
    gDFS[u].cor = 'P';
    (*t) ++;
    gDFS[u].f = *t;
}

void DFS(Grafo *g, int v) {
    int *t = malloc(sizeof(int)); // Timestamp
    GrafoDFS *gDFS = malloc(g->numVertices * sizeof (GrafoDFS)); // Vetor para indicar cada vértice do grafo.
    for (int i = 0; i < g->numVertices; ++i) {
        gDFS[i].cor = 'B';
        gDFS[i].pi = -1;
        gDFS[i].f = -1;
        gDFS[i].d = -1;
        gDFS[i].adj = g->listaVertices[i];
        gDFS[i].g = g;
    }
    *t = 0;
    DFS_visit(gDFS, v, t);
    printf("\n");
    free(gDFS);
    free(t);
}
