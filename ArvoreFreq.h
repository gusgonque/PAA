#ifndef PAA_ARVOREFREQ_H
#define PAA_ARVOREFREQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

typedef struct noArvore {
    wchar_t *simbolo;
    int frequencia;
    struct noArvore *esq; // subárvore esquerda
    struct noArvore *dir; // subárvore direita
} ArvoreFreq;

// Cria um nó da estrutura ArvoreFreq, já com um símbolo e frequência.
ArvoreFreq *criaAF(wchar_t *simbolo, int frequencia);

// Retorna o ponteiro de um novo nó de árvore, uma cópia do parâmetro.
ArvoreFreq *insereSimboloAF(ArvoreFreq *a);

// Testa se uma árvore é vazia
// 1 - é vazio
// 0 - não é vazio
int ehVaziaAF(struct noArvore *a);

// Testa se um nó é folha
// 1 - é folha
// 0 - não é folha
int ehFolhaAF(struct noArvore *a);

// Retorna a altura da árvore.
int tamanhoAF(ArvoreFreq *a);

#endif //PAA_ARVOREFREQ_H
