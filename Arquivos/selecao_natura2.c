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


int menorNum(TVet* vet ,int tam_memoria){
	int indice = 0;
	int menor_num = INT_MAX;
	for(int i = 0; i < tam_memoria; i++){
		if(vet[i].cli && vet[i].cli->cod_cliente < menor_num){
			menor_num = vet[i].cli->cod_cliente;
			indice = i;
		}
	}
	return indice;
}

void armazenaVetor(TVet *vet, char *particao, int tam_memoria){
	while(1){//colocando todos os registros que sobraram do vetor na particao
		int menorNum = INT_MAX;
		int indice = 0;
		for(int i = 0; i < tam_memoria;i++){
			if(vet[i].cli && vet[i].cli->cod_cliente < menorNum){
				menorNum = vet[i].cli->cod_cliente;
				indice = i;
			}
		}
		if(menorNum == INT_MAX) break;
		salva_cliente(vet[indice].cli,particao);
		free(vet[indice].cli);
		vet[indice].cli = NULL;
	}
}

int selecao_natural(char *nome_arquivo_entrada, int tam_memoria) { //funcao principal
    int num_particao = 1;
    int num_registrosReservatorio = 0;
	FILE * entrada = fopen(nome_arquivo_entrada,"r");
    FILE * reservatorio = fopen("reservatorio.txt","w+");
    FILE * particao = fopen(gera_nome_particao(num_particao),"w");
    if(!entrada || !reservatorio || !particao) exit(1);
    TVet *vet = (TVet*)malloc(tam_memoria*sizeof(TVet));
    for(int i= 0; i < tam_memoria;i++){ // inicializa memoria
    	vet[i].cli = NULL;
	}
    for(int i = 0; i < tam_memoria && !feof(entrada);i++){ //enchendo memoria
    	vet[i].cli = le_cliente(entrada);
	}
		int indice_menorNum = INT_MAX;
		TCliente *nova_leitura = NULL;
		while(!feof(entrada)){
			if(num_registrosReservatorio == tam_memoria){// se reservatorio ficou cheio
				armazenaVetor(vet,particao,tam_memoria);
				fclose(particao);
				num_particao++;
				particao = fopen(gera_nome_particao(num_particao),"w"); //gerando nova particao
				rewind(reservatorio);
				for(int i = 0; i < tam_memoria && !feof(reservatorio);i++){ // lendo todos os clientes do reservatorio para a memoria
					vet[i].cli = le_cliente(reservatorio);
				}
				fclose(reservatorio);
				reservatorio = fopen("reservatorio.txt","w+");
				num_registrosReservatorio = 0;
			}
			indice_menorNum = menorNum(vet, tam_memoria);
			salva_cliente(vet[indice_menorNum].cli,particao);
			nova_leitura = le_cliente(entrada);
			if(!nova_leitura){ //se minha nova leitura leu o final do arquivo
				free(vet[indice_menorNum].cli);
				vet[indice_menorNum].cli = NULL;
			}else if (nova_leitura->cod_cliente > vet[indice_menorNum].cli->cod_cliente){ //se o codigo da nova leitura eh maior doq
				free(vet[indice_menorNum].cli);
				vet[indice_menorNum].cli = nova_leitura;
			}else{
				salva_cliente(nova_leitura,reservatorio);
				num_registrosReservatorio++;
                free(nova_leitura);
				while(1){
					if(num_registrosReservatorio == tam_memoria){
                      free(vet[indice_menorNum].cli);
                      vet[indice_menorNum].cli = NULL;
                      break;
					}
					nova_leitura = le_cliente(entrada);
					if(!nova_leitura || nova_leitura->cod_cliente > vet[indice_menorNum].cli->cod_cliente){
						free(vet[indice_menorNum].cli);
						vet[indice_menorNum].cli = nova_leitura;
						break;
					}
					salva_cliente(nova_leitura,reservatorio);
					num_registrosReservatorio++;
					free(nova_leitura);
				}
			}
		}
		armazenaVetor(vet,particao,tam_memoria);
		rewind(reservatorio);
		TCliente *nc = le_cliente(reservatorio);
		if(nc){
			fclose(particao);
			num_particao++;
			particao = fopen(gera_nome_particao(num_particao),"w");
			vet[0].cli = nc;
			for(int i = 1; !feof(reservatorio);i++){ // lendo todos os clientes do reservatorio para a memoria
				vet[i].cli = le_cliente(reservatorio);
			}
		}
		armazenaVetor(vet,particao,tam_memoria);
	fclose(entrada);
	fclose(reservatorio);
	fclose(particao);
	for(int i = 0; i < tam_memoria;i++){
		if(vet[i].cli){
            free(vet[i].cli);
		}
	}
	free(vet);
	return num_particao;
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