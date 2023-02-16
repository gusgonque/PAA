#include "AlgoritmoHuffman.h"

Arvore *montaArvoreAlfabeto(Alfabeto *l) {
    Arvore *aAux = NULL;
    while (tamanhoListaAlfabeto(l) > 1){
        aAux = insereSimboloArvore(l->arvore);
        aAux->esq = insereSimboloArvore(l->arvore);
        l = retiraCabecaListaAlfabeto(l);
        aAux->dir = insereSimboloArvore(l->arvore);
        l = retiraCabecaListaAlfabeto(l);
        aAux->frequencia = aAux->dir->frequencia + aAux->esq->frequencia;
        l = insereAlfabeto(l, aAux);
    }
    aAux = l->arvore;
    free(l);
    return aAux;
}

// Percorre a árvore utilizando o algoritmo de busca em profundidade (DFS) para obter uma tabela de frequências, no formato de uma lista.
ListaSimples *determinaFrequenciaDFS(Arvore *a, char *codigo, int tamCodigo, ListaSimples *l){
    if(!ehVaziaArvore(a)) {
        if (ehFolha(a)) {
            codigo[tamCodigo] = '\0';
            l = insereListaSimples(l, a->simbolo, codigo);
        } else {
            codigo[tamCodigo] = '0';
            l = determinaFrequenciaDFS(a->esq, codigo, tamCodigo+1, l);
            codigo[tamCodigo] = '1';
            l = determinaFrequenciaDFS(a->dir, codigo, tamCodigo+1, l);
        }
    }
    return l;
}

void compactarArquivoLetra() {
    wchar_t *fileName = malloc(50 * sizeof(wchar_t)), *fileName2 = malloc(50 * sizeof(wchar_t));
    wprintf(L"Digite o nome do arquivo para compactação. Não colocar a extensão. O programa vai considerar um arquivo .txt\n - ");
    wscanf(L"%ls", fileName);
    wcscpy(fileName2,fileName);

    wchar_t *buffer = malloc(sizeof (wchar_t));
    Alfabeto *lFreq;
    Arvore *a;
    ListaSimples *lCod = NULL, *lCodAux;
    char *codigoAux;

    FILE *arq = _wfopen(wcscat(fileName,L".txt"),L"r, ccs=UTF-8");

    if(arq == NULL){
        wprintf(L"Não foi possível abrir o arquivo para leitura na primeira vez.\n");
        return;
    }

    while ((*buffer=fgetwc(arq)) != WEOF){
        wcscat(buffer,L"\0");
        a = criaArvoreSimbolos(buffer, 1);
        lFreq = insereAlfabeto(lFreq, a);
        free(a);
    }

    fclose(arq);

    a = montaArvoreAlfabeto(lFreq);
    codigoAux = malloc(sizeof(tamanhoArvore(a)));

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

Arvore *montaArvoreListaSimplesAux(Arvore *a, char *codigo, wchar_t *simbolo){
    if (*codigo != '\0'){
        if(*codigo == '0'){
            if(!ehVaziaArvore(a->esq)){
                a->esq = montaArvoreListaSimplesAux(a->esq, (codigo+1), simbolo);
            } else {
                a->esq = criaArvoreSimbolos(L"\n",0);
                a->esq = montaArvoreListaSimplesAux(a->esq, (codigo+1), simbolo);
            }
        } else {
            if(!ehVaziaArvore(a->dir)){
                a->dir = montaArvoreListaSimplesAux(a->dir, (codigo+1), simbolo);
            } else {
                a->dir = criaArvoreSimbolos(L"\n",0);
                a->dir = montaArvoreListaSimplesAux(a->dir, (codigo+1), simbolo);
            }
        }
    } else
        wcscpy(a->simbolo,simbolo);
    return a;
}

Arvore *montaArvoreListaSimples(ListaSimples *l){
    Arvore *aAux = criaArvoreSimbolos(L"\n",0);
    ListaSimples *lAux = l;
    while (!ehVazioListaSimples(lAux)){
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

    ListaSimples *lCod;
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
            lCod = insereListaSimples(lCod,buffer,cod);
        }
    }

    Arvore *a = montaArvoreListaSimples(lCod);
    Arvore *aAux = a;

    FILE *arq2 = _wfopen(wcscat(fileName2,L"D.txt"),L"w, ccs=UTF-8");

    if(arq2 == NULL){
        wprintf(L"Não foi possível abrir o arquivo2 para escrita.\n");
        return;
    }

    while ((*buffer=fgetwc(arq)) != WEOF) {
        wcscat(buffer,L"\0");
        if(ehFolha(aAux)) {
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

