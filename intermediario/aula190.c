#include "stdio.h"

typedef struct{
  int dia, mes, ano;
}Data;


int main(void){
  Data data;
  Data *p;
  p = &data;
  data.dia = 25;
  data.mes = 6;
  data.ano = 2025;

  printf("%i/%i/%i\n",data.dia,data.mes,data.ano);
  printf("%i/%i/%i\n",p->dia,p->mes,p->ano);
  //para pegar o valor de um ponteiro de struct, em vez de '.' é usado '->'
  //essa é uma sintaxe particular de C para deixar implicito que a manipulação é
  //feita com um ponteiro e não a variável.

  return 0;
}