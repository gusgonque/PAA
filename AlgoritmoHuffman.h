#ifndef PAA_TRAB1_ALGORITMOHUFFMAN_H
#define PAA_TRAB1_ALGORITMOHUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "ListaAlfabeto.h"
#include "ListaSimples.h"


// Cria uma lista com a frequência dos símbolos, já organizada.
// tipoCod é para determinar se vai codificar por letra ou palavra
// 1 — Letra
// 0 — palavra
alfabeto *determinaAlfabeto(wchar_t *buffer, int tipoCod, alfabeto *l);

// Monta a árvore binária a partir de uma lista, agrupando símbolos conforme a frequência.
// Pré-condição: parâmetro l de frequência organizada.
// Pós-condição: parâmetro l não existe mais, retorna a árvore das frequências.
arvore *montaArvore(alfabeto *l);

// Percorre a árvore utilizando o algoritmo de busca em profundidade (DFS) para obter uma tabela de frequências, no formato de uma lista.
listaSimples *determinaFrequenciaDFS(arvore *a, char *codigo, int tamCodigo, listaSimples *l);

// CÓDIGO NÃO USADO, APENAS REFERÊNCIA
// A partir da árvore de frequência, codifica a frase buffer.
// tipoCod é para determinar se vai codificar por letra ou palavra
// 1 — Letra
// 0 — palavra
// Pré-condição: Tomar cuidado com o parâmetro lFreq.
char* codificaHuffman (char* buffer, struct noArvore* a, int tipoCod, struct NoListaSimples *lFreq);

#endif //PAA_TRAB1_ALGORITMOHUFFMAN_H
