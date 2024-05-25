#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Biblioteca para a função toupper

char* converter(char *string) {
  char *ptr = string; // Ponteiro para percorrer a string
  while (*ptr != '\0') {
    *ptr = toupper(*ptr); // Converte o caractere para maiúscula
    ptr++; // Avança para o próximo caractere
  }
  return string;
}

int main() {
  char entrada[100];
  printf("Digite uma string: ");
  fgets(entrada, sizeof(entrada), stdin);
  printf("String original: %s", entrada);
  char *saida = converter(entrada);
  printf("String convertida para maiúsculas: %s", saida);
  return 0;
}
