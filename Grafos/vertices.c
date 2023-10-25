#include <stdio.h>
#include <stdlib.h>

typedef struct  viz{
    int id_vizinho;
    struct viz* prox;

}TVizinho;

typedef struct grafo{
    int id;
    struct grafo* prox;
    TVizinho* primeiro_vizinho;
}TGrafo;


TGrafo *inserirVertice(TGrafo *grafo, int id_vertice) {
    TGrafo *novoVertice = (TGrafo *)malloc(sizeof(TGrafo));
    novoVertice->id = id_vertice;
    novoVertice->prox = NULL;
    novoVertice->primeiro_vizinho = NULL;

    if (grafo == NULL) {
        // Se o grafo estiver vazio, o novo vértice se torna o primeiro vértice
        return novoVertice;
    }

    // Encontra o último vértice na lista
    TGrafo *ultimoVertice = grafo;
    while (ultimoVertice->prox != NULL) {
        ultimoVertice = ultimoVertice->prox;
    }

    // Insere o novo vértice no final da lista
    ultimoVertice->prox = novoVertice;
    return grafo;
}

TVizinho *criarVizinho(int id_vizinho) {
    TVizinho *novoVizinho = (TVizinho *)malloc(sizeof(TVizinho));
    novoVizinho->id_vizinho = id_vizinho;
    novoVizinho->prox = NULL;
    return novoVizinho;
}

TGrafo *inserirAresta(TGrafo *grafo, int origem, int destino) {
    // Encontra o vértice de origem
    TGrafo *verticeOrigem = grafo;
    while (verticeOrigem != NULL && verticeOrigem->id != origem) {
        verticeOrigem = verticeOrigem->prox;
    }

    if (verticeOrigem == NULL) {
        // Vértice de origem não encontrado
        return grafo;
    }

    // Cria um novo vizinho para o vértice de destino
    TVizinho *novoVizinho = criarVizinho(destino);

    // Insere o novo vizinho no início da lista de vizinhos do vértice de origem
    novoVizinho->prox = verticeOrigem->primeiro_vizinho;
    verticeOrigem->primeiro_vizinho = novoVizinho;

    return grafo;
}

int na(TGrafo* g){
    int aresta = 0;
    if(g == NULL){
        return 0;
    }
    TGrafo* vertice = g;
    while(vertice != NULL){
        TVizinho* vizinho = vertice->primeiro_vizinho;
        while(vizinho != NULL){
            vizinho = vizinho->prox;
            aresta ++;
        }
        vertice = vertice->prox;
    }
    return aresta;
}

int nv(TGrafo* g){
    int quant = 1;
    if(g == NULL){return 0;}

    while(g->prox != NULL){
        g = g->prox;
        quant ++;
    }

    return quant;

}

int main(void){
    TGrafo* inicio = NULL;
    inicio = inserirVertice(inicio, 1);
    inicio= inserirVertice(inicio,2);
    inicio= inserirVertice(inicio,3);
    inicio= inserirVertice(inicio,4);
    inicio= inserirVertice(inicio,5);
    inicio= inserirVertice(inicio,6);
    inicio= inserirVertice(inicio,7);
    inicio= inserirVertice(inicio,8);


    inicio = inserirAresta(inicio, 1, 2);
    inicio = inserirAresta(inicio, 1, 3);
    inicio = inserirAresta(inicio, 1, 4);
    inicio = inserirAresta(inicio, 1, 5);
    inicio = inserirAresta(inicio, 1, 6);
    inicio = inserirAresta(inicio, 1, 7);
    
    int i = na(inicio);
    printf("%d", i);
}