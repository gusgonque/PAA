#ifndef PAA_TRAB1_GRAFOS_H
#define PAA_TRAB1_GRAFOS_H

// Funções e Estruturas de Grafos gerais.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:/Program Files/Graphviz/include/graphviz/gvc.h"
// LEMBRAR DE MUDAR O INCLUDE

typedef struct noListaAresta{
    unsigned int u, v;
    int peso;
    struct noListaAresta *prox;
} ListaAresta;

typedef struct noListaVertices {
    int valorNo; // Valor do nó/vértice adjacente.
    int peso; // Valor do peso do caminho da aresta para esse nó.
    struct noListaVertices *prox; // Próximo nó/vértice adjacente.
} ListaVertices;

typedef struct Grafo {
    int orientacao; // 1 - sim, 0 - não.
    int numVertices;
    ListaAresta *listaArestas; // ponteiro para a lista de listaArestas
    ListaVertices **listaVertices; // vetor de lista de vértices, cada instância do vetor é um vértice, e os nós da lista em cadeia são os vértices adjacentes.
} Grafo;

// Cria um Grafo vazio.
Grafo *criaGrafo();

// Cria uma lista de Arestas vazia.
ListaAresta *criaListaAresta();

// Cria um vetor de lista de Vertices vazio.
ListaVertices **criaListaVerticesAdjacentes(int numVertices);

// Insere os dados de uma aresta, em um novo nó na lista passada como parâmetro. Retorna a nova cabeça da lista.
ListaAresta *insereListaAresta(ListaAresta *l, unsigned int u, unsigned int v, int peso);

// Remove a cabeça da lista de vértices, e retorna o próximo nó dessa.
ListaVertices *removeCabecaListaVertices (ListaVertices *l);

// Insere os dados de um vértice, em um novo nó na lista passada como parâmetro. Retorna a nova cabeça da lista.
ListaVertices *insereVertice(ListaVertices *l, int i, int peso);

// Carrega a lista dos vértices, a partir da lista de arestas do grafo. As listas estarão em ordem crescente.
void carregaVertices(Grafo *g);

// Carrega os dados do grafo, a partir do arquivo aberto.
// Pré-condiçãp: arquivo dado pelo parâmetro arq, aberto.
Grafo *carregaGrafo(FILE *arq);

// Desenha o grafo em um arquivo .dot e .png
void plotaGrafo(Grafo *Grafo, char *nomArq);

#endif //PAA_TRAB1_GRAFOS_H
