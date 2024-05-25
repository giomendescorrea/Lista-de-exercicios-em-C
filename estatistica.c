#include <stdlib.h>

// Função para comparar dois números (usada na função de ordenação)
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função para calcular a média dos elementos no array
float calcularMedia(int *array, int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma / tamanho;
}

// Função para calcular a mediana dos elementos no array
float calcularMediana(int *array, int tamanho) {
    qsort(array, tamanho, sizeof(int), comparar);
    if (tamanho % 2 == 0) {
        return (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0;
    } else {
        return array[tamanho / 2];
    }
}

// Função para calcular a moda dos elementos no array
int calcularModa(int *array, int tamanho) {
    qsort(array, tamanho, sizeof(int), comparar);

    int moda = array[0]; // Assume que o primeiro elemento é a moda inicial
    int contagem = 1;    // Contagem da moda inicial
    int maxContagem = 1; // Contagem máxima inicial

    for (int i = 1; i < tamanho; i++) {
        if (array[i] == array[i - 1]) {
            contagem++;
        } else {
            if (contagem > maxContagem) {
                maxContagem = contagem;
                moda = array[i - 1];
            }
            contagem = 1; // Reseta contagem para o próximo elemento
        }
    }

    // Verifica a contagem do último elemento
    if (contagem > maxContagem) {
        moda = array[tamanho - 1];
    }

    return moda;
}