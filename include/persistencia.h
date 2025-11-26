#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "tarefa.h"

// Salva tarefas em backup/tarefas.txt (formato: descricao|data|concluida)
void salvarTarefas(const struct Tarefa tarefas[], int total);

// Carrega tarefas de backup/tarefas.txt
int carregarTarefas(struct Tarefa tarefas[]);

#endif