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

ListaVertices **criaListaVerticesAdjacentes(int numVertices){
    ListaVertices **lAux = malloc(numVertices * sizeof (ListaVertices *));
    for (int i = 0; i < numVertices; ++i) {
        lAux[i] = NULL;
    }
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

ListaVertices *insereVertice(ListaVertices *l, int i, int peso) {
    if(l!=NULL && i>l->valorNo) {
        l->prox = insereVertice(l->prox,i,peso);
        return l;
    } else {
        ListaVertices *lAux = malloc(sizeof(ListaVertices));
        lAux->valorNo = i;
        lAux->peso = peso;
        lAux->prox = l; // muda a cabeça.
        return lAux;
    }
}

ListaVertices *removeCabecaListaVertices (ListaVertices *l){
    if(l != NULL) {
        ListaVertices *lAux = l->prox;
        free(l);
        return lAux;
    }
    return l;
}

void carregaVertices(Grafo *g) {
    g->listaVertices = criaListaVerticesAdjacentes(g->numVertices);
    ListaAresta *lAux = g->listaArestas;
    int i;

    while (lAux != NULL) {
        for (i = 0; i < g->numVertices; ++i) {
            if(lAux->v == i){
                if(g->orientacao)
                    g->listaVertices[lAux->u] = insereVertice(g->listaVertices[lAux->u], lAux->v, lAux->peso);
                else {
                    g->listaVertices[lAux->u] = insereVertice(g->listaVertices[lAux->u], lAux->v, lAux->peso);
                    g->listaVertices[lAux->v] = insereVertice(g->listaVertices[lAux->v], lAux->u, lAux->peso);
                }
                break;
            }
        }
        lAux = lAux->prox;
    }
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

    carregaVertices(gAux);

    return gAux;
}

void plotaGrafo(Grafo *Grafo, char *nomArq){
    if(Grafo->numVertices == 0) {
        wprintf(L" Grafo não carregado!\n");
        return;
    }

    GVC_t *gvc;
    gvc = gvContext();

    Agraph_t *g;
    if(Grafo->orientacao)
        g = agopen("Grafo", Agdirected, NULL);
    else
        g = agopen("Grafo", Agundirected, NULL);

    // Cria os nós no agraph
    for (int i = 0; i < Grafo->numVertices; i++) {
        char nome[20];
        sprintf(nome, "%d", i);
        agnode(g, nome, 1);
    }

    // Cria as arestas no agraph
    for (ListaAresta* lA = Grafo->listaArestas; lA != NULL; lA = lA->prox) {
        char nome1[20], nome2[20], peso[20];
        sprintf(nome1, "%d", lA->u);
        sprintf(nome2, "%d", lA->v);
        sprintf(peso, "%d", lA->peso);
        Agnode_t* node1 = agnode(g, nome1, 0);
        Agnode_t* node2 = agnode(g, nome2, 0);
        Agedge_t *edge = agedge(g, node1, node2, NULL, 1);
        agsafeset(edge, "label", peso, "");
    }

    char *nomArqDot = malloc(50 * sizeof(char));
    strcpy(nomArqDot, nomArq);
    strcat(nomArqDot, ".dot");

    char *nomArqPng = malloc(50 * sizeof(char));
    strcpy(nomArqPng, nomArq);
    strcat(nomArqPng, ".png");

    gvLayout(gvc, g, "dot");
    gvRenderFilename(gvc, g, "dot", nomArqDot);
    gvFreeLayout(gvc, g);

    agclose(g);

    gvFreeContext(gvc);

    char comando[100];
    sprintf(comando, "dot -Tpng %s -o %s", nomArqDot, nomArqPng);
    system(comando);

    wprintf(L" Arquivos criados com sucesso, com os nomes '%s' e '%s'!\n\n",nomArqDot,nomArqPng);

    free(nomArqDot);
    free(nomArqPng);
}
