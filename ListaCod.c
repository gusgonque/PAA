#include "ListaCod.h"

ListaCod *insereLC(ListaCod *l, wchar_t *simbolo, char *codigo) {
    ListaCod *aux = (ListaCod*) malloc(sizeof(ListaCod));

    aux->simbolo = malloc(wcslen(simbolo) * sizeof(wchar_t));
    wcscpy(aux->simbolo,simbolo);

    aux->codigo = malloc(strlen(codigo) * sizeof(char));
    strcpy(aux->codigo, codigo);

    aux->prox = l; //encadeia com a cabeça da lista

    return aux;// retorna a nova cabeça
}

int ehVazioLC(ListaCod *l){
    return (l==NULL);
}

ListaCod *buscaLC (ListaCod *l, wchar_t *simbolo) {
    ListaCod *lAux = l;
    while (!ehVazioLC(lAux)){
        if(wcscmp(lAux->simbolo,simbolo) == 0)
            return lAux;
        else
            lAux = lAux->prox;
    }
    return NULL;
}

int tamanhoLC(ListaCod *l){
    if(!ehVazioLC(l))
        return 1 + tamanhoLC(l->prox);
    else
        return 0;
}