#ifndef SAIDA_H
#define SAIDA_H

#include "tarefa.h"

// Exibe um título delimitado
void exibirTitulo(const char *titulo);

// Exibe uma mensagem simples
void exibirMensagem(const char *mensagem);

// Exibe a lista formatada de tarefas
void exibirLista(const struct Tarefa tarefas[], int total);

#endif