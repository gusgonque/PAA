#include "ListaArvore.h"

ListaArvore* criaNoLista(arvore no){
    ListaArvore *aux = (ListaArvore *) malloc(sizeof(ListaArvore) + sizeof(no->simbolo));
    aux->prox = NULL;
    strcpy(aux->no.simbolo, no->simbolo);
    aux->no.frequencia = no->frequencia;
    aux->no.esq = NULL;
    aux->no.dir = NULL;
    return aux;
}

int ehVazioLista(ListaArvore* l){
    return (l==NULL);
}

ListaArvore *insereLista(ListaArvore *l, arvore no) {
    if(ehVazioLista(l)){ // Insere noLista fim da lista
        l = criaNoLista(no);
        return l;
    } if(ehVazioLista(l->prox)){ // Insere noLista fim da lista
        l->prox = criaNoLista(no);
        return l;
    } if (l->no.frequencia > no->frequencia) { // Muda a cabeça
        ListaArvore *aux = criaNoLista(no);
        aux->prox = l; //encadeia com a cabeça da lista
        return aux;// retorna a nova cabeça
    }else{ // Não muda a cabeça, e insere noArvore próximo
        l->prox = insereLista(l->prox, no);
        return l;
    }
}

ListaArvore* retiraCabecaLista(ListaArvore* l) {
    ListaArvore * prox = l->prox; // Próximo nó
    free(l); // libera o nó do elemento removido
    return prox; // Retorna a nova cabeça
}

int tamanhoLista(ListaArvore* l){
    if(!ehVazioLista(l))
        return 1 + tamanhoLista(l->prox);
    return 0;
}

ListaArvore* buscaLista(ListaArvore* l, char* buffer){
    if(strcmp(l->no.simbolo,buffer) != 0)
        if(ehVazioLista(l->prox))
            return NULL;
        else
            return buscaLista(l->prox,buffer);
    else
        return l;
}


