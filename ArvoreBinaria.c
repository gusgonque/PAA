#include "ArvoreBinaria.h"

arvore *criaArvoreSimbolos(wchar_t *simbolo, int frequencia) {
    arvore *aAux = (arvore *) malloc(sizeof (arvore));
    aAux->simbolo = malloc(sizeof (wcslen(simbolo)));
    wcscpy(aAux->simbolo, simbolo);
    aAux->frequencia = frequencia;
    aAux->dir = NULL;
    aAux->esq = NULL;
    return aAux;
}

arvore *insereSimboloArvore(arvore *a) {
    arvore *aAux = criaArvoreSimbolos(a->simbolo, a->frequencia);
    aAux->esq = a->esq;
    aAux->dir = a->dir;
    return aAux;
}

int ehVaziaArvore(arvore *a) {
    return (a == NULL);
}

int ehFolha(arvore *a) {
    if(ehVaziaArvore(a))
        return 0;
    if(ehVaziaArvore(a->esq) && ehVaziaArvore(a->dir))
        return 1;
    else
        return 0;
}

int tamanhoArvore(arvore *a){
    if(!ehVaziaArvore(a)) {
        int dir = tamanhoArvore(a->dir), esq = tamanhoArvore(a->esq);
        return 1 + (dir > esq ? dir : esq);
    }
    return 0;
}