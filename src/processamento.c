#include <stdio.h>
#include "../include/processamento.h"
#include "../include/tarefa.h"
#include "../include/persistencia.h"
#include "../include/saida.h"

int processarOpcao(int opcao, struct Tarefa tarefas[], int *total) {
    switch (opcao) {
        case 1:
            adicionarTarefa(tarefas, total);
            return 1;
        case 2:
            listarTarefas(tarefas, *total);
            return 1;
        case 3:
            marcarConcluida(tarefas, *total);
            return 1;
        case 4:
            excluirTarefa(tarefas, total);
            return 1;
        case 0:
            salvarTarefas(tarefas, *total);
            exibirMensagem("Tarefas salvas. Saindo...");
            return 0;
        default:
            exibirMensagem("Opcao invalida! Tente novamente.");
            return 1;
    }
}