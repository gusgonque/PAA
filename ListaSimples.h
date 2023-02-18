#ifndef PAA_LISTASIMPLES_H
#define PAA_LISTASIMPLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

typedef struct NoListaSimples { //estrutura para lista encadeada
    wchar_t *simbolo;
    char *codigo;
    struct NoListaSimples *prox; // ponteiro para próximo elemento
}ListaSimples;

// Cria um novo nó da lista, com um símbolo e um código, e retorna esse nó
ListaSimples *insereListaSimples(ListaSimples *l, wchar_t *simbolo, char *codigo);

// Testa se a lista é vazia.
// 1 - é vazio
// 0 - não é vazio
int ehVazioListaSimples(ListaSimples *l);

// Busca na lista o simbolo passado como parâmetro, e retorna o nó da lista ou nulo, se não o encontrou.
ListaSimples* buscaListaSimples (ListaSimples* l, wchar_t *simbolo);

// Retorna o número de nós na lista.
int tamanhoListaSimple(ListaSimples *l);

#endif //PAA_LISTASIMPLES_H
