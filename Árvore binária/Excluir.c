#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

TNoA* exclui(TNoA *raiz, int chave) {
    //TODO: Implementar essa função
    //Ela recebe a raiz da árvore e a chave a ser excluída
    //Ela retorna ponteiro para a nova raiz
    TNoA* novo = (TNoA*) malloc(sizeof(TNoA));
    TNoA* percorre = raiz->esq;
    TNoA* auxiliar;
    if(raiz == NULL){
        printf("Valor não existe \n");
        return NULL;
    }else{
        
        /*Verificando se a chave para excluir é igual a chave da raiz*/
        
        if(raiz->chave == chave){
            
            /*Se for igual e a raiz for uma folha, apenas apaga*/

            if(raiz->esq == NULL && raiz->dir == NULL){
                novo = NULL;
            }


            else{

                /*Caso o nó não seja folha testamos as suas duas possíveis posições*/
                
                
                if(raiz->esq != NULL && raiz->dir != NULL){  // Caso o nó possua dois filhos // 
                    
                    // Usei como referencial o que foi visto em aula e retornar o maior valor da subárvore a esquerda // 
                    while(percorre->dir != NULL){
                        percorre = percorre->dir;
                    }
                    raiz->chave = percorre->chave;
                    percorre->chave = chave;
                    raiz->esq = exclui(raiz->esq, chave);
                    return raiz;
                }else{                                      // Caso o nó possua um único filho //
                    if(raiz->esq != NULL){
                        auxiliar = raiz->esq;
                    }else
                        auxiliar = raiz->dir;
                    free(raiz);
                    return auxiliar;
                }

            }
        }else{ 
            novo = raiz;
            if(raiz->chave > chave){
                raiz->esq = exclui(raiz->esq, chave);
            }
            else
            raiz->dir = exclui(raiz->dir, chave);
        }
    }
    return novo; // retorna a nova árvore com a exclusão concluída

}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *insere(TNoA *no, int chave) {
    if (no == NULL) {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    } else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

int main(void) {

    /* A função main lê os dados de entrada, cria a árvore e chama a função solicitada no problema
     * depois imprime o resultado solicitado
     * ELA NÃO DEVE SER MODIFICADA
     * */
    TNoA *raiz;
    raiz = NULL;

    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;

    /* lê valores para criar a arvore
     * valores devem ser informados separados por traço
     * exemplo: 1-3-5-2-7-9-21-6 */
    scanf("%s", l);
    //quebra a string de entrada
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        raiz = insere(raiz, valor);
        ptr = strtok(NULL, delimitador);
    }

    //le valor a ser excluido
    scanf("%d", &valor);
    //Chama função
    raiz = exclui(raiz, valor);
    imprime(raiz, 0);
};