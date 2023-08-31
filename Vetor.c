#include <stdio.h>

// Criando um programa para calcular a média de 10 números //

float media(int a, float *v){
    float b = 0.0;
    for(int i = 0; i<a; i++){
        b += v[i];
    }
    return b/a;
}

int main(void){
    float v[10];
    float med = 0.0;
    printf("Digite os números: \n" );
    for(int i=0; i<10; i++){
        scanf("%f", &v[i]);
        printf("%f \n", v[i]);
    }
    
    med = media(10, v);
    printf("%.2f", med);
    return 0;
}