#ifndef PAA_TRAB1_FILAPILHA_H
#define PAA_TRAB1_FILAPILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct noFilaSimples{
    int valorNo;
    struct noFilaSimples *prox;
}FilaSimples;

typedef struct noPilhaSimples{
    int valorNo;
    struct noPilhaSimples *prox;
}PilhaSimples;

// Cria uma Fila simples com o valoe do nó passado como parâmetro.
FilaSimples *criaFS(int valor);

// Insere um novo nó na Fila passada como parâmetro, com o valor passado como parâmetro.
FilaSimples *insereFS(FilaSimples *F, int valor);

// Cria uma pilha simples com o valoe do nó passado como parâmetro.
PilhaSimples *criaPS(int valor);

// Insere um novo nó na pilha passada como parâmetro, com o valor passado como parâmetro.
PilhaSimples *inserePS(PilhaSimples *P, int valor);

// Remove um nó da pilha passada como parâmetro.
PilhaSimples *removePS(PilhaSimples *P);

#endif //PAA_TRAB1_FILAPILHA_H
