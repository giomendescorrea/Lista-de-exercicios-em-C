#include <stdio.h>
#include "produtos.h"

int main (){
  Produto produtos[TOTAL];
  int opcao;
  int pos = 0;
  ERROS resultado;
  do {
    printf("\nBEM VINDO!\n");
    printf("1. Cadastrar produto\n");
    printf("2. Listar produtos\n");
    printf("3. Calcular valor total em estoque\n");
    printf("0. Sair\n");
    printf("Digite a opção desejada:");
    scanf("%d", &opcao);

    switch (opcao){
      case 1:
        resultado = cadastrar(produtos, &pos);
        break;
      case 2:
        resultado = listar(produtos, &pos);
        break;  
      case 3:
        resultado = calcular(produtos, &pos);
        break;
      default:
        printf("Erro desconhecido.");
        break;
    }
  }
  while (opcao != 0);
}