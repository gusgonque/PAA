#ifndef PAA_ALGORITMOHUFFMAN_H
#define PAA_ALGORITMOHUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "ListaFreq.h"
#include "ListaSimples.h"

// Monta a árvore binária a partir de uma lista, agrupando símbolos conforme a frequência.
// Pré-condição: parâmetro l de frequência organizada.
// Pós-condição: parâmetro l não existe mais, retorna a árvore das frequências.
ArvoreFreq *montaAF(ListaFreq *l);

// Percorre a árvore utilizando o algoritmo de busca em profundidade (DFS) para obter uma tabela de frequências, no formato de uma lista.
ListaCod *determinaFrequenciaDFS(ArvoreFreq *a, char *codigo, int tamCodigo, ListaCod *l);

// Percorre o arquivo passado como parâmetro, lendo cada caracter e inserindo na lista retornada.
ListaFreq *pegaListaFreqArqLetra(FILE *arq);

// Compacta um arquivo .txt em outro compactado .txt, com a lista de códigos na árvore, utilizando outras funções.
void compactarArquivoLetra();

// Compacta um arquivo .txt em outro compactado .txt, com a lista de códigos na árvore, utilizando outras funções.
void compactarArquivoPalavra();

// Descompacta um arquivo .txt em outro descompactado .txt, com a lista de códigos na árvore, utilizando outras funções.
void descompactarArquivoLetra();

#endif //PAA_ALGORITMOHUFFMAN_H
