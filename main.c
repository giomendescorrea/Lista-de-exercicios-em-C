#include <stdio.h>
#include <stdlib.h>

// função para transpõe uma matriz quadrada
void transporMatriz(int **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            // troca os elementos fora da diagonal principal
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }
}

// função que libera a memória alocada para uma matriz
void liberarMatriz(int **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// função para imprimir a matriz quadrada
void imprimirMatriz(int **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tamanho;

    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &tamanho);

    // aloca memória para a matriz
    int **matriz = (int **)malloc(tamanho * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memoria para a matriz.\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        matriz[i] = (int *)malloc(tamanho * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria para a matriz.\n");
            return 1;
        }
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz original:\n");
    imprimirMatriz(matriz, tamanho);

    // Transpõe a matriz
    transporMatriz(matriz, tamanho);

    printf("\nMatriz transposta:\n");
    imprimirMatriz(matriz, tamanho);

    // Libera a memória alocada
    liberarMatriz(matriz, tamanho);

    return 0;
}
