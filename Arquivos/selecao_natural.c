#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "geracao.c"

#include <limits.h>
#include <dirent.h>
#include <string.h>

typedef struct vetor {
    TCliente *cli;
} TVet;

void imprime_arquivo(char *nome) {
    FILE *arq; //declara ponteiro para arquivo
    // abre arquivo para leitura
    arq = fopen(nome, "r");
    if (arq != NULL) {// checa se não deu erro na abertura do arquivo
        char linha[150];
        fgets(linha, 150, arq);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s", linha);
            fgets(linha, 150, arq);
        }
        fclose(arq); //fecha arquivo
    } else printf("Erro ao abrir arquivo\n");
}

char *gera_nome_particao(int num_part) {
    char *nome_particao = (char *) malloc(sizeof(char[10]));
    char num_particao[10];

    strcpy(nome_particao, "p");
    sprintf(num_particao, "%d", num_part);
    strcat(nome_particao, num_particao);
    strcat(nome_particao, ".txt");

    return nome_particao;
}

int menor_valor(TCliente* vetor, int tam_memoria){
    int menor = vetor[0].cod_cliente; 
    for (int i = 1; i < tam_memoria; i++) {
        if (vetor[i].cod_cliente < menor && vetor[i].cod_cliente != 100000000000000000) {
            menor = vetor[i].cod_cliente;
        }
    }

    return menor;

}

int selecao_natural(char *nome_arquivo_entrada, int tam_memoria) {
    //TODO: Implementar essa função
    TCliente* vetor1 = (TCliente*) malloc(tam_memoria* sizeof(TCliente));
    TCliente* vetor2 = (TCliente*) malloc(tam_memoria* sizeof(TCliente));
    TCliente* memoria = (TCliente*) malloc(tam_memoria* sizeof(TCliente));
    int verifica = 0;
    int tam_vetor3 = 0;
    int menor;
    int result;
    FILE* arq;
    FILE* arq1;
    arq = fopen(nome_arquivo_entrada, "r");
    arq1 = fopen("teste.txt", "w");
    if(arq != NULL){
        int i = 0;
        int j = 0;
        while(!feof(arq)){
            TCliente* cliente = le_cliente(arq);
            if(i<tam_memoria){
                strcpy(vetor1[i].nome, cliente->nome);
                vetor1[i].cod_cliente = cliente->cod_cliente;
                i++ ;
            }
            else{
                strcpy(vetor2[j].nome, cliente->nome);
                vetor2[j].cod_cliente = cliente->cod_cliente;
                j++;
            }
        }   


        
        while(tam_vetor3 < tam_memoria && vetor2[verifica].nome != NULL){
            menor = menor_valor(vetor1, tam_memoria);
            int posicao = vetor2[verifica].cod_cliente;
            i = 0;
            while(vetor1[i].cod_cliente != menor){
                i ++; 
            }
            
            fprintf(arq1, "%d;%s\n", vetor1[i].cod_cliente, vetor1[i].nome);

            
            if(vetor1[i].cod_cliente < posicao){
                vetor1[i].cod_cliente = vetor2[verifica].cod_cliente;
                strcpy(vetor1[i].nome, vetor2[verifica].nome);
                verifica ++;
            }
            else{

                while(vetor1[i].cod_cliente > vetor2[verifica].cod_cliente && tam_vetor3 < tam_memoria && vetor2[verifica].nome != NULL){
                    
                    strcpy(memoria[tam_vetor3].nome, vetor2[verifica].nome);
                    memoria[tam_vetor3].cod_cliente = vetor2[verifica].cod_cliente;
                    //fprintf(arq1, "%d;%s\n",  memoria[tam_vetor3].cod_cliente, memoria[tam_vetor3].nome );
                    tam_vetor3 ++;
                    verifica ++;

                }
                if(vetor1[i].cod_cliente < vetor2[verifica].cod_cliente){
                    vetor1[i].cod_cliente = vetor2[verifica].cod_cliente;
                    strcpy(vetor1[i].nome, vetor2[verifica].nome);
                    verifica ++;
                }
                
            }
            

        }  

        //Descobrir como verificar se já foi escrito no arquivo o código do cliente, particionar criando outro arquivo e código pronto;

       /* while(fscanf(arq1, "%d\n", &result) != EOF){
            menor = menor_valor(vetor1, tam_memoria);
            i = 0;
            while(vetor1[i].cod_cliente != menor){
                i ++; 
            }
            if(result == menor){
                vetor1[i].cod_cliente = 100000000000000000;
            }
        } */


        if(tam_vetor3 == tam_memoria){
            int cont = 0;
            while(cont<tam_memoria){
                menor = menor_valor(vetor1, tam_memoria);
                i = 0;
                while(vetor1[i].cod_cliente != menor){
                    i ++; 
                }
                fprintf(arq1, "%d;%s passagem 2\n", vetor1[i].cod_cliente, vetor1[i].nome);
                vetor1[i].cod_cliente = 100000000000000000;
                cont ++;
            }
        }
        
        for(int i = 0; i<tam_vetor3; i++){
            strcpy(vetor1[i].nome, memoria[i].nome);
            vetor1[i].cod_cliente = memoria[i].cod_cliente;
        }
        
        memoria = (TCliente*) malloc(tam_memoria* sizeof(TCliente));
        tam_vetor3 = 0;


        return 0;
    }
    return 0;
}

int main() {
    int tam_memoria;
    scanf("%d", &tam_memoria);
    int num_part = selecao_natural("entrada.txt", tam_memoria);
    for (int i = 1; i < num_part+1; i++) {
        printf("*** %s\n", gera_nome_particao(i));
        imprime_arquivo(gera_nome_particao(i));
    }
}