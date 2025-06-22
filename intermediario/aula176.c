#include "stdio.h"



typedef struct {
  char tipo[100];
  char marca[50];
  char modelo[25];
  char eficiencieE;
  char descricao[500];
  int quantidade;
  int codigo;
} Eletronico;

void imprimir(Eletronico eletronico){
  printf("\nTipo: %s\n",eletronico.tipo);  
  printf("Marca: %s\n",eletronico.marca);  
  printf("Modelo: %s\n",eletronico.modelo);
  printf("Eficiência energética: %c\n",eletronico.eficiencieE);
  printf("Descrição: %s\n",eletronico.descricao);
  printf("quantidade: %i\n",eletronico.quantidade);
  printf("Código: %i\n",eletronico.codigo);  
}

Eletronico lerEletronico(){
  Eletronico eletronico;
  printf("Digite o Tipo do eletrônico: ");
  fgets(eletronico.tipo,100,stdin);

  printf("Digite a marca do eletrônico: ");
  fgets(eletronico.marca,50,stdin);

  printf("Digite o modelo do eletrônico: ");
  fgets(eletronico.modelo,25,stdin);

  printf("Digite a eficiência energética do eletrônico: ");
  scanf(" %c",&eletronico.eficiencieE);
  getchar();
  printf("Digite a descrição do eletrônico: ");
  fgets(eletronico.descricao,500,stdin);

  printf("Digite a quantidade do estoque: ");
  scanf(" %i",&eletronico.quantidade);

  printf("Digite o código do estoque: ");
  scanf(" %i",&eletronico.codigo);
  getchar();
  return eletronico; 
}

int main() {
  Eletronico ele = lerEletronico();
  imprimir(ele);
  
  return 0;
}