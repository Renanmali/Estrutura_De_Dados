#include <stdio.h>
#include <stdlib.h>
#include "Corpo.c"

int na(TGrafo *g){
    int arestas = 0;
    if(g == NULL){
        return 0;
    }else{
        while(g->prox != NULL){
            arestas ++;
            na(g->prox);
        }
        return *arestas;
    }
}

int main(void){
    TGrafo* inicio;
    inicio = 1;
    insere_um_sentido(inicio, 1, 2);
    imprime(inicio);
}