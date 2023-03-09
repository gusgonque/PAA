#include "AlgoritmoHuffman.h"

ArvoreFreq *montaAF(ListaFreq *l) {
    ArvoreFreq *aAux = NULL;
    while (tamanhoLF(l) > 1){
        aAux = insereSimboloAF(l->arvore);
        aAux->esq = insereSimboloAF(l->arvore);
        l = retiraCabecaLF(l);
        aAux->dir = insereSimboloAF(l->arvore);
        l = retiraCabecaLF(l);
        aAux->frequencia = aAux->dir->frequencia + aAux->esq->frequencia;
        l = insereLF(l, aAux);
    }
    aAux = l->arvore;
    free(l);
    return aAux;
}

// Percorre a árvore utilizando o algoritmo de busca em profundidade (DFS) para obter uma tabela de frequências, no formato de uma lista.
ListaCod *determinaFrequenciaDFS(ArvoreFreq *a, char *codigo, int tamCodigo, ListaCod *l){
    if(!ehVaziaAF(a)) {
        if (ehFolhaAF(a)) {
            codigo[tamCodigo] = '\0';
            l = insereLC(l, a->simbolo, codigo);
        } else {
            codigo[tamCodigo] = '0';
            l = determinaFrequenciaDFS(a->esq, codigo, tamCodigo+1, l);
            codigo[tamCodigo] = '1';
            l = determinaFrequenciaDFS(a->dir, codigo, tamCodigo+1, l);
        }
    }
    return l;
}

// todo: fazer para palavra
ListaFreq *pegaListaFreqArqLetra(FILE *arq) {
    wchar_t *buffer = malloc(sizeof (wchar_t));
    ArvoreFreq *a = NULL;
    ListaFreq *lFreq = NULL;
    while ((*buffer=fgetwc(arq)) != WEOF){
        wcscat(buffer,L"\0");
        a = criaAF(buffer, 1);
        lFreq = insereLF(lFreq, a);
        free(a);
    }
    return lFreq;
}

void compactarArquivoLetra() {

    // Parte 1: ler o arquivo para montar a àrvore de frequências.
    wchar_t *fileName = malloc(50 * sizeof(wchar_t));
    wprintf(L"Digite o nome do arquivo para compactação. Não colocar a extensão. O programa vai considerar um arquivo .txt\n - ");
    wscanf(L"%ls", fileName);

    FILE *arq = _wfopen(wcscat(fileName,L".txt"),L"r, ccs=UTF-8");

    if(arq == NULL){
        wprintf(L"Não foi possível abrir o arq1 para leitura.\n");
        return;
    }

    // Monta a lista de frequência organizada.
    ListaFreq *lFreq = pegaListaFreqArqLetra(arq);

    ArvoreFreq *a = NULL;
    // Monta a árvore de frequências, conforme a lista.
    a = montaAF(lFreq);

    // Parte 2: ler o arquivo arq1 para escrever no arq2 as frequências.
    rewind(arq);

    wchar_t *fileName2 = malloc(50 * sizeof(wchar_t));
    wcscpy(fileName2,fileName);

    FILE *arq2 = _wfopen(wcscat(fileName2,L"C.txt"),L"w, ccs=UTF-8");

    if(arq2 == NULL){
        wprintf(L"Não foi possível abrir o arq2 para escrita.\n");
        return;
    }

    char *codigoAux;
    codigoAux = malloc(tamanhoAF(a) * sizeof(char));
    ListaCod *lCod = NULL, *lCodAux;

    lCod = determinaFrequenciaDFS(a, codigoAux, 0, lCod);
    lCodAux = lCod;

    int tamLista = tamanhoLC(lCod);

    fwprintf(arq2,L"%d\n",tamLista);
    while (!ehVazioLC(lCodAux)){
        fwprintf(arq2,L"%ls\n%s\n",lCodAux->simbolo,lCodAux->codigo);
        lCodAux = lCodAux->prox;
    }

    wchar_t *buffer = malloc(sizeof (wchar_t));
    while ((*buffer=fgetwc(arq)) != WEOF){
        wcscat(buffer,L"\0");
        lCodAux = buscaLC(lCod, buffer);
        fwprintf(arq2,L"%s",lCodAux->codigo);
    }

    fclose(arq);
    fclose(arq2);

    wprintf(L"Compactação terminada. O arquivo foi salvo como '%ls'\n", fileName2);

}

