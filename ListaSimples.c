#include "ListaSimples.h"

struct NoListaSimples* insereListaSimples(struct NoListaSimples* l, char* simbolo, char* frequencia) {
    struct NoListaSimples* aux = (struct NoListaSimples*) malloc(sizeof(struct NoListaSimples));
    strcpy(aux->simbolo,simbolo);
    strcpy(aux->codigo, frequencia);
    aux->prox = l; //encadeia com a cabeça da lista
    return aux;// retorna a nova cabeça
}

int ehVazioListaSimples(struct NoListaSimples* l){
    return (l==NULL);
}

struct NoListaSimples* buscaListaSimples (struct NoListaSimples* l, char* simbolo) {
    struct NoListaSimples * lAux = l;
    while (!ehVazioListaSimples(lAux)){
        if(strcmp(lAux->simbolo,simbolo) == 0)
            break;
        else
            lAux = lAux->prox;
    }
    return NULL;
}

