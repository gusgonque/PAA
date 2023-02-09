#include "AlgoritmoHuffman.h"

alfabeto *determinaAlfabeto(wchar_t *buffer, int tipoCod, alfabeto *l) {
    int i;
    alfabeto *lAux = criaNoAlfabeto();
    arvore *aAux;
    wchar_t *strBuffer = malloc(sizeof (buffer));
    for ( i = 0 ; i < wcslen(buffer) ;  ) {
        *strBuffer = *(buffer+i);
        if (tipoCod) {
            *(strBuffer+1) = '\0';
            aAux = criaArvoreSimbolos(strBuffer, 1);
            lAux = insereAlfabeto(lAux, aAux);
            free(aAux);
            i++;
        } else {
            while (buffer[i] == ' ' || buffer[i] == '\n') {
                swscanf((buffer + i), L"%c", strBuffer);
                *(strBuffer+1) = '\0';
                aAux = criaArvoreSimbolos(strBuffer, 1);
                lAux = insereAlfabeto(lAux, aAux);
                ++i;
                free(aAux);
            }
            swscanf((buffer + i), L"%ls", strBuffer);
            aAux = criaArvoreSimbolos(strBuffer,1);
            lAux = insereAlfabeto(lAux, aAux);
            i += wcslen(strBuffer);
        }
    }
    return lAux;
}

arvore *montaArvore(alfabeto *l) {
    arvore *aAux;
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
listaSimples *determinaFrequenciaDFS(arvore *a, char *codigo, int tamCodigo, listaSimples *l){
    if(!ehVaziaArvore(a)) {
        if (ehFolha(a)) {
            codigo[tamCodigo] = '\0';
            l = insereListaSimples(l, a->simbolo, codigo);
        } else {
            codigo[tamCodigo] = '0';
            l = determinaFrequenciaDFS(a->esq, codigo, ++tamCodigo, l);
            codigo[tamCodigo] = '1';
            l = determinaFrequenciaDFS(a->dir, codigo, ++tamCodigo, l);
        }
    }
    return l;
}

char* codificaHuffman (char* buffer, struct noArvore* a, int tipoCod, struct NoListaSimples *lFreq) {
    char* codigo = NULL, *bAux = NULL;
    struct NoListaSimples *lAux = NULL;
    if(*buffer == '\0')
        return "\0";
    if(tipoCod) {
        *bAux = *buffer;
        lAux = buscaListaSimples(lFreq, bAux);
        if (lAux == NULL) {
            determinaFrequenciaDFS(a, NULL, 0, lFreq);
            lAux = buscaListaSimples(lFreq, bAux);
        }
        codigo = strcat(lAux->codigo, codificaHuffman(++buffer, a, tipoCod, lFreq));
        return codigo;
    } else {
        sscanf(buffer, "%s", bAux);
        lAux = buscaListaSimples(lFreq, bAux);
        if (lAux == NULL) {
            determinaFrequenciaDFS(a, NULL, 0, lFreq);
            lAux = buscaListaSimples(lFreq, bAux);
            codigo = lAux->codigo;
            if(*(buffer + sizeof(bAux)) == ' ') {
                codigo = strcat(codigo, codificaHuffman(" ", a, 1, lFreq)); // Considerando os espaços.
                codigo = strcat(codigo, codificaHuffman(buffer += sizeof(bAux + 1), a, tipoCod, lFreq));
            }
            return codigo;
        }
    }
}