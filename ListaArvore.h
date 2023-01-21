#ifndef PAA_TRAB1_LISTAARVORE_H
#define PAA_TRAB1_LISTAARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h"


typedef struct noLista { //estrutura para lista encadeada após organizar as frequências
    struct noArvore no;
    struct noLista * prox; // ponteiro para próximo elemento
} ListaArvore;

ListaArvore* criaNoLista(arvore no);

int ehVazioLista(ListaArvore* l);

ListaArvore *insereLista(ListaArvore *l, arvore no);

ListaArvore * retiraCabecaLista(ListaArvore* l);

int tamanhoLista(ListaArvore* l);

ListaArvore* buscaLista(ListaArvore* l, char* buffer);

#endif //PAA_TRAB1_LISTAARVORE_H
