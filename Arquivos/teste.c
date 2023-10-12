#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAM_NOME 100
typedef struct Departamento {
    int cod_dept;
    int sala;
    char nome[TAM_NOME];
} TDepartamento;

typedef struct Funcionario {
    int cod_func;
    int cod_dept;
    char nome[TAM_NOME];
} TFuncionario;

TFuncionario *le_funcionario(FILE *in)
{
    TFuncionario *func = (TFuncionario *) malloc(sizeof(TFuncionario));
    char linha[150];
    if (fgets (linha, 150, in) == NULL ) {
        free(func);
        return NULL;
    }

    char delimitador[] = ";";
    char *ptr;
    int cod;

    //quebra a linha
    ptr = strtok(linha, delimitador);
    cod = atoi(ptr);
    func->cod_func = cod;
    ptr = strtok(NULL, delimitador);
    cod = atoi(ptr);
    func->cod_dept = cod;
    ptr = strtok(NULL, delimitador);
    strcpy(func->nome, ptr);

    return func;
}
void leftOuterJoin(char *nome_arq_dept, char *nome_arq_funcionarios) {
    //TODO: Implementar essa função
    FILE* arq_dept = fopen(nome_arq_dept, "rb");
    FILE* arq_funcionarios = fopen(nome_arq_funcionarios, "rb");
    
    if(arq_dept != NULL && arq_funcionarios != NULL){
        while(arq_dept != NULL){
            TDepartamento* dept = le
        }

    }
}

int main(){
    leftOuterJoin("departamentos.txt", "funcionarios.txt");
}