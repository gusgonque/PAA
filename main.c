#include <stdio.h>
#include <locale.h>
#include "AlgoritmoHuffman.h"

void menuPrincipal(){
    wprintf(L"\tTela Principal! Digite a opção desejada:\n");
    wprintf(L"1 - Compactar arquivo (usando codificação por caracter)\n");
    wprintf(L"2 - Descompactar arquivo (usando codificação por caracter)\n");
    wprintf(L"3 - Compactar arquivo (usando codificação por palavra)(Não implementado)\n");
    wprintf(L"4 - Descompactar arquivo (usando codificação por palavra)(Não implementado)\n");
    wprintf(L"5 - Finalizar programa.\n");
    printf(" - ");
    int x;
    scanf("%d",&x);
    switch (x) {
        case 1:
            compactarArquivoLetra();
            menuPrincipal();
            break;
        case 2:
            descompactarArquivoLetra();
            menuPrincipal();
            break;
        case 3:
            compactarArquivoPalavra();
            menuPrincipal();
            break;
        case 4:
            menuPrincipal();
            break;
        case 5:
            return;
    }

}

int main() {
    setlocale(LC_ALL,"Portuguese");
    menuPrincipal();

    return 0;
}
