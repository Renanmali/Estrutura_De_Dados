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
    if(a == NULL){return a;}
    TAB* aux = a;

    TAB* auxDir = menor(a->dir);
    if(auxDir != NULL && auxDir->info < aux->info){
        aux = auxDir;
    }

    TAB* auxEsq = menor(a->esq);
    if(auxEsq != NULL && auxEsq->info < aux->info){
        aux = auxEsq;
    }
    
    return aux;
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
    raiz->dir = criaNo(2);
    raiz->esq->esq = criaNo(12);
    raiz->esq->esq->dir = criaNo(3);
    TAB* guarda = menor(raiz);
    int resultado = guarda->info;
    printf("%d \n", resultado);
}