#include "PAA-Trab1.h"

// Cria uma lista não organizada com a frequência dos símbolos.
// tipoCod é para determinar se vai codificar por letra ou palavra
// 1 — Letra
// 0 — palavra
ListaArvore* determinarFrequencia(char* buffer, int tipoCod){
    ListaArvore *lAux = NULL, *lAuxBusca = NULL;
    arvore noAux;
    if(tipoCod) {
        while ( buffer[0] ) {
            lAuxBusca = buscaLista(lAux, &buffer[0]);
            if(lAux != NULL)
                lAuxBusca->no.frequencia++;
            else {
                noAux->simbolo = &buffer[0];
                noAux->frequencia = 1;
                lAux = insereLista(lAux, noAux);
            }
            ++buffer;
        }
    } else {
        char *bAux = NULL;
        while (buffer){
            sscanf(buffer, "%s", bAux);
            buffer += sizeof(bAux);
            lAuxBusca = buscaLista(lAux, bAux);
            if(lAux != NULL)
                lAuxBusca->no.frequencia++;
            else {
                noAux->simbolo = bAux;
                noAux->frequencia = 1;
                lAux = insereLista(lAux, noAux );
            }
            if (*buffer == EOF)
                break;
            else {
                noAux->simbolo = &buffer[0];
                noAux->frequencia = 1;
                lAux = insereLista(lAux, noAux);
            }
        }
    }
    // lAux é uma lista não organizada.
    return lAux;
}

// Organiza a lista conforme a frequência de cada símbolo.
ListaArvore* organizaFrequencia (ListaArvore *l){
    ListaArvore *lAux = NULL;
    while (!ehVazioLista(l)){
        lAux = insereLista(lAux,&(l->no));
        l = retiraCabecaLista(l);
    }
    return lAux;
}


// Monta a árvore binária a partir de uma lista, agrupando símbolos conforme a frequência.
// Pré-condição: lista de frequência organizada.
// Pós-condição: lista não existe mais, retorna a árvore das frequências.
arvore montaArvore(ListaArvore *l) {
    arvore aAux = (arvore)malloc(sizeof(arvore));
    while (tamanhoLista(l) > 1){
        aAux->esq = (arvore)realloc(aAux->esq,sizeof(l->no));
        aAux->esq = &(l->no);
        l = retiraCabecaLista(l);
        aAux->dir = (arvore)realloc(aAux->dir,sizeof(l->no));
        aAux->dir = &(l->no);
        l = retiraCabecaLista(l);
        aAux->frequencia = aAux->dir->frequencia + aAux->esq->frequencia;
        l = insereLista(l,aAux);
    }
    free(l);
    return aAux;
}