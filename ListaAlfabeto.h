#ifndef PAA_LISTAALFABETO_H
#define PAA_LISTAALFABETO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "ArvoreBinaria.h"


typedef struct noListaAlfabeto{ //estrutura para lista encadeada após organizar as frequências
    Arvore *arvore;
    struct noListaAlfabeto *prox; // ponteiro para próximo elemento
} Alfabeto;

// Cria um nó da estrutura Alfabeto vazio e o retorna.
Alfabeto *criaNoAlfabeto();

// Testa se um Alfabeto é vazio.
// 1 - É vazio
// 0 - Não é vaizo
int ehVazioNoAlfabeto(Alfabeto *l);

// Insere o nó da Arvore no Alfabeto, ou criando um novo nó, ou substituindo um que já existe. O Alfabeto fica organizado em ordem crescente de frequência.
Alfabeto* insereAlfabeto(Alfabeto *l, Arvore *a);

// Reorganiza o Alfabeto em ordem crescente de frequência, se necessário.
// Pré-condição: lCabeça ser a cabeça do Alfabeto. l é o nó que vai testar se é necessário mudança.
Alfabeto *organizaAlfabeto (Alfabeto *lCabeca, Alfabeto *l);

// Retira a cabeça do Alfabeto e substitui ela pelo próximo nó.
Alfabeto* retiraCabecaListaAlfabeto(Alfabeto *l);

// Retorna o tamanho do Alfabeto.
int tamanhoListaAlfabeto(Alfabeto *l);

// Busca um símbolo no Alfabeto e retorna ou o nó em que ele está, ou nulo caso não encontre.
Alfabeto* buscaListaArvore(Alfabeto *l, wchar_t *buffer);

#endif //PAA_LISTAALFABETO_H
