#include "stdio.h"

typedef struct {
  int dia, mes, ano;
} Data;

typedef struct {
  Data idade;
  char sexo;
  char nome[100];
} Pessoa;

void imprimir(Pessoa pessoa){
  printf("Nome: %sIdade: %i/%i/%i\nSexo: %c\n",
    pessoa.nome, pessoa.idade.dia, pessoa.idade.mes, pessoa.idade.ano, pessoa.sexo);
}


int main() {
  Pessoa pessoa1;

  printf("Digite seu nome: ");
  fgets(pessoa1.nome, 100, stdin);

  printf("Digite sua data de nascimento (separe com /): ");
  scanf(" %i/%i/%i", &pessoa1.idade.dia, &pessoa1.idade.mes, &pessoa1.idade.ano);

  printf("Digite seu sexo: ");
  scanf(" %c", &pessoa1.sexo);

  imprimir(pessoa1);
  
  return 0;
}