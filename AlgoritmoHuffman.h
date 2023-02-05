#ifndef PAA_TRAB1_ALGORITMOHUFFMAN_H
#define PAA_TRAB1_ALGORITMOHUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "ListaAlfabeto.h"
#include "ListaSimples.h"

struct noListaAlfabeto* determinaAlfabeto(char* buffer, int tipoCod);

struct noArvore* montaArvore(struct noListaAlfabeto *l);

void determinaFrequenciaDFS(struct noArvore* a, char* codigo, int tamCodigo, struct NoListaSimples* l);

char* codificaHuffman (char* buffer, struct noArvore* a, int tipoCod, struct NoListaSimples *lFreq);

#endif //PAA_TRAB1_ALGORITMOHUFFMAN_H
