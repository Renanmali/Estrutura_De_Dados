#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
}TAB;

TAB *criaNo(int info){
    TAB* novo;
    novo = (TAB *) malloc(sizeof(TAB));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

TAB* menor(TAB * a){
    TAB* percorre = (TAB*) malloc(sizeof(TAB));
    if(a->esq !=NULL){
        menor(a->esq);
    }else{
        percorre->info = a->info;
        percorre->dir = a->dir;
        percorre->esq = a->esq;
        return percorre;
    }
}

void imprime(TAB *nodo, int tab){
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

int main(void){
    TAB *raiz;
    raiz = criaNo(5);
    raiz->esq = criaNo(4);
    raiz->dir = criaNo(9);
    raiz->esq->esq = criaNo(8);
    TAB* guarda = menor(raiz);
    int resultado = guarda->info;
    printf("%d \n", resultado);
}