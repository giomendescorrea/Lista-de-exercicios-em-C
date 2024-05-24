#define TOTAL 255
#define PRODUTO 25

// definição do struct que armazena cada contato inserido
typedef struct Produto {
  char produto[PRODUTO];
  float valor;
  int quantidade;
} Produto;

// enumera possíveis erros
typedef enum {OK} ERROS;

ERROS cadastrar(Produto produtos[], int *pos);
ERROS listar(Produto produtos[], int *pos);
ERROS calcular(Produto produtos[], int *pos);