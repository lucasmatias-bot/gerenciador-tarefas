#include <stdio.h>
#include <string.h>
#include "../include/tarefa.h"
#include "../include/entrada.h"
#include "../include/saida.h"

void adicionarTarefa(struct Tarefa tarefas[], int *total) {
    if (*total >= MAX_TAREFAS) {
        exibirMensagem("Limite maximo de tarefas atingido!");
        return;
    }

    exibirMensagem("Digite a descricao da tarefa:");
    if (!lerLinha(tarefas[*total].descricao, sizeof(tarefas[*total].descricao))) {
        exibirMensagem("Erro ao ler descricao.");
        return;
    }

    exibirMensagem("Digite a data da tarefa:");
    if (!lerLinha(tarefas[*total].data, sizeof(tarefas[*total].data))) {
        exibirMensagem("Erro ao ler data.");
        return;
    }

    tarefas[*total].concluida = 0;
    (*total)++;
    exibirMensagem("Tarefa adicionada com sucesso!");
}

void listarTarefas(const struct Tarefa tarefas[], int total) {
    exibirLista(tarefas, total);
}

void marcarConcluida(struct Tarefa tarefas[], int total) {
    int num;
    exibirMensagem("Digite o numero da tarefa para marcar como concluida:");
    if (!lerInteiro(&num)) {
        exibirMensagem("Entrada invalida.");
        return;
    }

    if (!validarIndiceTarefa(num, total)) {
        exibirMensagem("Numero de tarefa invalido!");
        return;
    }

    tarefas[num - 1].concluida = 1;
    exibirMensagem("Tarefa marcada como concluida!");
}

void excluirTarefa(struct Tarefa tarefas[], int *total) {
    int num;
    exibirMensagem("Digite o numero da tarefa para excluir:");
    if (!lerInteiro(&num)) {
        exibirMensagem("Entrada invalida.");
        return;
    }

    if (!validarIndiceTarefa(num, *total)) {
        exibirMensagem("Numero de tarefa invalido!");
        return;
    }

    for (int i = num - 1; i < *total - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }
    (*total)--;
    exibirMensagem("Tarefa excluida com sucesso!");
}

int validarIndiceTarefa(int indice, int total) {
    return (indice > 0 && indice <= total);
}