// Função que incrementa um valor aos números do vetor //

#include <stdio.h>

void incr_vetor(int a, int *v){
    int i;
    for(i=0; i<a; i++){
        v[i]++;
    }
}

int main(void){
    int b[] = {0,1,2,3};
    incr_vetor(4, b);
    printf(" %d %d %d %d ", b[0],b[1],b[2],b[3]);
    return 0;
}