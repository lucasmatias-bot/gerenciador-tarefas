#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/persistencia.h"

void salvarTarefas(const struct Tarefa tarefas[], int total) {
    FILE *arquivo = fopen("backup/tarefas.txt", "w");
    if (!arquivo) {
        printf("Erro ao salvar tarefas!\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        // cuidado com '|' nos campos (opcional: sanitizar)
        fprintf(arquivo, "%s|%s|%d\n",
                tarefas[i].descricao,
                tarefas[i].data,
                tarefas[i].concluida);
    }
    fclose(arquivo);
}

int carregarTarefas(struct Tarefa tarefas[]) {
    FILE *arquivo = fopen("backup/tarefas.txt", "r");
    if (!arquivo) {
        return 0; // Nenhum arquivo encontrado
    }

    int total = 0;
    char linha[150];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char *descricao = strtok(linha, "|");
        char *data = strtok(NULL, "|");
        char *concluida = strtok(NULL, "\n");

        if (descricao && data && concluida) {
            strncpy(tarefas[total].descricao, descricao, sizeof(tarefas[total].descricao));
            tarefas[total].descricao[sizeof(tarefas[total].descricao)-1] = '\0';

            strncpy(tarefas[total].data, data, sizeof(tarefas[total].data));
            tarefas[total].data[sizeof(tarefas[total].data)-1] = '\0';

            tarefas[total].concluida = atoi(concluida);
            total++;
            if (total >= MAX_TAREFAS) break;
        }
    }
    fclose(arquivo);
    return total;
}