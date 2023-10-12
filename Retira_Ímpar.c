#include <stdlib.h>
#include <stdio.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
}TABB;

TABB *criaNo(int ch){
    TABB* novo;
    novo = (TABB *) malloc(sizeof(TABB));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imprime(TABB *nodo, int tab){
    for(int i = 0; i < tab; i++){
        printf("-");
    }
    if(nodo != NULL){
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    }else printf("vazio");
}

TABB* retira_impares(TABB* a){
    TABB* novo = (TABB*) malloc(sizeof(TABB));
    novo = a;
    if(novo == NULL){
        return novo;
    }else{
        if(novo->info%2 == 1){
            novo = NULL;
        }else{
            retira_impares(novo->esq);
            retira_impares(novo->dir);
        }

    }
    return novo;
}

int main(void){
    TABB* raiz;
    raiz = criaNo(2);
    raiz->esq = criaNo(1);
    raiz->dir = criaNo(4);
    TABB* guarda = retira_impares(raiz);
    imprime(guarda, 0);
}