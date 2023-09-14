#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
}TAB;

TAB* copia (TAB *a){
    TAB* copia = NULL; TAB* original = a;
    while(original != NULL){
        copia = original;
    }

}