#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da árvore binária
typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

// Função para criar um novo nó da árvore
TAB* criarNo(int valor) {
    TAB* novoNo = (TAB*)malloc(sizeof(TAB));
    novoNo->info = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

TAB* maior(TAB* a){
    
    if(a == NULL){return a;}
   
    TAB* aux = a;


    TAB* auxDir = maior(a->dir);
    TAB* auxEsq = maior(a->esq);
    if(auxDir != NULL && auxDir->info > aux->info){
        aux = auxDir;
    }
    if(auxEsq != NULL && auxEsq->info > aux->info){
        aux = auxEsq;
    }


    return aux;


}


int maior1(TAB* raiz) {
    if (raiz == NULL) {
        return -1; // Se a árvore estiver vazia, retorne um valor indicando erro (por exemplo, -1)
    }

    int maiorElemento = raiz->info;

    // Verifica o maior valor na subárvore à direita
    int maiorDireita = maior1(raiz->dir);
    int maiorEsquerda = maior1(raiz->esq);
    if (maiorDireita > maiorElemento) {
        maiorElemento = maiorDireita;
    }

    // Verifica o maior valor na subárvore à esquerda
   
    if (maiorEsquerda > maiorElemento) {
        maiorElemento = maiorEsquerda;
    }

    return maiorElemento;
}

void imprime(TAB *nodo, int tab){
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


int main(){
    TAB* raiz;
    raiz = criarNo(5);
    raiz->dir = criarNo(4);
    raiz->esq = criarNo(6);
    raiz->esq->esq = criarNo(40);
    raiz->esq->dir = criarNo(3);
    TAB* retorno = maior(raiz);
    
    imprime(retorno,0);
}