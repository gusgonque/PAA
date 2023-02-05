#ifndef PAA_TRAB1_ARVOREBINARIA_H
#define PAA_TRAB1_ARVOREBINARIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noArvore {
    char * simbolo;
    int frequencia;
    struct noArvore * esq; // subárvore esquerda
    struct noArvore * dir; // subárvore direita
};

struct noArvore *criaArvoreSimbolos();

void insereSimboloArvore(struct noArvore * arvore, char * simbolo, int frequencia);

// Testa se uma árvore é vazia
int ehVaziaArvore(struct noArvore* a);

int ehFolha(struct noArvore* a);

#endif //PAA_TRAB1_ARVOREBINARIA_H
