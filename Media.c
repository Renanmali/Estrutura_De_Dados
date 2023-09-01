// Programa que calcula a média de n números reais //
// Após o cálculo libera a memória //

#include <stdio.h>
#include <stdlib.h>

float media(int a, float *v){
    float b = 0.0;
    for(int i = 0; i<a; i++){
        b += v[i];
    }
    return b/a;
}

int main(void){
    int n, i;
    float *v, med;

    printf("Digite a quantidade de números que deseja inserir para fazer a média: \n");
    scanf("%d", &n);

    // inicializando o vetor //

    v = (float*) malloc(n * sizeof(float));

    // Printando mensagem de erro caso o vetor não seja inicializado //

    if(v == NULL){
        printf("ERRO!! Não existe um vetor. \n");
        return 1;
    }

    // Colocando os valores dentro do vetor //
    printf("Digite os números para o cálculo da média \n");
    for(i=0; i<n; i++){
        scanf("%f", &v[i]);
    }

    med = media(n, v);
    printf("A média é igual a: %.2f \n", med);
    
    //Liberando a memória //
    free(v);
    
    return 0;

}