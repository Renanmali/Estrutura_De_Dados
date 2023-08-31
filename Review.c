#include <stdio.h>

// Programa para revisar como funciona o ponteiro em uma função //
 

void troca(int *px, int *py){
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main (void){
    int a=5, b=7;
    troca(&a, &b);
    printf("%d %d", a, b);
    return 0;
}