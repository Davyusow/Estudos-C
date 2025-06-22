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
  printf("Nome: %sIdade: %i/%i/%i\nSexo: %c\n\n",
    pessoa.nome, pessoa.idade.dia, pessoa.idade.mes, pessoa.idade.ano, pessoa.sexo);
}

Pessoa lerPessoa(){
  Pessoa pessoa;
  printf("\n\nDigite seu nome: ");
  fgets(pessoa.nome, 100, stdin);

  printf("Digite sua data de nascimento (separe com /): ");
  scanf(" %i/%i/%i", &pessoa.idade.dia, &pessoa.idade.mes, &pessoa.idade.ano);

  printf("Digite seu sexo: ");
  scanf(" %c", &pessoa.sexo);
  getchar();
  return pessoa;
}

int main() {
  Pessoa pessoas[3];
  for(int i = 0;i < 3;i++)
    pessoas[i] = lerPessoa();
  for(int i = 0;i < 3;i++)
    imprimir(pessoas[i]);


  return 0;
}