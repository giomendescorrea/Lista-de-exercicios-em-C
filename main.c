#include <stdio.h>
#include <string.h>

int main() {
    char string[50];
    int vogais = 0;

    printf("Digite uma string: ");
    scanf("%s", string); // Lê a string até que uma nova linha seja encontrada

    // percorre a string pra contar as vogais
    for (int i = 0; i < strlen(string); i++) { // percorre até o tamanho total da string
        // verifica se o caractere atual é uma vogal
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
            vogais++; //adiciona no número de vogais encontradas
            }
        }

        // printa o número de vogais encontradas na string
    printf("O número de vogais nessa string é: %d\n", vogais);
    return 0;
}
