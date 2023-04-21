#ifndef PAA_TRAB1_KURSKAL_H
#define PAA_TRAB1_KURSKAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"

// define um subgrafo com apenas um vertice e seu peso
typedef struct Subset {
    int parent;
    int rank;
} Subset;

void KruskalMST(Grafo* graph);
void Union(Subset *subsets, int x, int y);
void KruskalMST(Grafo* graph);

#endif