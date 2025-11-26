# Gerenciador de Tarefas

## Nome do Projeto
**Gerenciador de Tarefas**

---

## Objetivo Geral
Desenvolver um sistema em linguagem **C** que auxilie o usuário a organizar e acompanhar suas atividades diárias. O projeto tem como objetivo principal melhorar a produtividade e o planejamento pessoal por meio de um controle eficiente das tarefas.

---

## Principais Funcionalidades Previstas
- Cadastrar novas tarefas informando nome e descrição.  
- Listar todas as tarefas cadastradas.  
- Marcar tarefas como concluídas.  
- Excluir tarefas da lista.  
- Salvar e carregar as tarefas de um arquivo texto, garantindo persistência dos dados.  

---

## conteudo c usado no projeto

Variáveis e tipos de dados
Estruturas de controle de fluxo (como if, while, for)

Funções

Ponteiros

Manipulação de strings:
 fgets e strtok

Manipulação de arquivos:
 fopen, fclose, fscanf, fprintf e fgets

Funções de entrada e saída:
 printf e scanf

Funções de manipulação de arrays e strings:
 fgets, strtok, strock, strncpy, strcspn, strcpy, strlen, strcat, strcmp, strdup, free

## Nome dos Autores
**Lucas Matias dos Santos e Vytor Rodrigues**
---
## etapas futuras
pegar data direto do servido, sem precisar adicionar manualmente.
Implementar a validação de formatos de dados utilizando expressões regulares, tornando o processo mais robusto e confiável.

## estrutura de pasta
```
Gerenciador de tarefas/
├── src/
│   ├── main.c
│   ├── entrada.c
│   ├── persistencia.c
│   ├── processamento.c
│   ├── saida.c
│   └── tarefa.c
├── include/
│   ├── entrada.h
│   ├── processamento.h
│   ├── persistencia.h
│   ├── saida.h
│   └── tarefa.h
├── docs/
│   ├── relatorio.docx
│   ├── Gerenciador de tarefas.docx
│   ├── analise_refatoracao.txt
│   ├── definicao_structs.txt
│   ├── estrutura_modulos.txt
│   └── definicao_headers.txt
├── backup/
│   ├── tarefas.txt
└── .gitignore
```
## Orientações de Compilação e Execução

### Compilação
Para compilar o programa, utilize o compilador **GCC** (GNU Compiler Collection):

```bash
gcc -Wall -std=c99 src/*.c -I include -o bin/gerenciador-tarefas

