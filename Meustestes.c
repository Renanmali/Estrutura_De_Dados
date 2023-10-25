#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} NoArvore;

typedef struct NoLista {
    int valor;
    struct NoLista *prox;
} NoLista;

NoArvore *criarNo(int valor) {
    NoArvore *novoNo = (NoArvore *)malloc(sizeof(NoArvore));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

NoLista *inserirLista(NoLista *cabeca, int valor) {
    NoLista *novoNo = (NoLista *)malloc(sizeof(NoLista));
    novoNo->valor = valor;
    novoNo->prox = cabeca;
    return novoNo;
}

NoLista *valoresEntreMEN(NoArvore *raiz, int m, int n) {
    if (raiz == NULL) {
        return NULL;
    }

    NoLista *lista = NULL;

    if (raiz->valor > m && raiz->valor < n) {
        lista = inserirLista(lista, raiz->valor);
    }

    NoLista *esquerda = valoresEntreMEN(raiz->esquerda, m, n);
    NoLista *direita = valoresEntreMEN(raiz->direita, m, n);

    // Concatenar as listas
    NoLista *atual = lista;
    if (atual == NULL) {
        lista = esquerda;
    } else {
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = esquerda;
    }

    // Concatenar a lista da direita
    atual = lista;
    if (atual == NULL) {
        lista = direita;
    } else {
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = direita;
    }

    return lista;
}

void imprimirLista(NoLista *cabeca) {
    NoLista *atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void liberarLista(NoLista *cabeca) {
    NoLista *atual = cabeca;
    while (atual != NULL) {
        NoLista *prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int main() {
    // Construa uma árvore binária simples
    NoArvore *raiz = criarNo(5);
    raiz->esquerda = criarNo(3);
    raiz->direita = criarNo(8);
    raiz->esquerda->esquerda = criarNo(2);
    raiz->esquerda->direita = criarNo(4);
    raiz->direita->esquerda = criarNo(7);
    raiz->direita->direita = criarNo(10);

    int m = 3; // Valor mínimo
    int n = 7; // Valor máximo

    // Obtenha uma lista de valores entre m e n na árvore
    NoLista *lista = valoresEntreMEN(raiz, m, n);

    // Imprima os valores da lista
    printf("Valores entre %d e %d na árvore: ", m, n);
    imprimirLista(lista);

    // Lembre-se de liberar a memória alocada para a lista e a árvore.

    return 0;
}

