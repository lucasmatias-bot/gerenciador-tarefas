#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/entrada.h"

int lerLinha(char *destino, size_t tamanho) {
    if (fgets(destino, (int)tamanho, stdin) == NULL) {
        return 0; // erro ou EOF
    }

    // Remove o '\n' se existir
    destino[strcspn(destino, "\n")] = '\0';

    // Verifica se a string está vazia
    if (destino[0] == '\0') {
        return 0; // não aceita entrada vazia
    }

    return 1; // sucesso
}
int lerInteiro(int *valor) {
    char buffer[100];

    // lê uma linha inteira da entrada
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0; // erro ou EOF
    }

    // remove o '\n' se existir
    buffer[strcspn(buffer, "\n")] = '\0';

    // tenta converter para inteiro
    char *endptr;
    long numero = strtol(buffer, &endptr, 10);

    // verifica se toda a string foi consumida e se não houve erro
    if (*endptr != '\0') {
        return 0; // havia caracteres inválidos
    }

    *valor = (int)numero;
    return 1;
}

void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}