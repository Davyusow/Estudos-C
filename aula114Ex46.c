#include "stdio.h"
#include "stdlib.h"

int lerInteiro(char *mensagem) {
  int valorLido;
  printf(" %s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    while (getchar() != '\n');
    printf(" %s", mensagem);
  }
  return valorLido;
}

float lerPreco(char *mensagem) {
  float valorLido;
  printf(" %s", mensagem);
  while (scanf(" %f", &valorLido) != 1) {
    while (getchar() != '\n');
    printf(" %s", mensagem);
  }
  return valorLido;
}

#define MAX 10
#define MIN 0
#define TAM_NOME 100

int main(void) {
  float precos[MAX];
  char nomes[MAX][TAM_NOME];
  int vendas[MAX],maioresObjetosVendidos = 0,opcao = 0;
  float total = 0,comissao,salario = 1100;

  for(int contador = 0;contador < MAX;contador++){ //cadastra os objetos
      printf("\nInsira aqui o nome do %i° objeto: ",contador+1);
      scanf(" %s",nomes[contador]);
      precos[contador] = lerPreco("Insira aqui o preço do objeto: R$");
      vendas[contador] = 0;
  }


  do {  //Fase de vendas
    system("clear");

    if(opcao < MIN || opcao > MAX)
        printf("Digite um valor válido\n");

    printf("Objetos: \n");
    for(int contador = 0;contador<MAX;contador++)
        printf("%2i° %-8s : preco R$%.2f\n",contador+1,nomes[contador],precos[contador]);
    printf("0 para sair\n");
    opcao = lerInteiro("Opção: ");

    if (opcao >= MIN+1 && opcao <= MAX)
        vendas[opcao-1]++;
  } while (opcao != 0);
  system("clear");

  for(int contador = 0;contador<MAX;contador++){ //imprime o resultado das vendas
      printf("%2i° %-10s : vendido(s) %i unidade(s), valor unitário: R$%.2f, total: R$%.2f\n"
        ,contador+1,nomes[contador],vendas[contador],precos[contador],vendas[contador]*precos[contador]);

      total+=vendas[contador]*precos[contador];
      if(vendas[contador]>maioresObjetosVendidos)
        maioresObjetosVendidos = vendas[contador];
  }

  printf("\nObjeto(s) mais vendido(s): \n"); //estátisticas dos objetos mais vendidos
  for(int contador = 0;contador<MAX;contador++){
    if(vendas[contador]==maioresObjetosVendidos)
        printf("%s com %i unidade(s), custando R$%.2f, na posição %i do vetor\n"
            ,nomes[contador],maioresObjetosVendidos,precos[contador],contador);
  }

  //Cálulo do salário do funcionário
  comissao = total*0.05;
  printf("\nO total vendido foi de R$%.2f, o funcionário receberá uma comissão de R$%.2f(5%% das vendas)",total,comissao);
  printf("\nO salário a ser pago para o funcionário será de R$%.2f\n",salario+comissao);

  return 0;
}
