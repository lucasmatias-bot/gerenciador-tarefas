/*
   Nome do Projeto: Gerenciador de Tarefas
   Autor: Lucas Matias, Vytor Rodrigues
   Data: 10/11/2025
   Descrição: Um aplicativo simples para gerenciar tarefas diárias.
*/

#include <stdio.h>
#include "../include/processamento.h"
#include "../include/persistencia.h"
#include "../include/saida.h"
#include "../include/tarefa.h"
#include "../include/entrada.h"

int main(void) {
    struct Tarefa tarefas[MAX_TAREFAS];
    int total = carregarTarefas(tarefas);

    int opcao = -1;
    do {
        exibirTitulo("GERENCIADOR DE TAREFAS");
        printf("1. Adicionar tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Marcar tarefa como concluida\n");
        printf("4. Excluir tarefa\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        if (!lerInteiro(&opcao)) {
            exibirMensagem("Entrada invalida.");
            opcao = -1;
            continue;
        }

        // Processa e decide continuar ou sair
        int continua = processarOpcao(opcao, tarefas, &total);
        if (!continua) break;

    } while (1);

    return 0;
}
