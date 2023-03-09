#include "ArvoreFreq.h"

ArvoreFreq *criaAF(wchar_t *simbolo, int frequencia) {
    ArvoreFreq *aAux = (ArvoreFreq *) malloc(sizeof (ArvoreFreq));
    aAux->simbolo = malloc(sizeof (wcslen(simbolo)));
    wcscpy(aAux->simbolo, simbolo);
    aAux->frequencia = frequencia;
    aAux->dir = NULL;
    aAux->esq = NULL;
    return aAux;
}

ArvoreFreq *insereSimboloAF(ArvoreFreq *a) {
    ArvoreFreq *aAux = criaAF(a->simbolo, a->frequencia);
    aAux->esq = a->esq;
    aAux->dir = a->dir;
    return aAux;
}

int ehVaziaAF(struct noArvore *a) {
    return (a == NULL);
}

int ehFolhaAF(struct noArvore *a) {
    if(ehVaziaAF(a))
        return 0;
    if(ehVaziaAF(a->esq) && ehVaziaAF(a->dir))
        return 1;
    else
        return 0;
}

int tamanhoAF(ArvoreFreq *a){
    if(!ehVaziaAF(a)) {
        int dir = tamanhoAF(a->dir), esq = tamanhoAF(a->esq);
        return 1 + (dir > esq ? dir : esq);
    }
    return 0;
}