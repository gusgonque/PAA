#ifndef PAA_TRAB1_ARVOREBINARIA_H
#define PAA_TRAB1_ARVOREBINARIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noArvore {
    char simbolo [100];
    int frequencia;
    struct noArvore * esq; // subárvore esquerda
    struct noArvore * dir; // subárvore direita
};

// Testa se uma árvore é vazia
int ehVaziaArvore(struct noArvore* a);

int ehFolha(struct noArvore* a);

struct noArvore* insereArvoreBinaria(struct noArvore* a, char simbolo[], int frequencia);

#endif //PAA_TRAB1_ARVOREBINARIA_H
