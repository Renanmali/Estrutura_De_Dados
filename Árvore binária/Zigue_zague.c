#include "Corpo.c"

int zz(TAB* a){
    if(a == NULL){
        return 0;
    }
    if(a->esq == NULL || a->dir == NULL){
        zz(a->esq);
        zz(a->dir);
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    TAB* raiz;
    raiz = criaNo(1);
    raiz->esq = criaNo(2);
    raiz->dir = criaNo(3);
    // raiz->esq->esq = criaNo(4);
    // raiz->esq->dir = criaNo (5);
    // raiz->dir->esq = criaNo(6);
    int total = zz(raiz);
    printf("%d", total);
    
}