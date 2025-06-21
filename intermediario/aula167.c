#include "stdio.h"
#include "string.h"

 typedef struct{
    char nome[100];
    char sexo;
    float peso;
    int idade;
}Aluno; //mais fácil de trabalhar

typedef struct Pessoa{  //precisa chamar com struct
    char nome[100];
    char sexo;
    float peso;
    int idade;
}Pessoa;


int main(void){
    Aluno aluno;
    struct Pessoa pessoa;
    aluno.idade = 20;
    aluno.sexo = 'M';
    //aluno.nome = "Fulano";  não funciona, pois a String é imutável
    strcpy(aluno.nome,"Fulano"); //assim funciona
    printf("Nome: %s\nIdade: %i\nSexo: %c"
        ,aluno.nome,aluno.idade,aluno.sexo);

    return 0;
}
