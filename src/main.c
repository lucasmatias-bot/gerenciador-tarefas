/*
   Nome do Projeto: Gerenciador de Tarefas
   Autor: Lucas Matias, Vytor Rodrigues
   Data: 10/11/2025
   Descrição: Um aplicativo simples para gerenciar tarefas diárias.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100

// Define a estrutura para uma tarefa.
// Esta estrutura agrupa todas as informações relacionadas a uma única tarefa.
struct Tarefa {
    char descricao[100]; // Armazena a descrição da tarefa (até 99 caracteres).
    char data[20];       // Armazena a data de conclusão da tarefa (até 19 caracteres).
    int concluida;       // Flag para indicar se a tarefa foi concluída (1 para sim, 0 para não).
};

// Função para salvar as tarefas em um arquivo
// Parâmetros:
// array de estruturas Tarefa contendo as tarefas a serem salvas.
// total: número total de tarefas no array.
// Retorno: Nenhum.
void salvarTarefas(struct Tarefa tarefas[], int total) {
    FILE *arquivo = fopen("../backup/tarefas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar tarefas!\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%s|%s|%d\n", tarefas[i].descricao, tarefas[i].data, tarefas[i].concluida);
    }
    fclose(arquivo);
}

// Função para carregar as tarefas de um arquivo
// Parâmetros:
// array de estruturas Tarefa onde as tarefas carregadas serão armazenadas.
// Retorno: O número total de tarefas carregadas.
int carregarTarefas(struct Tarefa tarefas[]) {
    FILE *arquivo = fopen("../backup/tarefas.txt", "r");
    if (arquivo == NULL) {
        return 0; // Nenhum arquivo encontrado
    }
    int total = 0;
    while (fgets(tarefas[total].descricao, sizeof(tarefas[total].descricao), arquivo)) {
        char linha[150];
        strcpy(linha, tarefas[total].descricao);
        char *descricao = strtok(linha, "|");
        char *data = strtok(NULL, "|");
        char *concluida = strtok(NULL, "\n");

        if (descricao && data && concluida) {
            strncpy(tarefas[total].descricao, descricao, sizeof(tarefas[total].descricao));
            strncpy(tarefas[total].data, data, sizeof(tarefas[total].data));
            tarefas[total].concluida = atoi(concluida);
            total++;
        }
    }
    fclose(arquivo);
    return total;
}

int main() {
    struct Tarefa tarefas[MAX_TAREFAS];
    int total = carregarTarefas(tarefas);
    int opcao;

    do {
        printf("\n******* GERENCIADOR DE TAREFAS ******\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Marcar tarefa como concluida\n");
        printf("4. Excluir tarefa\n");
        printf("0. Sair\n");
        printf("**********************************\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (total < MAX_TAREFAS) {
                    printf("Digite a descricao da tarefa: ");
                    fgets(tarefas[total].descricao, sizeof(tarefas[total].descricao), stdin);
                    tarefas[total].descricao[strcspn(tarefas[total].descricao, "\n")] = 0;
                    printf("Digite a data da tarefa: ");
                    fgets(tarefas[total].data, sizeof(tarefas[total].data), stdin);
                    tarefas[total].data[strcspn(tarefas[total].data, "\n")] = 0;
                    tarefas[total].concluida = 0;
                    total++;
                    printf("Tarefa adicionada com sucesso!\n");
                } else {
                    printf("Limite maximo de tarefas atingido!\n");
                }
                break;
            case 2:
                if (total == 0) {
                    printf("Nenhuma tarefa cadastrada.\n");
                } else {
                    printf("\n****** LISTA DE TAREFAS ******\n");
                    for (int i = 0; i < total; i++) {
                        printf("%d. [%s] %s (Data: %s)\n", i + 1, tarefas[i].concluida ? "X" : " ", tarefas[i].descricao, tarefas[i].data);
                    }
                }
                break;
            case 3: {
                int num;
                printf("Digite o numero da tarefa para marcar como concluida: ");
                scanf("%d", &num);
                if (num > 0 && num <= total) {
                    tarefas[num - 1].concluida = 1;
                    printf("Tarefa marcada como concluida!\n");
                } else {
                    printf("Numero de tarefa invalido!\n");
                }
                break;
            }
            case 4: {
                int num;
                printf("Digite o numero da tarefa para excluir: ");
                scanf("%d", &num);
                if (num > 0 && num <= total) {
                    for (int i = num - 1; i < total - 1; i++) {
                        tarefas[i] = tarefas[i + 1];
                    }
                    total--;
                    printf("Tarefa excluida com sucesso!\n");
                } else {
                    printf("Numero de tarefa invalido!\n");
                }
                break;
            }
            case 0:
                salvarTarefas(tarefas, total);
                printf("Tarefas salvas. Saindo do Gerenciador...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
