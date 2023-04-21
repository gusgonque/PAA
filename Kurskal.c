//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "Kurskal.h"
//
////  uma funcao de utilidade que encontra o subgrafo de um elemento 1
//int find(Subset *subsets, int i) {
//    if (subsets[i].parent != i) {
//        subsets[i].parent = find(subsets, subsets[i].parent);
//    }
//    return subsets[i].parent;
//}
//
//// uma funcao de utilidade que une dois subgrafos
//void Union(Subset *subsets, int x, int y) {
//    int xroot = find(subsets, x);
//    int yroot = find(subsets, y);
//
//    // coloca uma arvore menor debaixo da raiz de uma arvore maior
//    if (subsets[xroot].rank < subsets[yroot].rank) {
//        subsets[xroot].parent = yroot;
//    } else if (subsets[xroot].rank > subsets[yroot].rank) {
//        subsets[yroot].parent = xroot;
//    } else {
//        subsets[yroot].parent = xroot;
//        subsets[xroot].rank++;
//    }
//}
//
////a funcao principal que constroi o MST usando o algoritimo de kruskal
//void KruskalMST(Grafo* graph) {
//    int V = graph->numVertices;
//    ListaAresta* arestas = graph->listaArestas;
//
//    // aloca memoria criando subgrafos V
//    Subset* subsets = (Subset*) malloc(V * sizeof(Subset));
//
//    // cria subgrafos V com unicos elementos
//    for (int v = 0; v < V; ++v) {
//        subsets[v].parent = v;
//        subsets[v].rank = 0;
//    }
//
//    // aloca memoria para o resultado
//    ListaAresta* resultado = NULL;
//    ListaAresta* atual = NULL;
//
//    // organiza todas as bordas em uma ordem nao decrecente de pesos
//    arestas = MergeSortListasAresta(arestas);
//
//    // itera todas as bordas organizadas
//    while (arestas != NULL) {
//        int u = arestas->u;
//        int v = arestas->v;
//        int peso = arestas->peso;
//
//        int setU = find(subsets, u);
//        int setV = find(subsets, v);
//
//        // se incluir essa borda nao resulta em ciclo inclui no resultado e incrementa o index do resultado pra proxima borda
//        if (setU != setV) {
//            // une os dois subgrafos encontrados anteriormente
//            Union(subsets, setU, setV);
//
//            // adiciona a borda no MST
//            if (resultado == NULL) {
//                resultado = (ListaAresta*) malloc(sizeof(ListaAresta));
//                resultado->u = u;
//                resultado->v = v;
//                resultado->peso = peso;
//                resultado->prox = NULL;
//                atual = resultado;
//            } else {
//                atual->prox = (ListaAresta*) malloc(sizeof(ListaAresta));
//                atual = atual->prox;
//                atual->u = u;
//                atual->v = v;
//                atual->peso = peso;
//                atual->prox = NULL;
//            }
//        }
//
//        // vai pra proxima borda
//        arestas = arestas->prox;
//    }
//
//    // imprime o MST construido
//    printf("Edges in the constructed MST:\n");
//    atual = resultado;
//    while (atual != NULL) {
//        printf("(%d %d)\n", atual->u, atual->v);
//    }
//}
