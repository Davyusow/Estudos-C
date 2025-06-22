#include "stdio.h"

typedef struct {
  int dia, mes, ano;
} Data;

typedef struct {
  Data idade;
  char sexo;
  char nome[100];
} Pessoa;

int main() {
  Data data;
  Pessoa pessoa1;

  printf("\nTamanho da memória de Data: %li",sizeof(data));
  printf("\nTamanho da memória de Pessoa: %li\n",sizeof(pessoa1));

  printf("Digite seu nome: ");
  fgets(pessoa1.nome, 100, stdin);

  printf("Digite sua data de nascimento (separe com /): ");
  scanf(" %i/%i/%i", &pessoa1.idade.dia, &pessoa1.idade.mes,
        &pessoa1.idade.ano);

  printf("Digite seu sexo: ");
  scanf(" %c", &pessoa1.sexo);

  printf("Nome: %sIdade: %i/%i/%i\nSexo: %c\n", pessoa1.nome, pessoa1.idade.dia,
         pessoa1.idade.mes, pessoa1.idade.ano, pessoa1.sexo);

  
  return 0;
}