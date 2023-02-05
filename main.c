#include <stdio.h>
#include <stdlib.h>
#include "AlgoritmoHuffman.h"

int main() {
    system("chcp 65001");
    system("cls");
    char * buffer = "Olá, mundo! Tudo bem com você? Você parece não estar bem, mundo.";
    printf("Testando a codificação da frase: '%s', por letras.\n", buffer);

    char * codigo = codificaHuffman(buffer, montaArvore(determinaAlfabeto(buffer, 1)), 1, NULL);

    printf("Resultado = '%s'", codigo);

    return 0;
}
