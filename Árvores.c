#include <stdio.h>
#include <stdlib.h>

typedef struct noA{
    int info;
    struct noA* esq;
    struct noA* dir;
}TNoA;

TNoA *criaNo(int ch){
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

TNoA* espelho(TNoA *raiz) {
    //TODO: Implementar essa funcão
    TNoA* original = raiz;
    TNoA* espelhar = NULL;
    if(original == NULL) {return original;}
    
    espelhar = original;
    TNoA* aux = original->esq;
    original->esq = original->dir;
    original->dir = aux;
    espelho(original->esq);
    espelho(original->dir);
    return espelhar;
    
}


int main(void){
    TNoA *raiz;
    raiz = criaNo('10');
    raiz->esq = criaNo('15');
    raiz->dir = criaNo(20);
    raiz->esq->esq = criaNo(40);
    raiz->esq->dir = criaNo(3);
    TNoA* guarda = espelho(raiz);
    // guarda->esq->esq->dir = criaNo('E');
    printf("\n");
    imprime(guarda, 0);
    
}