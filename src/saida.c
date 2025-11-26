#include <stdio.h>
#include "../include/saida.h"

void exibirTitulo(const char *titulo) {
    printf("\n**********************************\n");
    printf("%s\n", titulo);
    printf("**********************************\n");
}

void exibirMensagem(const char *mensagem) {
    printf("%s\n", mensagem);
}

void exibirLista(const struct Tarefa tarefas[], int total) {
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    printf("\n****** LISTA DE TAREFAS ******\n");
    for (int i = 0; i < total; i++) {
        printf("%d. [%s] %s (Data: %s)\n",
               i + 1,
               tarefas[i].concluida ? "X" : " ",
               tarefas[i].descricao,
               tarefas[i].data);
    }
}