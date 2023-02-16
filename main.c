#include <stdio.h>
#include <locale.h>
#include "AlgoritmoHuffman.h"

// Compacta um arquivo .txt em outro compactado .txt, com a lista de códigos na árvore, utilizando outras funções.
void compactarArquivoLetra() {
    wchar_t *fileName = malloc(50 * sizeof(wchar_t)), *fileName2 = malloc(50 * sizeof(wchar_t));
    wprintf(L"Digite o nome do arquivo para compactação. Não colocar a extensão. O programa vai considerar um arquivo .txt\n - ");
    wscanf(L"%ls", fileName);
    wcscpy(fileName2,fileName);

    wchar_t *buffer = malloc(sizeof (wchar_t));
    alfabeto *lFreq;
    arvore *a;
    listaSimples *lCod = NULL, *lCodAux;
    char *codigoAux;

    FILE *arq = _wfopen(wcscat(fileName,L".txt"),L"r, ccs=UTF-8");

    if(arq == NULL){
        wprintf(L"Não foi possível abrir o arquivo para leitura na primeira vez.\n");
        return;
    }

    while ((*buffer=fgetwc(arq)) != WEOF){
        wcscat(buffer,L"\0");
        wprintf(L"'%ls' ",buffer); // todo.
        a = criaArvoreSimbolos(buffer, 1);
        lFreq = insereAlfabeto(lFreq, a);
        free(a);
    }

    fclose(arq);

    a = montaArvore(lFreq);
    codigoAux = malloc(sizeof(tamanhoArvore(a)));

    arq = _wfopen(fileName,L"r, ccs=UTF-8");

    if(arq == NULL){
        wprintf(L"Não foi possível abrir o arquivo para leitura na segunda vez.\n");
        return;
    }

    FILE *arq2 = _wfopen(wcscat(fileName2,L"Compactado.txt"),L"w, ccs=UTF-8");

    if(arq2 == NULL){
        wprintf(L"Não foi possível abrir o arquivo2 para escrita.\n");
        return;
    }

    lCod = determinaFrequenciaDFS(a, codigoAux, 0, lCod);
    lCodAux = lCod;

    int tamLista = tamanhoListaSimple(lCod);

    fwprintf(arq2,L"%d\n",tamLista);
    while (!ehVazioListaSimples(lCodAux)){
        fwprintf(arq2,L"%ls\n%s\n",lCodAux->simbolo,lCodAux->codigo);
        lCodAux = lCodAux->prox;
    }

    while ((*buffer=fgetwc(arq)) != WEOF){
        wcscat(buffer,L"\0");
        lCodAux = buscaListaSimples(lCod, buffer);
        fwprintf(arq2,L"%s",lCodAux->codigo);
    }

    fclose(arq);
    fclose(arq2);

    wprintf(L"Compactação terminada. O arquivo foi salvo como '%ls'\n", fileName2);

}

// Descompacta um arquivo .txt em outro descompactado .txt, com a lista de códigos na árvore, utilizando outras funções.
void descompactarArquivoLetra() {
    wchar_t *fileName = malloc(50 * sizeof(wchar_t)), *fileName2 = malloc(50 * sizeof(wchar_t));
    wprintf(L"Digite o nome do arquivo para compactação. Não colocar a extensão. O programa vai considerar um arquivo .txt\n - ");
    wscanf(L"%ls", fileName);
    wcscpy(fileName2,fileName);

    listaSimples *lCod, *lCodAux;
    wchar_t *buffer = malloc(50 * sizeof(wchar_t)), *bufferAux = malloc(50 * sizeof(wchar_t));
    char *cod = malloc(50*sizeof (char ));

    FILE *arq = _wfopen(wcscat(fileName,L".txt"),L"r, ccs=UTF-8");

    if(arq == NULL){
        wprintf(L"Não foi possível abrir o arquivo para leitura.\n");
        return;
    }

    int tamLista;
    fwscanf(arq,L"%d\n", &tamLista);

    for (int i = 0; i < tamLista; ++i) {
        if ((*buffer=fgetwc(arq)) != WEOF) {
            fgetws(bufferAux,100,arq);
            wcstombs(cod, bufferAux, 100);
            lCod = insereListaSimples(lCod,buffer,cod);
        }
    }





}

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
    system("chcp 65001");
    system("cls");

    menuPrincipal();
//    char * buffer = "Olá, mundo! Tudo bem com você? Você parece não estar bem, mundo.";
//    printf("Testando a codificação da frase: '%s', por letras.\n", buffer);
//
//    char * codigo = codificaHuffman(buffer, montaArvore(determinaAlfabeto(buffer, 1)), 1, NULL);
//
//    printf("Resultado = '%s'", codigo);

    return 0;
}
