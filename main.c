#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include "Grafos.h"

void menuPrincipal(){
    wprintf(L"\tTela Principal! Digite a opção desejada:\n");
    wprintf(L"0 - Finalizar programa.\n");
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

    FILE *arq = fopen("test.txt","r");
    if (arq == NULL)
        printf("Nao foi posivel abrir o arquivo");

    Grafo *gAux = carregaGrafo(arq);

    return 0;
}
