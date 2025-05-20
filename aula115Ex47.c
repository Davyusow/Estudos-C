#include "stdio.h"
#include "stdlib.h"

float lerTemperatura(char *mensagem) {
  float valorLido;
  printf(" %s", mensagem);
  while (scanf(" %f", &valorLido) != 1) {
    while (getchar() != '\n');
    printf(" %s", mensagem);
  }
  return valorLido;
}

char* meses(int numero){
    char *valor;
    switch(numero){
        default:
            printf("\nMês indefinido!\n");
            valor = "<indefinido>";
            break;
        case 0:
            valor = "Janeiro";
            break;
        case 1:
            valor = "Fevereiro";
            break;
        case 2:
            valor = "Março";
            break;
        case 3:
            valor = "Abril";
            break;
        case 4:
            valor = "Maio";
            break;
        case 5:
            valor = "Junho";
            break;
        case 6:
            valor = "Julho";
            break;
        case 7:
            valor = "Agosto";
            break;
        case 8:
            valor = "Setembro";
            break;
        case 9:
            valor = "Outubro";
            break;
        case 10:
            valor = "Novembro";
            break;
        case 11:
            valor = "Dezembro";
            break;
    }
    return valor;
}

int main(void){
    float temperaturas[12];
    printf("\tInsira as temperaturas de cada Mês: \n");
    int contador = 0,maior,menor;

    for(contador = 0;contador<12;contador++){
        printf("%2i - %-11s |",contador+1,meses(contador));
        temperaturas[contador] = lerTemperatura("Valor da temperatura: C°");

        if(contador == 0){
            maior = contador;
            menor = contador;
        }else if(temperaturas[maior] < temperaturas[contador])
            maior = contador;
        else if(temperaturas[menor] > temperaturas[contador])
            menor = contador;
    }

    char *maiorTexto = meses(maior);
    char *menorTexto = meses(menor);

    printf("\nA maior temperatura foi a %2.0fC° no mês %s",temperaturas[maior],maiorTexto);
    printf("\nA menor temperatura foi a %2.0fC° no mês %s\n",temperaturas[menor],menorTexto);

    return 0;
}
