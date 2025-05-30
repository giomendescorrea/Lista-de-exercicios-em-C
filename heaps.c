#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
  int valores[LEN];
  int qtde;
} heap;

int filho_esq(int pai) { 
    return pai * 2 + 1;
    }

int filho_dir(int pai) { 
    return pai * 2 + 2;
    }

int pai(int filho) { 
    return (filho - 1) / 2;
    }

int ultimo_pai(heap *h) { 
    return (h->qtde / 2) - 1;
}

void peneirar(heap *h, int pai) {
    int f_esquerdo = filho_esq(pai);
    int f_direito = filho_dir(pai);
    int maior = pai;
    int substituto;
    if(f_esquerdo < h->qtde && h->valores[f_esquerdo] > h->valores[maior]){
        maior = f_esquerdo;
    }
    if(f_direito < h->qtde && h->valores[f_direito] > h->valores[maior]){
        maior = f_direito;
    }
    if(maior != pai){
        substituto = h->valores[pai];
        h->valores[pai] = h->valores[maior];
        h->valores[maior] = substituto;
        peneirar(h, maior);
    }
}        

void mostrar(heap *h) {
    for(int i = 0; i < h->qtde; i++){
        printf("%d ", h->valores[i]);
    }
    printf("\n");
}

void construir(heap *h) {
    for(int i = ultimo_pai(h); i >= 0; i--){
        peneirar(h, i);
    }
}

void inserir(heap *h, int valor) {
    h->valores[h->qtde++] = valor;
    int p = pai(h->qtde - 1);
    if(h->valores[p] < h->valores[h->qtde-1]){
        construir(h);
    }

}

void remover(heap *h) {
  if(h->qtde == 0){
    return;
  }
  h->valores[0] = h->valores[h->qtde - 1];
  h->qtde--;
  peneirar(h, 0);
}

int main(void) {
  heap *h = malloc(sizeof(heap));
  int valor;
  h->qtde = 0;
  for (int i = 0; i < LEN; i++) {
    scanf("%d", &valor);
    inserir(h, valor);
    mostrar(h);
  }
  for (int i = 0; i < LEN; i++) {
    remover(h);
    mostrar(h);
  }

  return 0;
}