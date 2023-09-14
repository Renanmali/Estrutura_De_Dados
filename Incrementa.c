// Incrementação via alocação dinâmica //

#include <stdio.h>
#include <stdlib.h>

/*Criando a struct lista*/
struct lista{
        int info;
        struct lista* prox;
    };

typedef struct lista TLista;

/*Criando uma função que cria lista*/

TLista* cria_lista (void){
        return NULL;
    }

/*Criando uma função que adiciona um valor ao ínicio*/
TLista* insere_inicio(TLista* li, int i){
        TLista* novo = (TLista*) malloc(sizeof(TLista));
        novo->info = i;
        novo->prox = li;
        return novo;
        printf("%d", i);
    }
/*Criando uma função que insere um número no fim*/

TLista* insere_fim(TLista* li, int i){
    TLista* novo = (TLista*) malloc(sizeof(TLista)); /*Criando um novo elemento temporário*/
    novo->info = i; /*Passando a informação para esse novo elemento*/
    novo->prox=li; /*Recebendo o li da lista*/
    TLista* p = li; /*Criando uma TLista* temporária para alocar e comparar dados*/
    TLista* ant = li; /*Criando uma TLista* temporária para alocar e comparar dados*/
    while(p != NULL){ /*Comparando se o conteúdo de p é ou não um NULL e caso não seja passando esse conteúdo para ant*/
        ant = p;
        p = p->prox;
    }
    if(ant != NULL){ /* Se ant for diferente de NULL ele recebe o que está em novo, adicionando assim a lista */
        ant->prox = novo;
    }
    else /*Caso seja igual a NULL, li recebe o conteúdo de novo, ou seja, info e o prox*/
        li = novo; 
    return li;
}

/*Criando uma função que insere os valores de maneira ordenada*/
TLista* insere_ordenado(TLista* li, int i){
    TLista* p = li;
    TLista* ant = NULL;
    while(p != NULL && p->info<i){
        ant = p;
        p = p->prox;
    }
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    if(ant == NULL){
        novo->prox = li;
        li = novo;
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return li;
}

int main(){
    TLista* v = (TLista*) malloc(sizeof(TLista));
    insere_inicio(v, 5);
    return 0;
}


