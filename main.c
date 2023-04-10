#include <stdio.h>
#include <locale.h>
#include "Trab2.h"

void menuPrincipal(Grafo *g) {
    wprintf(L"\tTela Principal! Digite a opção desejada:\n");
    wprintf(L" 1 - Carregar grafo de arquivo.\n");
    wprintf(L" 2 - Busca em Profundidade a partir de um dado vértice de origem do grafo.\n");
    wprintf(L" 3 - Busca em Largura a partir de um dado vértice de origem do grafo.\n");
    wprintf(L" 4 - Dijkstra: dado um vértice de origem, calcular os menores caminhos para os demais vértices.\n"); // Todo: Dijkstra
    wprintf(L" 5 - Bellman-Ford: dado um vértice de origem, calcular os menores caminhos para os demais vértices.\n"); // Todo: Bellman-Ford
    wprintf(L" 6 - Floyd-Warshall: o menor caminho entre todos os pares de vértices.\n"); // Todo: Floyd-Warshall
    wprintf(L" 7 - Kruskal: calcular árvore geradora mínima.\n"); // Todo: Kruskal
    wprintf(L" 8 - Prim: dado vértice inicial, calcular árvore geradora mínima.\n"); // Todo: Prim
    wprintf(L" 9 - Plotar grafo.\n"); // Todo: Plotar grafo
    wprintf(L" 0 - Finalizar programa.\n");
    printf(" - ");
    int x;
    scanf("%d",&x);
    switch (x) {
        case 1:
            free(g);
            g = carregaArquivoGrafo();
            menuPrincipal(g);
            break;
        case 2:
            if(g->numVertices != 0) {
                wprintf(L" Digite o valor do vértice de origem para busca.\n - ");
                scanf("%d", &x);
                DFS(g, x);
            } else
                wprintf(L" Grafo não carregado.\n");
            menuPrincipal(g);
            break;
        case 3:
            if(g->numVertices != 0) {
                wprintf(L" Digite o valor do vértice de origem para busca.\n - ");
                scanf("%d", &x);
                BFS_visit(g,x);
            } else
                wprintf(L" Grafo não carregado.\n");
            menuPrincipal(g);
            break;
        case 4:
            menuPrincipal(g);
            break;
        case 5:
            if(g->numVertices != 0 && g->orientacao == 1) {
                wprintf(L" Digite o valor do vértice de origem para busca.\n - ");
                scanf("%d", &x);
                BellmanFord(g, x);
            } else
                wprintf(L" Grafo inválido.\n");
            menuPrincipal(g);
            break;
        case 6:
            menuPrincipal(g);
            break;
        case 7:
            menuPrincipal(g);
            break;
        case 8:
            menuPrincipal(g);
            break;
        case 9:
            plotaGrafo(g,"Grafo");
            menuPrincipal(g);
            break;
        case 0:
            return;
        default:
            wprintf(L" Opção inválida.\n");
            menuPrincipal(g);
            break;
    }

}

int main() {
    Grafo *g = criaGrafo();

    setlocale(LC_ALL,"Portuguese");
    menuPrincipal(g);

    return 0;
}
