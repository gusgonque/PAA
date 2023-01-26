#include "PAA-Trab1.h"

// Cria uma lista não organizada com a frequência dos símbolos.
// tipoCod é para determinar se vai codificar por letra ou palavra
// 1 — Letra
// 0 — palavra
struct noListaArvore* determinarFrequencia(char* buffer, int tipoCod){
    struct noListaArvore *lAux = NULL, *lAuxBusca = NULL;
    char bAux[2] = " \0";
    struct noArvore* noAux = NULL;
    if(tipoCod) {
        while ( *buffer != '\0' ) {
            bAux[0] = *buffer;
            lAuxBusca = buscaListaArvore(lAux, bAux);
            if(lAuxBusca != NULL)
                lAuxBusca->a->frequencia++;
            else {
                noAux = NULL;
                noAux = insereArvoreBinaria(noAux, bAux, 1);
                lAux = insereListaArvore(lAux, noAux);
            }
            ++buffer;
        }
    } else {
        char *bAux2 = NULL;
        while (*buffer != '\0'){
            sscanf(buffer, "%s", bAux2);
            lAuxBusca = buscaListaArvore(lAux, bAux2);
            if(lAux != NULL)
                lAuxBusca->a->frequencia++;
            else {
                strcpy(noAux->simbolo,bAux2);
                noAux->frequencia = 1;
                lAux = insereListaArvore(lAux, noAux);
            }
            buffer += sizeof(bAux2);
            if (*buffer == '\0')
                break;
            else {
                lAux = determinarFrequencia(" ",1);
            }
        }
    }
    // lAux é uma lista não organizada.
    return lAux;
}

// Organiza a lista conforme a frequência de cada símbolo.
struct noListaArvore* organizaFrequencia (struct noListaArvore *l){
    struct noListaArvore *lAux = NULL;
    while (!ehVazioNoListaArvore(l)){
        lAux = insereListaArvore(lAux, l->a);
        l = retiraCabecaListaArvore(l);
    }
    return lAux;
}


// Monta a árvore binária a partir de uma lista, agrupando símbolos conforme a frequência.
// Pré-condição: parâmetro l de frequência organizada.
// Pós-condição: parâmetro l não existe mais, retorna a árvore das frequências.
// TODO;
struct noArvore* montaArvore(struct noListaArvore *l) {
    struct noArvore* aAux;
    while (tamanhoListaArvore(l) > 1){
        aAux = (struct noArvore*)malloc(sizeof(struct noArvore));
        aAux->esq = l->a;
        l = retiraCabecaListaArvore(l);
        aAux->dir = l->a;
        l = retiraCabecaListaArvore(l);
        aAux->frequencia = aAux->dir->frequencia + aAux->esq->frequencia;
        strcpy(aAux->simbolo,"\0");
        l = insereListaArvore(l, aAux);
        free(aAux);
    }
    aAux = l->a;
    free(l);
    return aAux;
}

// Percorre a árvore utilizando o algoritmo de busca em profundidade (DFS) para obter uma tabela de frequências, no formato de uma lista.
void determinaFrequenciaDFS(struct noArvore* a, char* caminho, int tamCaminho, struct NoListaSimples* l){
    if(ehVaziaArvore(a))
        return;
    if(ehFolha(a)) {
        l = insereListaSimples(l,a->simbolo,caminho);
    } else {
        caminho = realloc(caminho, tamCaminho + 1);
        caminho[tamCaminho] = '0';
        determinaFrequenciaDFS(a->esq, caminho, ++tamCaminho, l);
        caminho[tamCaminho] = '1';
        determinaFrequenciaDFS(a->dir, caminho, ++tamCaminho, l);
    }
}

// A partir da árvore de frequência, codifica a frase buffer.
// tipoCod é para determinar se vai codificar por letra ou palavra
// 1 — Letra
// 0 — palavra
// Pré-condição: Tomar cuidado com o parâmetro lFreq.
char* codificaHuffman (char* buffer, struct noArvore* a, int tipoCod, struct NoListaSimples *lFreq) {
    char* codigo = NULL, *bAux = NULL;
    struct NoListaSimples *lAux = NULL;
    if(*buffer == '\0')
        return "\0";
    if(tipoCod) {
        *bAux = *buffer;
        lAux = buscaListaSimples(lFreq, bAux);
        if (lAux == NULL) {
            determinaFrequenciaDFS(a, NULL, 0, lFreq);
            lAux = buscaListaSimples(lFreq, bAux);
        }
        codigo = strcat(lAux->frequencia, codificaHuffman(++buffer, a, tipoCod, lFreq));
        return codigo;
    } else {
        sscanf(buffer, "%s", bAux);
        lAux = buscaListaSimples(lFreq, bAux);
        if (lAux == NULL) {
            determinaFrequenciaDFS(a, NULL, 0, lFreq);
            lAux = buscaListaSimples(lFreq, bAux);
        }
        codigo = lAux->frequencia;
        if(*(buffer + sizeof(bAux)) == ' ') {
            codigo = strcat(codigo, codificaHuffman(" ", a, 1, lFreq)); // Considerando os espaços.
            codigo = strcat(codigo, codificaHuffman(buffer += sizeof(bAux + 1), a, tipoCod, lFreq));
        }
        return codigo;
    }
}