void compactarArquivoPalavra() {
    wchar_t *fileName = malloc(50 * sizeof(wchar_t)), *fileName2 = malloc(50 * sizeof(wchar_t));
    wprintf(L"Digite o nome do arquivo para compactação. Não colocar a extensão. O programa vai considerar um arquivo .txt\n - ");
    wscanf(L"%ls", fileName);
    wcscpy(fileName2,fileName);

    wchar_t *buffer = malloc(sizeof (wchar_t));
    ListaFreq *lFreq = NULL;
    ArvoreFreq *a = NULL;
    ListaCod *lCod = NULL, *lCodAux;
    char *codigoAux;

    FILE *arq = _wfopen(wcscat(fileName,L".txt"),L"r, ccs=UTF-8");

    if(arq == NULL){
        wprintf(L"Não foi possível abrir o arquivo para leitura na primeira vez.\n");
        return;
    }

    while (feof(arq) == 0){
        fwscanf(arq,L"%ls",buffer);
        a = criaAF(buffer, 1);
        lFreq = insereLF(lFreq, a);
        free(a);
        if((feof(arq) == 0)) {
            fgetws(buffer, 2, arq);
            a = criaAF(buffer, 1);
            lFreq = insereLF(lFreq, a);
            free(a);
        }
    }

    fclose(arq);

    a = montaAF(lFreq);
    codigoAux = malloc(tamanhoAF(a) * sizeof(char));

    arq = _wfopen(fileName,L"r, ccs=UTF-8");

    if(arq == NULL){
        wprintf(L"Não foi possível abrir o arquivo para leitura na segunda vez.\n");
        return;
    }

    FILE *arq2 = _wfopen(wcscat(fileName2,L"C.txt"),L"w, ccs=UTF-8");

    if(arq2 == NULL){
        wprintf(L"Não foi possível abrir o arquivo2 para escrita.\n");
        return;
    }

    lCod = determinaFrequenciaDFS(a, codigoAux, 0, lCod);
    lCodAux = lCod;

    int tamLista = tamanhoLC(lCod);

    fwprintf(arq2,L"%d\n",tamLista);
    while (!ehVazioLC(lCodAux)){
        fwprintf(arq2,L"%ls\n%s\n",lCodAux->simbolo,lCodAux->codigo);
        lCodAux = lCodAux->prox;
    }

    while (feof(arq) == 0){
        fwscanf(arq,L"%ls",buffer);
        lCodAux = buscaLC(lCod, buffer);
        fwprintf(arq2,L"%s",lCodAux->codigo);
        if((feof(arq) == 0)) {
            fgetws(buffer, 2, arq);
            lCodAux = buscaLC(lCod, buffer);
            fwprintf(arq2,L"%s",lCodAux->codigo);
        }
    }

    fclose(arq);
    fclose(arq2);

    wprintf(L"Compactação terminada. O arquivo foi salvo como '%ls'\n", fileName2);

}

ArvoreFreq *montaArvoreListaSimplesAux(ArvoreFreq *a, char *codigo, wchar_t *simbolo){
    if (*codigo != '\0'){
        if(*codigo == '0'){
            if(!ehVaziaAF(a->esq)){
                a->esq = montaArvoreListaSimplesAux(a->esq, (codigo+1), simbolo);
            } else {
                a->esq = criaAF(L"\n", 0);
                a->esq = montaArvoreListaSimplesAux(a->esq, (codigo+1), simbolo);
            }
        } else {
            if(!ehVaziaAF(a->dir)){
                a->dir = montaArvoreListaSimplesAux(a->dir, (codigo+1), simbolo);
            } else {
                a->dir = criaAF(L"\n", 0);
                a->dir = montaArvoreListaSimplesAux(a->dir, (codigo+1), simbolo);
            }
        }
    } else
        wcscpy(a->simbolo,simbolo);
    return a;
}

ArvoreFreq *montaArvoreListaSimples(ListaCod *l){
    ArvoreFreq *aAux = criaAF(L"\n", 0);
    ListaCod *lAux = l;
    while (!ehVazioLC(lAux)){
        aAux = montaArvoreListaSimplesAux(aAux, l->codigo, l->simbolo);
        lAux = lAux->prox;
    }
    return aAux;
}

void descompactarArquivoLetra() {
    wchar_t *fileName = malloc(50 * sizeof(wchar_t)), *fileName2 = malloc(50 * sizeof(wchar_t));
    wprintf(L"Digite o nome do arquivo para descompactação. Não colocar a extensão. O programa vai considerar um arquivo .txt\n - ");
    wscanf(L"%ls", fileName);
    wcscpy(fileName2,fileName);

    ListaCod *lCod = NULL;
    wchar_t *buffer = malloc(50 * sizeof(wchar_t));
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
            wcscat(buffer,L"\0");
            fwscanf(arq,L"%*c%[^\n]", cod);
            lCod = insereLC(lCod, buffer, cod);
        }
    }

    ArvoreFreq *a = montaArvoreListaSimples(lCod);
    ArvoreFreq *aAux = a;

    FILE *arq2 = _wfopen(wcscat(fileName2,L"D.txt"),L"w, ccs=UTF-8");

    if(arq2 == NULL){
        wprintf(L"Não foi possível abrir o arquivo2 para escrita.\n");
        return;
    }

    while ((*buffer=fgetwc(arq)) != WEOF) {
        wcscat(buffer,L"\0");
        if(ehFolhaAF(aAux)) {
            fwprintf(arq2, L"%ls", aAux->simbolo);
            aAux = a;
        }
        else {
            if(*buffer == L'0')
                aAux = aAux->esq;
            else
                aAux = aAux->dir;
        }
    }

    fclose(arq);
    fclose(arq2);

    wprintf(L"Descompactação terminada. O arquivo foi salvo como '%ls'\n", fileName2);

}

