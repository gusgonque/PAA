#include "FilaPilha.h"

FilaSimples *criaFS(int valor) {
    FilaSimples *aux = malloc(sizeof(FilaSimples));
    aux->valorNo = valor;
    aux->prox = NULL;
    return aux;
}

FilaSimples *insereFS(FilaSimples *F, int valor) {
    FilaSimples *aux = F;
    if(aux == NULL) {
        aux = criaFS(valor);
        return aux;
    }
    while(aux->prox!=NULL)
        aux = aux->prox;
    aux->prox = criaFS(valor);
    return F;
}

PilhaSimples *criaPS(int valor) {
    PilhaSimples *aux = malloc(sizeof(PilhaSimples));
    aux->valorNo = valor;
    aux->prox = NULL;
    return aux;
}

PilhaSimples *inserePS(PilhaSimples *P, int valor) {
    PilhaSimples *aux = criaPS(valor);
    aux->prox = P;
    return aux;
}

PilhaSimples *removePS(PilhaSimples *P){
    PilhaSimples *aux = P->prox;
    free(P);
    return aux;
}