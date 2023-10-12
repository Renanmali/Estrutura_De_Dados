#include "Corpo.c"

TAB* retira_pares(TAB* arv){
    if(arv == NULL){
        return NULL;
    }
    
    arv->esq = retira_pares(arv->esq);
    arv->dir = retira_pares(arv->dir);

    if(arv->info%2 == 0){
        
        if(arv->esq != NULL){
            TAB* temp = arv;
            arv = arv->esq;
            free(temp);
        }else{
            TAB* temp = arv;
            arv = arv->dir;
            free(temp);
        }
    }

    return arv;
}

int main(void){
    TAB* raiz;
    raiz = criaNo(1);
    raiz->esq = criaNo(2);
    raiz->dir = criaNo(3);
    raiz->esq->esq = criaNo(4);
    raiz->esq->dir = criaNo (5);
    raiz->dir->esq = criaNo(6);
    TAB* final = retira_pares(raiz);
    imprime(final,0);
}