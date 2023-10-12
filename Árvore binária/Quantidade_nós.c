#include "Corpo.c"

int ni(TAB* a){
    if(a == NULL){
        return 0;
    }
    return 1 + ni(a->dir) + ni(a->esq);
}

int main(void){
    TAB* raiz;
    raiz = criaNo(1);
    raiz->esq = criaNo(2);
    raiz->dir = criaNo(3);
    raiz->esq->esq = criaNo(4);
    raiz->esq->dir = criaNo (5);
    raiz->dir->esq = criaNo(6);
    int total = ni(raiz);
    printf("%d", total);
    
}