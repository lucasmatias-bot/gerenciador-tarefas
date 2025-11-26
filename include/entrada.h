#ifndef ENTRADA_H
#define ENTRADA_H

#include <stddef.h>

// Lê uma linha (com fgets) removendo '\n' se existir.
// Retorna 1 se sucesso, 0 se erro/EOF.
int lerLinha(char *destino, size_t tamanho);

// Lê um inteiro da entrada padrão (com validação simples).
// Retorna 1 se sucesso e escreve em *valor; caso contrário retorna 0.
int lerInteiro(int *valor);

// Limpa caracteres remanescentes do buffer de entrada.
void limparEntrada(void);

#endif