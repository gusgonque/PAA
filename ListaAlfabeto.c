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
    struct noListaAlfabeto * lAux = criaNoAlfabeto();
    insereSimboloArvore(lAux->arvore, a->simbolo, a->frequencia);
    lAux->prox = l; // Muda a cabeça.
    return lAux;
}

struct noListaAlfabeto * organizaAlfabeto (struct noListaAlfabeto* l){
    if(!ehVazioNoAlfabeto(l) && !ehVazioNoAlfabeto(l->prox) && l->arvore->frequencia > l->prox->arvore->frequencia){
        struct noArvore * aAux = criaArvoreSimbolos();
        insereSimboloArvore(aAux,l->arvore->simbolo,l->arvore->frequencia);
        l = retiraCabecaListaAlfabeto(l);
        l->prox = insereAlfabeto(l->prox, aAux);
        l->prox = organizaAlfabeto(l->prox);
    }
    return l;
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


