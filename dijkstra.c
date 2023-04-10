#include "dijkstra.h"

#define INF INT_MAX

//void relax(Grafo *g, ListaVertices * u, ListaVertices *v, int *dist, int *pred, int i){
//    if(v->peso > u->peso + g->listaArestas->peso){
//        dist[i] = pred[i-1] + v->peso;
//        pred[i] = dist[i];
//    }
//}
//
//void inicializaorigem(Grafo *g, ListaVertices * s, int *dist, int *pred){
//    int i = 0;
//    for(Grafo *v = g; v->listaVertices != NULL; v = v->prox){
//        dist[i] = INF;
//        pred[i] = NULL;
//        i++;
//    }
//    d[s] = 0;
//}
//
//int *dijkstra(Grafo * g, ListaVertices *s){
//    int dist[], pred[], i = 0;
//    inicializaorigem(g, s, dist, pred);
//    ListaVertices *S = NULL;
//    ListaVertices *Q = g->listaVertices;
//    while (Q!=NULL){
//        ListaVertices u = extraimenor(Q);
//        S[i] = u;
//        for(ListaVertices v = g->listaVertices; v != NULL; v = v->prox){
//            relax(g, u, v, dist, pred, i);
//        }
//        i++;
//    }
//}
