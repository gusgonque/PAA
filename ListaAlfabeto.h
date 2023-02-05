#ifndef PAA_TRAB1_LISTAALFABETO_H
#define PAA_TRAB1_LISTAALFABETO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h"


struct noListaAlfabeto{ //estrutura para lista encadeada após organizar as frequências
    struct noArvore * arvore;
    struct noListaAlfabeto * prox; // ponteiro para próximo elemento
};

struct noListaAlfabeto* criaNoAlfabeto();

int ehVazioNoAlfabeto(struct noListaAlfabeto *l);

struct noListaAlfabeto *insereAlfabeto(struct noListaAlfabeto *l, struct noArvore *a);

struct noListaAlfabeto * retiraCabecaListaAlfabeto(struct noListaAlfabeto* l);

int tamanhoListaArvore(struct noListaAlfabeto* l);

struct noListaAlfabeto* buscaListaArvore(struct noListaAlfabeto* l, char* buffer);

#endif //PAA_TRAB1_LISTAALFABETO_H
