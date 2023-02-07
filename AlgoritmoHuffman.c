#include "AlgoritmoHuffman.h"

// Cria uma lista com a frequência dos símbolos, já organizada.
// tipoCod é para determinar se vai codificar por letra ou palavra
// 1 — Letra
// 0 — palavra
struct noListaAlfabeto* determinaAlfabeto(char* buffer, int tipoCod){
    int i;
    struct noListaAlfabeto* lAux = criaNoAlfabeto(), *lAuxBusca;
    struct noArvore* aAux = criaArvoreSimbolos();
    char strAux[50];
    char * strBuffer;
    for ( i = 0 ; i < strlen(buffer) ; i++ ) {
        strBuffer = buffer+i;
        if (tipoCod) {
            sscanf((strBuffer), "%c", strAux);
            lAuxBusca = buscaListaArvore(lAux, strAux);
            if (ehVazioNoAlfabeto(lAuxBusca)) {
                insereSimboloArvore(aAux, strAux, 1);
                lAux = insereAlfabeto(lAux, aAux);
            } else {
                lAuxBusca->arvore->frequencia++;
                lAuxBusca = organizaAlfabeto(lAuxBusca);
            }
        } else {
            while (buffer[i] == ' ' || buffer[i] == '\n') {
                sscanf((buffer + i), "%c", strAux);
                insereSimboloArvore(aAux, strAux, 1);
                lAux = insereAlfabeto(lAux, aAux);
                ++i;
            }
            sscanf((buffer + i), "%s", strAux);
            insereSimboloArvore(aAux, strAux, 1);
            lAux = insereAlfabeto(lAux, aAux);
        }
    }
    return lAux;
}

// Monta a árvore binária a partir de uma lista, agrupando símbolos conforme a frequência.
// Pré-condição: parâmetro l de frequência organizada.
// Pós-condição: parâmetro l não existe mais, retorna a árvore das frequências.
// TODO;
struct noArvore* montaArvore(struct noListaAlfabeto *l) {
    struct noArvore* aAux = criaArvoreSimbolos();
    while (tamanhoListaArvore(l) > 1){
        aAux->esq = l->arvore;
        l = retiraCabecaListaAlfabeto(l);
        aAux->dir = l->arvore;
        l = retiraCabecaListaAlfabeto(l);
        aAux->frequencia = aAux->dir->frequencia + aAux->esq->frequencia;
        l = insereAlfabeto(l, aAux);
    }
    aAux = l->arvore;
    free(l);
    return aAux;
}

// Percorre a árvore utilizando o algoritmo de busca em profundidade (DFS) para obter uma tabela de frequências, no formato de uma lista.
void determinaFrequenciaDFS(struct noArvore* a, char* codigo, int tamCodigo, struct NoListaSimples* l){
    if(ehVaziaArvore(a))
        return;
    if(ehFolha(a)) {
        l = insereListaSimples(l, a->simbolo, codigo);
    } else {
        codigo = realloc(codigo, tamCodigo + 1);
        codigo[tamCodigo] = '0';
        determinaFrequenciaDFS(a->esq, codigo, ++tamCodigo, l);
        codigo[tamCodigo] = '1';
        determinaFrequenciaDFS(a->dir, codigo, ++tamCodigo, l);
    }
}

// A partir da árvore de frequência, codifica a frase buffer.
// tipoCod é para determinar se vai codificar por letra ou palavra
// 1 — Letra
// 0 — palavra
// Pré-condição: Tomar cuidado com o parâmetro lFreq.
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
        }
        codigo = lAux->codigo;
        if(*(buffer + sizeof(bAux)) == ' ') {
            codigo = strcat(codigo, codificaHuffman(" ", a, 1, lFreq)); // Considerando os espaços.
            codigo = strcat(codigo, codificaHuffman(buffer += sizeof(bAux + 1), a, tipoCod, lFreq));
        }
        return codigo;
    }
}