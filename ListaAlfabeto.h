#ifndef PAA_TRAB1_LISTAALFABETO_H
#define PAA_TRAB1_LISTAALFABETO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "ArvoreBinaria.h"


typedef struct noListaAlfabeto{ //estrutura para lista encadeada após organizar as frequências
    arvore *arvore;
    struct noListaAlfabeto *prox; // ponteiro para próximo elemento
} alfabeto;

// Cria um nó da estrutura alfabeto vazio e o retorna.
alfabeto *criaNoAlfabeto();

// Testa se um alfabeto é vazio.
// 1 - É vazio
// 0 - Não é vaizo
int ehVazioNoAlfabeto(alfabeto *l);

// Insere o nó da arvore no alfabeto, ou criando um novo nó, ou substituindo um que já existe. O alfabeto fica organizado em ordem crescente de frequência.
alfabeto* insereAlfabeto(alfabeto *l, arvore *a);

// Reorganiza o alfabeto em ordem crescente de frequência, se necessário.
// Pré-condição: lCabeça ser a cabeça do alfabeto. l é o nó que vai testar se é necessário mudança.
alfabeto *organizaAlfabeto (alfabeto *lCabeca, alfabeto *l);

// Retira a cabeça do alfabeto e substitui ela pelo próximo nó.
alfabeto* retiraCabecaListaAlfabeto(alfabeto *l);

// Retorna o tamanho do alfabeto.
int tamanhoListaAlfabeto(alfabeto *l);

// Busca um símbolo no alfabeto e retorna ou o nó em que ele está, ou nulo caso não encontre.
alfabeto* buscaListaArvore(alfabeto *l, wchar_t *buffer);

#endif //PAA_TRAB1_LISTAALFABETO_H
