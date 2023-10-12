#include "Corpo.c"

int nf(TAB* a){
    if(a == NULL){
        return 0;
    }
    if(a->dir == NULL && a->esq == NULL){
        return 1;
    }
    return nf(a->esq) + nf(a->dir);
}

int main(void){
    TAB* raiz;
    raiz = criaNo(1);
    raiz->esq = criaNo(2);
    // raiz->dir = criaNo(3);
    // raiz->esq->esq = criaNo(4);
    // raiz->esq->dir = criaNo (5);
    // raiz->dir->esq = criaNo(6);
    int total = nf(raiz);
    printf("%d", total);
    
}