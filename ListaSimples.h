#ifndef PAA_TRAB1_LISTASIMPLES_H
#define PAA_TRAB1_LISTASIMPLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

typedef struct NoListaSimples { //estrutura para lista encadeada
    wchar_t *simbolo;
    char *codigo;
    struct NoListaSimples *prox; // ponteiro para próximo elemento
}listaSimples;

// Cria um novo nó da lista, com um símbolo e um código, e retorna esse nó
listaSimples *insereListaSimples(listaSimples *l, wchar_t *simbolo, char *codigo);

// Testa se a lista é vazia.
// 1 - é vazio
// 0 - não é vazio
int ehVazioListaSimples(listaSimples *l);

// Busca na lista o simbolo passado como parâmetro, e retorna o nó da lista ou nulo, se não o encontrou.
listaSimples* buscaListaSimples (listaSimples* l, wchar_t *simbolo);

// Retorna o número de nós na lista.
int tamanhoListaSimple(listaSimples *l);

#endif //PAA_TRAB1_LISTASIMPLES_H
