#include "Trab2.h"

FILE *abreArquivo (char *fileName, char *mode) {
    FILE *arq = fopen(fileName,mode);
    if(arq == NULL)
        wprintf(L"Não foi possível abrir o arquivo '%s' no modo '%s'.\n", fileName, mode);
    return arq;
}

Grafo *carregaArquivoGrafo(){
    Grafo *g = criaGrafo();
    char *fileNmae = malloc(50*sizeof (char));
    wprintf(L"Insira o nome do arquivo em que o grafo se encontra.\n - ");
    scanf("%s", fileNmae);

    FILE *arq = abreArquivo(fileNmae,"r");
    if(arq != NULL) {
        wprintf(L"Grafo carregado com sucesso!\n\n");
        g = carregaGrafo(arq);
    }
    free(fileNmae);
    return g;
}