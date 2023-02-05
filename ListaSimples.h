#ifndef PAA_TRAB1_LISTASIMPLES_H
#define PAA_TRAB1_LISTASIMPLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NoListaSimples { //estrutura para lista encadeada
    char * simbolo;
    char * codigo;
    struct NoListaSimples * prox; // ponteiro para próximo elemento
} ;


struct NoListaSimples* insereListaSimples(struct NoListaSimples* l, char *simbolo, char *frequencia);

int ehVazioListaSimples(struct NoListaSimples* l);

struct NoListaSimples* buscaListaSimples (struct NoListaSimples* l, char* simbolo);

#endif //PAA_TRAB1_LISTASIMPLES_H
