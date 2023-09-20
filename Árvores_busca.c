#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA{
    char info;
    int chave;
    struct sNoA* esq;
    struct sNoA* dir;
}TNoA;

TNoA* busca(TNoA* no, int chave){
    TNoA* aux = no;
    while(aux->chave != chave && aux->chave != NULL){
        if(aux->chave < chave){
            aux = aux->dir;
        }
        if(aux->chave > chave){
            aux = aux->esq;
        }
    }
    if(aux->chave == chave){
        return aux;
    }else{
        return NULL;
    }
}

int main(void){
    
}