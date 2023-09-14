#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct noA{
    int info;
    struct noA* esq;
    struct noA* dir;
}TNoA;

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

int power(int x,int n)
{
    int i; /* Variable used in loop counter */
    int number = 1;

    for (i = 0; i < n; ++i)
        number *= x;

    return(number);
}

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

void aux(TNoA* no, int n, int linha, int conta){
    TLista* auxiliar = NULL; TNoA* percorre = no;
    

}

void imprimir(TNoA *nodo){
    TNoA* contador = nodo;
    int tamanho = 0;
    while(contador != NULL){
        contador = contador->esq;
        tamanho++;
    }
    aux(nodo, tamanho, 3, 0);
}

int main(void){
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->esq->esq = criaNo('D');
    raiz->esq->dir = criaNo('E');
    raiz->dir->esq = criaNo('F');
    raiz->dir->dir = criaNo('G');
    raiz->esq->esq->esq = criaNo('H');
    raiz->esq->esq->dir = criaNo('I');
    raiz->esq->dir->esq = criaNo('J');
    raiz->esq->dir->dir = criaNo('K');
    raiz->dir->esq->esq = criaNo('L');
    raiz->dir->esq->dir = criaNo('M');
    raiz->dir->dir->esq = criaNo('N');
    raiz->dir->dir->dir = criaNo('O');

    imprime(raiz, 0);
    printf("\n");
    imprimir(raiz);
}