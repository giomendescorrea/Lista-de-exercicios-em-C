#include <stdio.h>
#include <time.h>

void exemplo() {
    for (int i = 0; i < 100; i++) {
        printf("oie!");
    }
}

int main() {
    // armazena o tempo de início
    clock_t inicio = clock();

    // chama a função que contém o código de exemplo
    exemplo();

    // armazena o tempo de término
    clock_t fim = clock();

    // calcular o tempo decorrido em segundos
    double tempoDecorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo decorrido: %.6f segundos\n", tempoDecorrido);

    return 0;
}
