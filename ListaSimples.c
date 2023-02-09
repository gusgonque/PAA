#include "ListaSimples.h"

listaSimples *insereListaSimples(listaSimples *l, wchar_t *simbolo, char *codigo) {
    listaSimples *aux = (listaSimples*) malloc(sizeof(listaSimples));
    aux->simbolo = malloc(sizeof(wcslen(simbolo)));
    wcscpy(aux->simbolo,simbolo);
    aux->codigo = malloc(sizeof(strlen(codigo)));
    strcpy(aux->codigo, codigo);
    aux->prox = l; //encadeia com a cabeça da lista
    return aux;// retorna a nova cabeça
}

int ehVazioListaSimples(listaSimples *l){
    return (l==NULL);
}

listaSimples *buscaListaSimples (listaSimples *l, wchar_t *simbolo) {
    listaSimples *lAux = l;
    while (!ehVazioListaSimples(lAux)){
        if(wcscmp(lAux->simbolo,simbolo) == 0)
            return lAux;
        else
            lAux = lAux->prox;
    }
    return NULL;
}

int tamanhoListaSimple(listaSimples *l){
    if(!ehVazioListaSimples(l))
        return 1 + tamanhoListaSimple(l->prox);
    else
        return 0;
}