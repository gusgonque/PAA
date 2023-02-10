#ifndef PAA_TRAB1_GRAFOS_H
#define PAA_TRAB1_GRAFOS_H

// Funções e Estruturas de Grafos gerais.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noListaAresta{
    unsigned int u, v;
    int peso;
    struct noListaAresta *prox;
} ListaAresta;

typedef struct noListaVertices {
    int valor;
    struct noListaVertices *prox;
} ListaVertices;

typedef struct Grafo {
    int orientacao; // 1 - sim, 0 - não.
    int numVertices;
    ListaAresta *listaArestas; // ponteiro para a lista de listaArestas
    ListaVertices **listaVertices; // vetor de lista de vértices, cada instância do vetor é um vértice, e os nós da lista em cadeia são os vértices adjacentes desse vértice.
} Grafo;

// Cria um Grafo vazio.
Grafo *criaGrafo();

// Cria uma lista de Arestas vazia.
ListaAresta *criaListaAresta();

// Insere os dados de uma aresta, em um novo nó na lista passada como parâmetro. Retorna a nova cabeça da lista.
ListaAresta *insereListaAresta(ListaAresta *l, unsigned int u, unsigned int v, int peso);

// Carrega a lista dos vértices, a partir da lista de arestas do grafo. As listas estarão em ordem crescente.
ListaVertices **carregaVertices(Grafo g);

// Carrega os dados do grafo, a partir do arquivo aberto.
// Pré-condiçãp: arquivo dado pelo parâmetro arq, aberto.
Grafo *carregaGrafo(FILE *arq);



#endif //PAA_TRAB1_GRAFOS_H
