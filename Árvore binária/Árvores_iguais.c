#include <stdio.h>
#include <stdlib.h>
#include "Corpo.c"

int igual(TAB* A1, TAB* A2){
    TAB* av = A1;
    TAB* av1 = A2;

    if(av == NULL && av1 == NULL){
        return 1;
    }
    if(av == NULL || av1 == NULL){
        return 0;
    }
    if(av->info == av1->info && igual(av->esq, av1->esq) && igual(av->dir, av1->dir)){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    TAB* av;
    TAB* av1;
    av = criaNo(1);
    av1 = criaNo(1);
    int compara = igual(av, av1);
    printf("%d", compara);
}