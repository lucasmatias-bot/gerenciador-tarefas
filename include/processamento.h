#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

#include "tarefa.h"

// Processa a opção selecionada pelo usuário.
// Retorna 0 para sair, 1 para continuar.
int processarOpcao(int opcao, struct Tarefa tarefas[], int *total);

#endif