/*
   Nome do Projeto: Gerenciador de Tarefas
   Autor: Lucas Matias, Vytor Rodrigues
   Data: 2025
   Descrição: Um aplicativo simples para gerenciar tarefas diárias.
*/


#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 100

typedef struct {
    char descricao[100];
    int concluida; 
} Tarefa;

int main() {
    Tarefa tarefas[MAX_TAREFAS];
    int total = 0;
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
            case 1: {
                if (total < MAX_TAREFAS) {
                    printf("Digite a descricao da tarefa: ");
                    fgets(tarefas[total].descricao, sizeof(tarefas[total].descricao), stdin);
                    tarefas[total].descricao[strcspn(tarefas[total].descricao, "\n")] = 0; 
                    tarefas[total].concluida = 0;
                    total++;
                    printf("Tarefa adicionada com sucesso!\n");
                } else {
                    printf("Limite maximo de tarefas atingido!\n");
                }
                break;
            }
            case 2: {
                if (total == 0) {
                    printf("Nenhuma tarefa cadastrada.\n");
                } else {
                    printf("\n****** LISTA DE TAREFAS ******\n");
                    for (int i = 0; i < total; i++) {
                        printf("%d. [%c] %s\n", i + 1,
                               tarefas[i].concluida ? 'X' : ' ',
                               tarefas[i].descricao);
                    }
                }
                break;
            }
            case 3: {
                int num;
                printf("Digite o numero da tarefa para marcar como concluida: ");
                scanf("%d", &num);
                if (num > 0 && num <= total) {
                    tarefas[num - 1].concluida = 1;
                    printf("Tarefa marcada como concluida!\n");
                } else {
                    printf(" Numero de tarefa invalido!\n");
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
                    printf(" Numero de tarefa invalido!\n");
                }
                break;
            }
            case 0:
                printf("Saindo do Gerenciador de Tarefas...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
