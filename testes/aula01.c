#include "stdbool.h"
#include "stdio.h"

#define PI 3.14



typedef struct Bateria{
    float bateria;
    char nome;
    char Marca;
    int valor;
}Bateria;

void recarregar(Bateria *b1){
    for(;b1->bateria<100;b1->bateria++ )
        printf("\nPorcentagem: %f",b1->bateria);
}

int main(void) {

  float var2 = 2.2;                  // 32 bits //4milhões
  double var5 = 2.2;                 // 64 bits
  char texto[] = {"Textos bonitos"}; // 128 bits
  bool var3 = true;                  // 1 bit
  unsigned long long var4 = 255;     // 16 bits, 32 mil, - +
  signed int num1 = -2;
  char letra[] = {"á"};

  // printf("%s",letra); //%s unicode

  int var = 0; // 32 bits
  if (false) {
    printf("\nFuncionou!\n");
  } else if (var == 1) {
    printf("\nNão funcionou\n");
  } else {
    printf("\nFim do código\n");
  }

  printf("\n");

  int num2 = 1;
  switch (num2) {
  case 1:
    printf("igual a 1");
    break;
  case 2:
    printf("igual a 2");
    break;
  case 3:
    printf("igual a 3");
    break;
  case 4:
    printf("igual a 4");
    break;
  case 5:
    printf("igual a 5");
    break;
  default:
    printf("Nenhum deles");
    break;
  }
  printf("\n");

  int valor1 = 1, valor2 = 1;

  for (int i = 1; i < 10; i++) {
    printf("%i X %i = %i\n", i, i, i * i); //valor 1 = 10
  }
  // apaga i

  printf("%i\n",valor1);
  valor1 = 9;

  while (valor1 * valor1 % 2 == 0) {
    printf("%i X %i = %i\n", valor1, valor1, valor1 * valor1);
    valor1++;
  }

  valor1 = 9;

  do{
    printf("%i X %i = %i\n", valor1, valor1, valor1 * valor1);
    valor1++;
  }while (valor1 * valor1 % 2 == 0);

  printf("\nÁrea de um círculo de raio 2: %.2f",PI*(2*2));

  Bateria duracell;

  duracell.bateria = 100;
  duracell.nome = 'a' ;
  duracell.Marca = 'd';
  duracell.valor = 20.00;

  duracell.bateria = 50;
  recarregar(&duracell);

  printf("\nEscreva seu nome: ");
  char nome[200];
  scanf("%s",nome[0]);

  printf("Olá %s",nome);

  return 0;
}
