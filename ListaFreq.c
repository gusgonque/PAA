#include "ListaFreq.h"

ListaFreq *criaNoLF(){
    ListaFreq *aux = (ListaFreq *) malloc(sizeof(ListaFreq));
    aux->arvore = NULL;
    aux->prox = NULL;
    return aux;
}

int ehVazioNoLF(ListaFreq *l){
    return (l == NULL || ehVaziaAF(l->arvore));
}

ListaFreq *insereLF(ListaFreq *l, ArvoreFreq *a) {
    ListaFreq *lAuxBusca = buscaLF(l, a->simbolo), *lAux;
    if(!ehVazioNoLF(lAuxBusca)){
        lAuxBusca->arvore->frequencia ++;
        l = organizaLF(l, lAuxBusca);
        return l;
    } else {
        if(!ehVazioNoLF(l) && a->frequencia > l->arvore->frequencia) {
            lAux = l;
            lAux->prox = insereLF(lAux->prox, a);
            return l;
        } else {
            lAux = criaNoLF();
            lAux->arvore = insereSimboloAF(a);
            lAux->prox = l; // Muda a cabeça.
            return lAux;
        }
    }
}

ListaFreq *organizaLF (ListaFreq *lCabeca, ListaFreq *l){
    ListaFreq *lAux;
    ArvoreFreq *aAux = insereSimboloAF(l->arvore);
    if(!ehVazioNoLF(l->prox) && l->arvore->frequencia > l->prox->arvore->frequencia) {
        lAux = lCabeca;
        if (wcscmp(lAux->arvore->simbolo, l->arvore->simbolo) == 0) {// caso o nó ruim esteja na cabeça`
            lCabeca = insereLF(l->prox, aAux);
            free(l->arvore);
            free(l); //libera o nó do elemento removido
        } else {
            while (wcscmp(lAux->prox->arvore->simbolo, l->arvore->simbolo) != 0)
                lAux = lAux->prox;

            // Agora temos 3 nós do ListaFreq, lCabeca é a cabeça, l é onde está o nó para reorganizar o ListaFreq, e lAux é o anterior de l.
            l = retiraCabecaLF(l);
            l->prox = insereLF(l->prox, aAux);
            lAux->prox = l;
        }
    }
    return lCabeca;
}

ListaFreq *retiraCabecaLF(ListaFreq *l) {
    ListaFreq *prox = l->prox; // Próximo nó
    free(l->arvore);
    free(l); //libera o nó do elemento removido
    return prox; // Retorna a nova cabeça
}

int tamanhoLF(ListaFreq *l){
    if(!ehVazioNoLF(l))
        return 1 + tamanhoLF(l->prox);
    return 0;
}

ListaFreq *buscaLF(ListaFreq *l, wchar_t *buffer){
    if (ehVazioNoLF(l) || ehVaziaAF(l->arvore))
        return NULL;
    if (wcscmp(l->arvore->simbolo,buffer) == 0)
        return l;
    return buscaLF(l->prox, buffer);
}

