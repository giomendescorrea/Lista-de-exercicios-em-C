#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.c"

// Função para adicionar um novo registro ao arquivo
void adicionarRegistro(FILE *arquivo) {
    Funcionario funcionario;

    printf("Digite o nome do funcionário: ");
    scanf("%s", funcionario.nome);

    printf("Digite a idade do funcionário: ");
    scanf("%d", &funcionario.idade);

    printf("Digite o salário do funcionário: ");
    scanf("%f", &funcionario.salario);

    // Escreve o registro no final do arquivo
    fwrite(&funcionario, sizeof(Funcionario), 1, arquivo);

    printf("Registro adicionado com sucesso!\n");
}

// Função para listar todos os registros do arquivo
void listarRegistros(FILE *arquivo) {
    Funcionario funcionario;

    // Retorna ao início do arquivo
    fseek(arquivo, 0, SEEK_SET);

    printf("\nLista de funcionarios:\n");
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
    }
}

// Função para buscar registros por nome
void buscarPorNome(FILE *arquivo, const char *nomeBusca) {
    Funcionario funcionario;
    int encontrado = 0;

    // Retorna ao início do arquivo
    fseek(arquivo, 0, SEEK_SET);

    // Busca por registros com o nome fornecido
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
        if (strcmp(funcionario.nome, nomeBusca) == 0) {
            printf("Nome: %s, Idade: %d, Salário: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum registro encontrado com o nome %s.\n", nomeBusca);
    }
}