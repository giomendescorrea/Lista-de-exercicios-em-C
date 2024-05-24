#include <stdio.h>

int main() {
    int tamanho; 

    printf("Digite o tamanho do array desejado: ");
    scanf("%d", &tamanho);

    // array vai ter o tamanho especificado pelo usuário
    int array[tamanho];

    // solicito ao usuário para inserir os elementos do array até dar o tamanho do array
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // calcula a soma dos elementos do array
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    // printa a soma dos elementos
    printf("A soma dos elementos do array é: %d\n", soma);
    return 0;
}
