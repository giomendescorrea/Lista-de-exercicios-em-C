#include <stdio.h>
#include <stdlib.h>

int* inverterArray(int *array, int tamanho) {
  int *arrayInvertido = (int *)malloc(tamanho * sizeof(int));
  for (int i = 0; i < tamanho; i++) {
    arrayInvertido[i] = array[tamanho - 1 - i];
  }
  return arrayInvertido;
}

int main() {
  int tamanho;

  printf("Digite o tamanho do array: ");
  scanf("%d", &tamanho);

  int *array = (int *)malloc(tamanho * sizeof(int));
  if (array == NULL) {
    printf("Erro ao alocar memória para o array.\n");
    return 1;
  }

  printf("Digite os elementos do array:\n");
  for (int i = 0; i < tamanho; i++) {
    scanf("%d", &array[i]);
  }

  int *arrayInvertido = inverterArray(array, tamanho);

  printf("Array invertido:\n");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", arrayInvertido[i]);
  }
  printf("\n");
  return 0;
}

