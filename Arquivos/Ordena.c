#include <stdio.h>

void imprime_arquivo(char *nomeArq){
    FILE *arq; //declara ponteiro para arquivo
    //abre arquivo para leitura
    arq = fopen(nomeArq, "r");
    if (arq != NULL){// checa se não deu erro na abertura do arquivo
        char s[10];
        fscanf(arq, "%s", s);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s\n", s);
            fscanf(arq, "%s", s);
        }
        fclose(arq); //fecha arquivo
    }
    else printf("Erro ao abrir arquivo\n");
}

void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge) {
    //TODO: Implementar essa função
    FILE* arq1;
    FILE* arq2;
    FILE* arqmerge;

    arqmerge = fopen(nomeArqMerge, "w");

    arq1 = fopen(nomeArq1, "r");
    arq2 = fopen(nomeArq2, "r");
    if(arq1 != NULL && arq2 != NULL){
        int number1, number2;
        fscanf(arq1, "%d", &number1);
        fscanf(arq2, "%d", &number2);
        while (!feof(arq1) && !feof(arq2)) {//testa se chegou ao final do arquivo
            if(number1 > number2){
                fprintf(arqmerge, "%d\n", number2);    
                fscanf(arq2, "%d", &number2);
            }
            else if(number2 > number1){
                fprintf(arqmerge, "%d\n", number1);
                fscanf(arq1, "%d", &number1);
            }
            else{
                fprintf(arqmerge, "%d\n", number1);
                fscanf(arq1, "%d", &number1);
                fscanf(arq2, "%d", &number2);
            }
        }
        if(feof(arq1) && !feof(arq2)){
            while(!feof(arq2)){
                if(number1 > number2){
                    fprintf(arqmerge, "%d\n", number2);
                    fscanf(arq2, "%d", &number2);
                }
                else if(number2 > number1){
                    fprintf(arqmerge, "%d\n", number1);
                    while(!feof(arq2)){
                        fprintf(arqmerge, "%d\n", number2);
                        fscanf(arq2, "%d", &number2);
                    }
                    fprintf(arqmerge, "%d\n", number2);
                }
                else{
                    fprintf(arqmerge, "%d\n", number2);
                    while(!feof(arq2)){
                        fprintf(arqmerge, "%d\n", number2);
                        fscanf(arq2, "%d", &number2);
                    }
                    fprintf(arqmerge,"%d\n", number2);
                }
            }
        }
        else if(feof(arq2) && !feof(arq1)){
            while(!feof(arq1)){
                if(number2 > number1){
                    fprintf(arqmerge, "%d\n", number1);
                    fscanf(arq2, "%d", &number1);
                }
                else if(number1 > number2){
                    fprintf(arqmerge, "%d\n", number2);
                    while(!feof(arq1)){
                        fprintf(arqmerge, "%d\n", number1);
                        fscanf(arq2, "%d", &number1);
                    }
                    fprintf(arqmerge,"%d \n", number1);
                }
                else{
                    fprintf(arqmerge, "%d\n", number1);
                    while(!feof(arq1)){
                        fprintf(arqmerge, "%d\n", number1);
                        fscanf(arq2, "%d", &number1);
                    }
                    fprintf(arqmerge,"%d\n", number1);
                }
            }
        }
        else{
            if(number1 > number2){
                fprintf(arqmerge, "%d\n", number2);
                fprintf(arqmerge, "%d\n", number1);
            }
            else if(number1 < number2){
                fprintf(arqmerge, "%d\n", number1);
                fprintf(arqmerge, "%d\n", number2);
            }
            else{
                fprintf(arqmerge, "%d\n", number2);
            }
        }
        fclose(arq1);
        fclose(arq2);
        fclose(arqmerge);
    }
    else printf("Erro!");
}

int main() {
    merge("numeros1.txt", "numeros2.txt", "merge.txt");
    imprime_arquivo("merge.txt");
}