#ifndef PAA_TRAB1_ARVOREBINARIA_H
#define PAA_TRAB1_ARVOREBINARIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

typedef struct noArvore {
    wchar_t *simbolo;
    int frequencia;
    struct noArvore *esq; // subárvore esquerda
    struct noArvore *dir; // subárvore direita
} arvore;

// Cria um nó da estrutura arvore, já com um símbolo e frequência.
arvore *criaArvoreSimbolos(wchar_t *simbolo, int frequencia);

// Retorna o ponteiro de um novo nó de árvore, uma cópia do parâmetro.
arvore *insereSimboloArvore(arvore *a);

// Testa se uma árvore é vazia
// 1 - é vazio
// 0 - não é vazio
int ehVaziaArvore(struct noArvore *a);

// Testa se um nó é folha
// 1 - é folha
// 0 - não é folha
int ehFolha(struct noArvore *a);

// Retorna a altura da árvore.
int tamanhoArvore(arvore *a);

#endif //PAA_TRAB1_ARVOREBINARIA_H
