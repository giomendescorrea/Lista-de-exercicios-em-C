#include <stdio.h>

#define LEN 10

typedef struct {
    int dados[LEN];
    int qtde;
} LES;

int is_full(LES *les){
    return les->qtde == LEN;
}

int get_index(LES *les, int value){
    int i = 0;
    while(i < les->qtde && value > les->dados[i]){
        i++;
    }
    return i;
}

void move_right(LES *les, int i){
    for (int n = les->qtde; n > i; n--){
        les->dados[n] = les->dados[n-1];
    }
}

void insert(LES *les, int value){
    if(is_full(les)){
        return;
    }
    int idx = get_index(les, value);
    move_right(les, idx);
    les->dados[idx] = value;
    les->qtde++;
}

void show(LES *les){
    for (int i = 0; i < les->qtde; i++){
        printf("%d", les->dados[i]);
    }
    printf("\n");
}

int main(){
    LES les;
    les.qtde = 0;
    LES *p_les = &les;
    for(int num = 10; num >= 0; num--){
        insert(p_les, num);
        show(p_les);
    }
    return 0;
}

