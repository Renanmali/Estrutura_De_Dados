#include <stdlib.h>
#include <stdio.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
}TABB;

TABB *criaNo(int ch){
    TABB* novo;
    novo = (TABB *) malloc(sizeof(TABB));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imprime(TABB *nodo, int tab){
    for(int i = 0; i < tab; i++){
        printf("-");
    }
    if(nodo != NULL){
        printf("%d\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    }else printf("vazio");
}

TABB* retira_impares(TABB* a){
    TABB* novo = (TABB*) malloc(sizeof(TABB));
    TABB* percorre = a->esq;
    TABB* aux;
    if(a == NULL) {return a;}
    else{
        if(a->info%2 == 1){
            if(a->esq == NULL && a->dir == NULL){
                novo = NULL;
            }
            else{
                if(a->esq != NULL && a->dir != NULL){  // Caso o nó possua dois filhos // 
                    
                    // Usei como referencial o que foi visto em aula e retornar o maior valor da subárvore a esquerda // 
                    while(percorre->dir != NULL){
                        percorre = percorre->dir;
                    }
                    aux = a;
                    a->info = percorre->info;
                    percorre->info = aux->info;
                    a->esq = retira_impares(a->esq);
                    return a;
                }else{                                      // Caso o nó possua um único filho //
                    if(a->esq != NULL){
                        aux = a->esq;
                    }else
                        aux = a->dir;
                    free(a);
                    return aux;
                }

            }
        }
        else{
            novo = a;
            retira_impares(a->esq);
            retira_impares(a->dir);
        }
    }

    return novo;
}

int main(void){
    TABB* raiz;
    raiz = criaNo(2);
    raiz->esq = criaNo(1);
    raiz->dir = criaNo(4);
    TABB* guarda = retira_impares(raiz);
    imprime(guarda, 0);
}