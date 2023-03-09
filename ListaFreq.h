#ifndef PAA_LISTAFREQ_H
#define PAA_LISTAFREQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "ArvoreFreq.h"


typedef struct noListaAlfabeto{ //estrutura para lista encadeada após organizar as frequências
    ArvoreFreq *arvore;
    struct noListaAlfabeto *prox; // ponteiro para próximo elemento
} ListaFreq;

// Cria um nó da estrutura ListaFreq vazio e o retorna.
ListaFreq *criaNoLF();

// Testa se um ListaFreq é vazio.
// 1 - É vazio
// 0 - Não é vaizo
int ehVazioNoLF(ListaFreq *l);

// Insere o nó da ArvoreFreq no ListaFreq, ou criando um novo nó, ou substituindo um que já existe. O ListaFreq fica organizado em ordem crescente de frequência.
ListaFreq* insereLF(ListaFreq *l, ArvoreFreq *a);

// Reorganiza o ListaFreq em ordem crescente de frequência, se necessário.
// Pré-condição: lCabeça ser a cabeça do ListaFreq. l é o nó que vai testar se é necessário mudança.
ListaFreq *organizaLF (ListaFreq *lCabeca, ListaFreq *l);

// Retira a cabeça do ListaFreq e substitui ela pelo próximo nó.
ListaFreq* retiraCabecaLF(ListaFreq *l);

// Retorna o tamanho do ListaFreq.
int tamanhoLF(ListaFreq *l);

// Busca um símbolo no ListaFreq e retorna ou o nó em que ele está, ou nulo caso não encontre.
ListaFreq* buscaLF(ListaFreq *l, wchar_t *buffer);

#endif //PAA_LISTAFREQ_H
