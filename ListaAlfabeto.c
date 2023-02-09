#include "ListaAlfabeto.h"

alfabeto *criaNoAlfabeto(){
    alfabeto *aux = (alfabeto *) malloc(sizeof(alfabeto));
    aux->arvore = NULL;
    aux->prox = NULL;
    return aux;
}

int ehVazioNoAlfabeto(alfabeto *l){
    return (l == NULL || ehVaziaArvore(l->arvore));
}

alfabeto *insereAlfabeto(alfabeto *l, arvore *a) {
    alfabeto *lAuxBusca = buscaListaArvore(l, a->simbolo), *lAux;
    if(!ehVazioNoAlfabeto(lAuxBusca)){
        lAuxBusca->arvore->frequencia ++;
        l = organizaAlfabeto(l, lAuxBusca);
        return l;
    } else {
        if(!ehVazioNoAlfabeto(l) && a->frequencia > l->arvore->frequencia) {
            lAux = l;
            lAux->prox = insereAlfabeto(lAux->prox, a);
            return l;
        } else {
            lAux = criaNoAlfabeto();
            lAux->arvore = insereSimboloArvore(a);
            lAux->prox = l; // Muda a cabeça.
            return lAux;
        }
    }
}

alfabeto *organizaAlfabeto (alfabeto *lCabeca, alfabeto *l){
    alfabeto *lAux;
    arvore *aAux = insereSimboloArvore(l->arvore);
    if(!ehVazioNoAlfabeto(l->prox) && l->arvore->frequencia > l->prox->arvore->frequencia) {
        lAux = lCabeca;
        if (wcscmp(lAux->arvore->simbolo, l->arvore->simbolo) == 0) {// caso o nó ruim esteja na cabeça`
            lCabeca = insereAlfabeto(l->prox,aAux);
            free(l->arvore);
            free(l); //libera o nó do elemento removido
        } else {
            while (wcscmp(lAux->prox->arvore->simbolo, l->arvore->simbolo) != 0)
                lAux = lAux->prox;

            // Agora temos 3 nós do Alfabeto, lCabeca é a cabeça, l é onde está o nó para reorganizar o alfabeto, e lAux é o anterior de l.
            l = retiraCabecaListaAlfabeto(l);
            l->prox = insereAlfabeto(l->prox, aAux);
            lAux->prox = l;
        }
    }
    return lCabeca;
}

alfabeto *retiraCabecaListaAlfabeto(alfabeto *l) {
    alfabeto *prox = l->prox; // Próximo nó
    free(l->arvore);
    free(l); //libera o nó do elemento removido
    return prox; // Retorna a nova cabeça
}

int tamanhoListaAlfabeto(alfabeto *l){
    if(!ehVazioNoAlfabeto(l))
        return 1 + tamanhoListaAlfabeto(l->prox);
    return 0;
}

alfabeto *buscaListaArvore(alfabeto *l, wchar_t *buffer){
    if (ehVazioNoAlfabeto(l) || ehVaziaArvore(l->arvore))
        return NULL;
    if (wcscmp(l->arvore->simbolo,buffer) == 0)
        return l;
    return buscaListaArvore(l->prox, buffer);
}

