#ifndef PAA_TRAB1_LISTAARVORE_H
#define PAA_TRAB1_LISTAARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h"


struct noListaArvore{ //estrutura para lista encadeada após organizar as frequências
    struct noArvore* a;
    struct noListaArvore* prox; // ponteiro para próximo elemento
};

struct noListaArvore* criaNoListaArvore(struct noArvore* a);

int ehVazioNoListaArvore(struct noListaArvore *l);

struct noListaArvore *insereListaArvore(struct noListaArvore *l, struct noArvore* a);

struct noListaArvore * retiraCabecaListaArvore(struct noListaArvore* l);

int tamanhoListaArvore(struct noListaArvore* l);

struct noListaArvore* buscaListaArvore(struct noListaArvore* l, char* buffer);

#endif //PAA_TRAB1_LISTAARVORE_H
