#include <stdio.h>
#include <stdlib.h>



int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int));

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    float media = calcularMedia(array, tamanho);
    printf("Média: %.2f\n", media);

    float mediana = calcularMediana(array, tamanho);
    printf("Mediana: %.2f\n", mediana);

    int moda = calcularModa(array, tamanho);
    printf("Moda: %d\n", moda);

    free(array);

    return 0;
}
