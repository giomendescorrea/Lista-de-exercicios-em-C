#include "produtos.h"
#include <stdio.h>
#include <string.h>

ERROS cadastrar(Produto *produtos, int *pos) {
  printf("Digite o nome do produto: ");
  scanf("%s", produtos[*pos].produto); 
  
  printf("Digite o preço do produto: ");
  scanf("%f", &produtos[*pos].valor);
  
  printf("Digite a quantidade em estoque: ");
  scanf("%d", &produtos[*pos].quantidade);

  printf("Produto cadastrado com sucesso.");
  pos = pos + 1; // Atualiza o contador de quantidade de produtos
  return OK;
}

// Função para exibir as informações de todos os produtos
ERROS listar(Produto *produtos, int *pos) {
  printf("Produtos cadastrados:\n");
  for (int i = 0; i < *pos; i++) {
      printf("Nome: %s\n", produtos[i].produto);
      printf("Valor: R$ %.2f\n", produtos[i].valor);
      printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
      printf("\n");
  }
  return OK;
}

// Função para calcular o valor total em estoque
ERROS calcular(Produto *produtos, int *pos) {
  for (int i = 0; i < *pos; i++) {
      printf("Nome: %s\n", produtos[i].produto);
      printf("Valor: R$ %.2f\n", produtos[i].valor);
      printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
      printf("Valor total do produto em estoque: %f\n", (produtos[i].valor * produtos[i].quantidade));
      printf("\n");
  }
  return OK;
}