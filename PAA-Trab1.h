#ifndef PAA_TRAB1_PAA_TRAB1_H
#define PAA_TRAB1_PAA_TRAB1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "ListaArvore.h"
#include "ListaSimples.h"

struct noListaArvore* determinarFrequencia(char* buffer, int tipoCod);

struct noListaArvore* organizaFrequencia (struct noListaArvore *l);

struct noArvore* montaArvore(struct noListaArvore *l);

void determinaFrequenciaDFS(struct noArvore* a, char* caminho, int tamCaminho, struct NoListaSimples* l);

char* codificaHuffman (char* buffer, struct noArvore* a, int tipoCod, struct NoListaSimples *lFreq);

#endif //PAA_TRAB1_PAA_TRAB1_H
