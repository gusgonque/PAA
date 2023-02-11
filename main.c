#include <stdio.h>
#include "Grafos.h"

//Busca em Profundidade a partir de um dado v´ertice de origem
//2. Busca em Largura a partir de um dado v´ertice de origem
//3. Dijkstra: dado um v´ertice de origem, calcular os menores caminhos para os demais v´ertices
//4. Bellman-Ford: dado um v´ertice de origem, calcular os menores caminhos para os demais v´ertices
//5. Floyd-Warshall: o menor caminho entre todos os pares de v´ertices
//6. Kruskal: calcular ´arvore geradora m´ınima
//7. Prim: dado v´ertice inicial, calcular ´arvore geradora m´ınima

void menuPrincipal(){
    wprintf(L"\tTela Principal! Digite a opção desejada:\n");
    wprintf(L" 1 - Carregar grafo de arquivo.\n");
    wprintf(L" 0 - Finalizar programa.\n");
    printf(" - ");
    int x;
    scanf("%d",&x);
    switch (x) {
        case 1:
            menuPrincipal();
            break;
        case 2:
            menuPrincipal();
            break;
        case 3:
            menuPrincipal();
            break;
        case 4:
            menuPrincipal();
            break;
        case 0:
            return;
    }

}

int main() {
    //menuPrincipal();

    FILE *arq = fopen("grafo.txt","r");
    if (arq == NULL)
        printf("Nao foi posivel abrir o arquivo");

    Grafo *gAux = carregaGrafo(arq);

    return 0;
}
