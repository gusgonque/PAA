#ifndef PAA_TRAB1_DIJKSTRA_H
#define PAA_TRAB1_DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"

void relax(Grafo *g, ListaVertices * u, ListaVertices *v, int *dist, int *pred, int i);

void inicializaorigem(Grafo *g, ListaVertices * s, int *dist, int *pred);

int *dijkstra(Grafo * g, ListaVertices *s);

#endif