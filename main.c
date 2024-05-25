#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da pessoa
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

// Função de comparação para qsort (compara idades)
int compararIdades(const void *a, const void *b) {
    // Conversão dos ponteiros para o tipo correto (Pessoa *)
    const Pessoa *pessoaA = (const Pessoa *)a;
    const Pessoa *pessoaB = (const Pessoa *)b;

    // Retorna a diferença entre as idades
    // Se a idade de A for menor, o resultado será negativo
    // Se a idade de B for menor, o resultado será positivo
    // Se as idades forem iguais, o resultado será zero
    return pessoaA->idade - pessoaB->idade;
}

int main() {
    int tamanho;

    // Solicita o número de pessoas ao usuário
    printf("Digite o número de pessoas: ");
    scanf("%d", &tamanho);

    // Aloca memória para o array de pessoas
    Pessoa *pessoas = malloc(tamanho * sizeof(Pessoa));
    if (pessoas == NULL) {
        printf("Erro ao alocar memória para o array de pessoas.\n");
        return 1;
    }

    // Entrada de dados: solicita nome e idade de cada pessoa
    printf("Digite os nomes e idades das pessoas:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", pessoas[i].nome);
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
    }

    // Ordena o array de pessoas com base na idade usando qsort
    qsort(pessoas, tamanho, sizeof(Pessoa), compararIdades);

    // Saída ordenada: imprime o nome e a idade de cada pessoa
    printf("\nPessoas ordenadas por idade:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }

    // Libera a memória alocada para o array de pessoas
    free(pessoas);

    return 0;
}
