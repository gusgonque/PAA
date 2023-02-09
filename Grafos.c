#include "Grafos.h"

Grafo *criaGrafo(){
    Grafo *gAux = malloc(sizeof(Grafo));
    gAux->listaVertices = NULL;
    gAux->listaArestas = NULL;
    gAux->numVertices = 0;
    gAux->orientacao = 0;
    return gAux;
}

ListaAresta *criaListaAresta(){
    ListaAresta *lAux = malloc(sizeof (ListaAresta));
    lAux->prox = NULL;
    lAux->peso = 0;
    lAux->u = 0;
    lAux->v = 0;
    return lAux;
}

ListaAresta *insereListaAresta(ListaAresta *l, unsigned int u, unsigned int v, int peso){
    ListaAresta *lAux = criaListaAresta();
    lAux->peso = peso;
    lAux->u = u;
    lAux->v = v;
    lAux->prox = l; // muda a cabeça.
    return lAux;
}

Grafo * carregaGrafo(FILE *arq) {
    Grafo *gAux = criaGrafo();
    char strAux[3];

    fscanf(arq,"orientado=%3s\n",strAux); // todo: testar

    gAux->orientacao = (strcmp(strAux,"sim") == 0);

    fscanf(arq,"V=<%d>\n", &(gAux->numVertices)); // todo: testar

    int peso;
    unsigned int u, v;
    for (int i = 0; i < gAux->numVertices; ++i) {
        fscanf(arq,"(<%u>,<%u>):<%d>\n", &u, &v, &peso); // todo: testar
        gAux->listaArestas = insereListaAresta(gAux->listaArestas,u,v,peso);
    }

    return gAux;
}
