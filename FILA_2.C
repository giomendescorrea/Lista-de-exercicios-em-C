#include <stdio.h>

#define LEN 100

typedef struct {
	char data[LEN];
	int head;
	int tail;
	int qtde;
} Queue;

void enqueue(Queue *queue, char caracter) {
    if(queue->qtde == LEN){
        return;
    }
    queue->data[queue->tail++] = caracter;
    queue->qtde++;
}

int dequeue(Queue *queue) {
    if(queue->qtde == 0){
        return 0;
    }
    char valor = queue->data[queue->head++];
    queue->qtde--;
    return valor;
}

void show(Queue *queue) {
    for(int i = queue->head; i < queue->tail; i++){
        printf("%c", queue->data[i]);
    }
}

void start_queue(Queue *queue) {
    queue->head = 0;
    queue->tail = 0;
    queue->qtde = 0;
}

int main(void) {
    char s[LEN];
    fgets(s, sizeof(s), stdin);
    Queue queue;
    
    start_queue(&queue);

    for (int i = 0; s[i] != '\0'; i++) {
        enqueue(&queue, s[i]);
    }
        
    // implementar
    Queue queue_parenteses;
    start_queue(&queue_parenteses);
    int flag = 1; // começa com 1, se ficar com 0 é falha e se ficar com 1 é sucesso

    for (int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '('){
            enqueue(&queue_parenteses, s[i]);
        }
        else if(s[i] == ')'){
            if(dequeue(&queue_parenteses) == 0){
                flag = 0;
                break;
            };
        }
        dequeue(&queue);
        show(&queue);
    }
    
    if(queue_parenteses.qtde != 0){
        flag = 0;
    }

    if(flag == 0){
        printf("incorreto");
    }
    else{
        printf("correto");
    }

    return 0;
}
