#include "ArvoreBinaria.h"

int ehVaziaArvore(struct noArvore* a) {
    return (a == NULL);
}

int ehFolha(struct noArvore* a) {
    if(ehVaziaArvore(a->esq) && ehVaziaArvore(a->dir))
        return 1;
    else
        return 0;
}

struct noArvore* insereArvoreBinaria(struct noArvore* a, char simbolo[], int frequencia){
    if(ehVaziaArvore(a)) {
        a = (struct noArvore*) malloc(sizeof(struct noArvore));
        strcpy(a->simbolo,simbolo);
        a->frequencia = frequencia;
        a->esq = NULL;
        a->dir = NULL;
    }
    return a;
}