#include "Grafos.h"

Grafo *criaGrafo(){
    Grafo *gAux = (Grafo *) malloc(sizeof(Grafo));
    gAux->listaVertices = NULL;
    gAux->listaArestas = NULL;
    gAux->numVertices = 0;
    gAux->orientacao = 0;
    return gAux;
}

ListaAresta *criaListaAresta(){
    ListaAresta *lAux = (ListaAresta *) malloc(sizeof (ListaAresta));
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

// todo: fazer essa função
ListaVertices **carregaVertices(Grafo g){

}

Grafo * carregaGrafo(FILE *arq) {
    Grafo *gAux = criaGrafo();
    char *strAux = malloc(3*sizeof (char ));

    fscanf(arq,"%*10c%3s%*c",strAux);

    gAux->orientacao = (strcmp(strAux,"sim") == 0);


    fscanf(arq,"%*2c%d%*c", &(gAux->numVertices));

    int peso;
    unsigned int u, v;
    while(feof(arq) == 0){
        fscanf(arq,"%*c%u%*c%u%*2c%d%*c", &u, &v, &peso);
        gAux->listaArestas = insereListaAresta(gAux->listaArestas,u,v,peso);
    }

//    gAux->listaVertices = carregaVertices(gAux);

    return gAux;
}
