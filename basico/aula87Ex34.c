#include "stdio.h"
#include "stdbool.h"

bool isMulher(char sexo){
    if(sexo == 'F' || sexo == 'f')
        return true;
    else
        return false;
}

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}


float lerSalario(char *mensagem) {
  float salarioLido;
  printf("%s", mensagem);
  while (scanf(" %f", &salarioLido) != 1) {
    while (getchar() != '\n');
    printf(" %s", mensagem);
  }
  return salarioLido;
}

char lerSexo(char *mensagem){
    char sexo ;
    do{
        printf("%s",mensagem);
        scanf(" %c", &sexo);
        if(isMulher(sexo))
            break;
        if(sexo == 'M' || sexo == 'm')
            break;
    }while(true);
    return sexo;
}

int main(void) {
  int totalHabitantes = lerInteiro("Quantos habitantes serão lidos?: ");
  float somaSalario = 0,salario;
  int idade, menorIdade,maiorIdade, mulheresAte2mil = 0;
  char sexo;

  if(totalHabitantes > 0){
    printf("1° - Habitante");
    idade = lerInteiro("\nDigite a idade: ");
    sexo = lerSexo("\nDigite o sexo [M/F]: ");
    salario = lerSalario("\nDigite o salário: R$");

    somaSalario += salario;
    maiorIdade = idade;menorIdade = idade;

    if(isMulher(sexo) && salario <= 2000)
        mulheresAte2mil++;
    for (int contador = 1; contador < totalHabitantes; contador++){
        printf("%d° - Habitante",contador+1);
        idade = lerInteiro("\nDigite a idade: ");
        sexo = lerSexo("\nDigite o sexo [M/F]: ");
        salario = lerSalario("\nDigite o salário: R$");

        somaSalario += salario;
        if(idade < menorIdade)
            menorIdade = idade;
        if(idade > maiorIdade)
            maiorIdade = idade;

        if(isMulher(sexo) && salario <= 2000)
            mulheresAte2mil++;
    }
    printf("\nA média salarial é de R$%.2f",somaSalario/totalHabitantes);
    printf("\nA maior idade registrada foi de %d anos, enquando a menor foi de %d anos",maiorIdade,menorIdade);
    printf("\nE existem %d mulheres que ganham até R$2000.00",mulheresAte2mil);
  }

  printf("\nFinalizando...\n");

    return 0;
}
