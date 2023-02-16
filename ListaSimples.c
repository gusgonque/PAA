#include "ListaSimples.h"

ListaSimples *insereListaSimples(ListaSimples *l, wchar_t *simbolo, char *codigo) {
    ListaSimples *aux = (ListaSimples*) malloc(sizeof(ListaSimples));
    aux->simbolo = malloc(wcslen(simbolo)*sizeof(wchar_t));
    wcscpy(aux->simbolo,simbolo);
    aux->codigo = malloc(strlen(codigo)*sizeof(char));
    strcpy(aux->codigo, codigo);
    aux->prox = l; //encadeia com a cabeça da lista
    return aux;// retorna a nova cabeça
}

int ehVazioListaSimples(ListaSimples *l){
    return (l==NULL);
}

ListaSimples *buscaListaSimples (ListaSimples *l, wchar_t *simbolo) {
    ListaSimples *lAux = l;
    while (!ehVazioListaSimples(lAux)){
        if(wcscmp(lAux->simbolo,simbolo) == 0)
            return lAux;
        else
            lAux = lAux->prox;
    }
    return NULL;
}

int tamanhoListaSimple(ListaSimples *l){
    if(!ehVazioListaSimples(l))
        return 1 + tamanhoListaSimple(l->prox);
    else
        return 0;
}