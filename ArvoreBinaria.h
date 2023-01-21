#ifndef PAA_TRAB1_ARVOREBINARIA_H
#define PAA_TRAB1_ARVOREBINARIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noArvore {
    char* simbolo;
    int frequencia;
    struct noArvore * esq; // subárvore esquerda
    struct noArvore * dir; // subárvore direita
};

typedef struct noArvore* arvore; //árvore é um ponteiro para um nó

// Testa se uma árvore é vazia
int ehVaziaArvore(arvore r);



#endif //PAA_TRAB1_ARVOREBINARIA_H
