#include <stdio.h>
#include <stdlib.h>

typedef struct noA{
    int info;
    struct noA* esq;
    struct noA* dir;
}TNoA;

TNoA *criaNo(char ch){
    TNoA* novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imprime(TNoA *nodo, int tab){
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

TNoA* copia(TNoA* original){
    TNoA* copia1 = NULL;
    if(original != NULL){
        copia1 = original;
        copia(original->esq);
        copia(original->dir);
    }
    return copia1;
}


int main(void){
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->esq->esq = criaNo('D');
    TNoA* guarda = copia(raiz);
    guarda->esq->esq->dir = criaNo('E');
    imprime(guarda, 0);
    
}