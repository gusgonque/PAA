#include "ListaAlfabeto.h"

struct noListaAlfabeto* criaNoAlfabeto(){
    struct noListaAlfabeto* aux = (struct noListaAlfabeto*) malloc(sizeof(struct noListaAlfabeto));
    aux->arvore = criaArvoreSimbolos();
    aux->prox = NULL;
    return aux;
}

int ehVazioNoAlfabeto(struct noListaAlfabeto *l){
    return (l == NULL || ehVaziaArvore(l->arvore));
}

struct noListaAlfabeto *insereAlfabeto(struct noListaAlfabeto *l, struct noArvore *a) {
    struct noListaAlfabeto * lAux = buscaListaArvore(l, a->simbolo);
    if (ehVazioNoAlfabeto(lAux)){
        lAux = criaNoAlfabeto();
        insereSimboloArvore(lAux->arvore,a->simbolo,a->frequencia);
        if(!ehVazioNoAlfabeto(l->prox) && lAux->arvore->frequencia > l->arvore->frequencia) {
            l->prox = insereAlfabeto(l->prox, lAux->arvore);
            return l;
        }
        lAux->prox = l;
    } else {
        lAux->arvore->frequencia ++;
    }

    if (!ehVazioNoAlfabeto(lAux->prox) && lAux->arvore->frequencia > lAux->prox->arvore->frequencia) { // Muda a cabeça, colocando a frequência maior no final.
        struct noListaAlfabeto * lAux2 = criaNoAlfabeto();
        insereSimboloArvore(lAux2->arvore,lAux->arvore->simbolo,lAux->arvore->frequencia);
        lAux = retiraCabecaListaAlfabeto(lAux);
        lAux = insereAlfabeto(lAux, lAux2->arvore);
    }
    return lAux;
}

struct noListaAlfabeto* retiraCabecaListaAlfabeto(struct noListaAlfabeto* l) {
    struct noListaAlfabeto * prox = l->prox; // Próximo nó
    free(l); //libera o nó do elemento removido
    return prox; // Retorna a nova cabeça
}

int tamanhoListaArvore(struct noListaAlfabeto* l){
    if(!ehVazioNoAlfabeto(l))
        return 1 + tamanhoListaArvore(l->prox);
    return 0;
}

struct noListaAlfabeto* buscaListaArvore(struct noListaAlfabeto* l, char* buffer){
    if (ehVazioNoAlfabeto(l) || ehVaziaArvore(l->arvore))
        return NULL;
    if (strcmp(l->arvore->simbolo,buffer) == 0)
        return l;
    return buscaListaArvore(l->prox, buffer);
}


