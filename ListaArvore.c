#include "ListaArvore.h"

struct noListaArvore* criaNoListaArvore(struct noArvore* a){
    struct noListaArvore* aux = (struct noListaArvore*) malloc(sizeof(struct noListaArvore));
    aux->prox = NULL;
    aux->a = insereArvoreBinaria(a, a->simbolo, a->frequencia);
    return aux;
}

int ehVazioNoListaArvore(struct noListaArvore *l){
    return (l==NULL);
}

struct noListaArvore* insereListaArvore(struct noListaArvore *l, struct noArvore* a) {
    if(ehVazioNoListaArvore(l)){ // Insere no fim da lista.
        l = criaNoListaArvore(a);
        return l;
    } if (l->a->frequencia > a->frequencia) { // Muda a cabeça.
        struct noListaArvore* aux = criaNoListaArvore(a);
        aux->prox = l; //encadeia com a cabeça da lista.
        return aux;// retorna a nova cabeça.
    } else { // Não muda a cabeça, e insere no próximo nó.
        l->prox = insereListaArvore(l->prox, a);
        return l;
    }
}

struct noListaArvore* retiraCabecaListaArvore(struct noListaArvore* l) {
    struct noListaArvore * prox = l->prox; // Próximo nó
    free(l); // libera o nó do elemento removido
    return prox; // Retorna a nova cabeça
}

int tamanhoListaArvore(struct noListaArvore* l){
    if(!ehVazioNoListaArvore(l))
        return 1 + tamanhoListaArvore(l->prox);
    return 0;
}

struct noListaArvore* buscaListaArvore(struct noListaArvore* l, char* buffer){
    if  (ehVazioNoListaArvore(l))
        return NULL;
    if  (strcmp(l->a->simbolo,buffer) == 0)
        return l;
    return buscaListaArvore(l->prox, buffer);
}


