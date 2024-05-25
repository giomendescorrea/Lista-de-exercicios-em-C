#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"

int main() {
    FILE *arquivo;
    char opcao;
    char nomeBusca[50];

    // Abre o arquivo em modo de leitura e escrita binária
    arquivo = fopen("funcionarios.bin", "r+b");
    if (arquivo == NULL) {
        // Se o arquivo não existir, cria um novo
        arquivo = fopen("funcionarios.bin", "w+b");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
    }

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Adicionar novo registro\n");
        printf("2. Listar todos os registros\n");
        printf("3. Buscar por nome\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarRegistro(arquivo);
                break;
            case '2':
                listarRegistros(arquivo);
                break;
            case '3':
                printf("Digite o nome a ser buscado: ");
                scanf("%s", nomeBusca);
                buscarPorNome(arquivo, nomeBusca);
                break;
            case '4':
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != '4');

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}