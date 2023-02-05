#include "ArvoreBinaria.h"

struct noArvore * criaArvoreSimbolos() {
    struct noArvore * aux = (struct noArvore *) malloc(sizeof (struct noArvore));
    aux->simbolo = NULL;
    aux->frequencia = 1;
    aux->dir = NULL;
    aux->esq = NULL;
    return aux;
}

void insereSimboloArvore(struct noArvore * arvore, char * simbolo, int frequencia){
    if(arvore->simbolo == NULL)
        arvore->simbolo = malloc(sizeof (strlen(simbolo)));
    strcpy(arvore->simbolo,simbolo);
    arvore->frequencia = frequencia;
}

int ehVaziaArvore(struct noArvore* a) {
    return (a == NULL || (a->simbolo == NULL && ehVaziaArvore(a->esq) && ehVaziaArvore(a->dir)));
}

int ehFolha(struct noArvore* a) {
    if(ehVaziaArvore(a))
        return 0;
    if(ehVaziaArvore(a->esq) && ehVaziaArvore(a->dir))
        return 1;
    else
        return 0;
}