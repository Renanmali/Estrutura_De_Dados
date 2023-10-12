#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    int cor;
    struct ab* esq;
    struct ab* dir;
}TAB;

TAB *criaNo(int ch){
    TAB* novo;
    novo = (TAB *) malloc(sizeof(TAB));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imprime(TAB *nodo, int tab){
    for(int i = 0; i < tab; i++){
        printf("-");
    }
    if(nodo != NULL){
        printf("%d\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    }else printf("vazio");
}

