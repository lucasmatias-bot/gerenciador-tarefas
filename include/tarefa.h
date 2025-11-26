#ifndef TAREFA_H
#define TAREFA_H

#define MAX_TAREFAS 100

// Representa uma tarefa de texto com data e status de conclusão.
// Campos:
//  - descricao: texto da tarefa (até 99 chars + '\0')
//  - data: data livre (até 19 chars + '\0')
//  - concluida: 0 (não) ou 1 (sim)
struct Tarefa {
    char descricao[100];
    char data[20];
    int concluida;
};

// Operações de manipulação de tarefas
void adicionarTarefa(struct Tarefa tarefas[], int *total);
void listarTarefas(const struct Tarefa tarefas[], int total);
void marcarConcluida(struct Tarefa tarefas[], int total);
void excluirTarefa(struct Tarefa tarefas[], int *total);

// Utilitário: valida índice a partir de entrada do usuário
int validarIndiceTarefa(int indice, int total);

#endif