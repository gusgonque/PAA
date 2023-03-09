#ifndef PAA_ALGORITMOHUFFMAN_H
#define PAA_ALGORITMOHUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "ListaFreq.h"
#include "ListaCod.h"

// Monta a árvore binária a partir de uma lista, agrupando símbolos conforme a frequência.
// Pré-condição: parâmetro l de frequência organizada.
// Pós-condição: parâmetro l não existe mais, retorna a árvore das frequências.
ArvoreFreq *montaAF(ListaFreq *l);

// Percorre a árvore utilizando o algoritmo de busca em profundidade (DFS) para obter uma tabela de frequências, no formato de uma lista.
ListaCod *determinaFrequenciaDFS(ArvoreFreq *a, char *codigo, int tamCodigo, ListaCod *l);

// Percorre o arquivo passado como parâmetro, lendo cada caracter e inserindo na lista retornada.
// tipoCod é para determinar se os símbolos são letras ou palavras. 1 = Letra / 0 = Palavra
ListaFreq *pegaListaFreqArq(FILE *arq, int tipoCod);

// Escreve a lista de códigos passada como parâmetro no arquivo.
void escreveListaCodArq(FILE *arq, ListaCod *lCod);

// Codifica o arq, usando a lista de códigos passada como parâmetro, no arq2.
// tipoCod é para determinar se os símbolos são letras ou palavras. 1 = Letra / 0 = Palavra
void codificaArq(FILE *arq, FILE *arq2, ListaCod *lCod, int tipoCod);

// Compacta um arquivo .txt em outro compactado .txt, com a lista de códigos na árvore, utilizando outras funções.
// tipoCod é para determinar se os símbolos são letras ou palavras. 1 = Letra / 0 = Palavra
void compactarArquivo(int tipoCod);

// Descompacta um arquivo .txt em outro descompactado .txt, com a lista de códigos na árvore, utilizando outras funções.
void descompactarArquivoLetra();

#endif //PAA_ALGORITMOHUFFMAN_H
