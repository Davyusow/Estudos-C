#include "stdbool.h"
#include "stdio.h"
#include <math.h>

int main(void) {

  // Soma
  { // somente para compactar linhas grandes, evite fazer isso em códigos reais,
    // aqui é um cenários de estudos
    printf("## Adição ##\n\n");
    short resultado = 0;
    resultado = 10 + 5; // em uma variável que já existe

    short resultado2 = 10 + 5; // em uma variável nova;

    printf("10 + 5 = %i \n", 10 + 5); // direto no resultado

    printf("10 + 5 = %i \n", resultado);
  }

  // Subtração
  {
    printf("## Subtração ##\n\n");
    short resultado = 10 - 2; // Operação com negativos
    printf("-10 + 10 = %i \n", resultado);

    short valor = -10; // criando variável negativa

    resultado = 10 - valor; // - com - é mais

    printf("10 -(-10) = %i\n", resultado);
  }

  // Multiplicação
  {
    printf("## Subtração ##\n\n");
    int resultado = 18 * 2;
    printf("18 X 2 = %i\n", resultado);

    // invertendo valor
    resultado = resultado * -1;
    printf("Invertido = %i\n", resultado);

    // zerando valor
    resultado = resultado * 0;
    printf("Invertido = %i\n", resultado);
  }

  // Divisão
  {
    printf("## Divisão ##\n\n");
    int resultado = 18 / 2; // sempre será uma divisão inteira com tipo inteiro
    printf("18 / 2 = %i\n", resultado);

    float resultado_f = 7.0 / 2.0;
    printf("7 / 2 = %f\n", resultado_f);

    // resultado = 10 / 0; // nem imprime, erro feioso
    // printf("10 / 0 = %i\n", resultado);
  }

  // Mod
  {
    printf("## Mod ##\n\n");
    int par = 20 % 2; // se for resto 0 é par
    printf("20 mod 2 = %i\n", par);

    int dias = 302;
    int dia = dias % 31; // Calcula o dia do Mês (bem porcamente mas conta)
    printf("%i -> %i \n", dias, dia);
  }

  // Math.h
  {
    printf("## Math.h ##\n\n");
    // potência:
    int quadrado = pow(10, 2); // 10²
    printf("10 ^ 2 = %i\n", quadrado);

    int raiz_quadrada = cbrt(64); // raíz de 64
    printf(" √64 = %i\n", raiz_quadrada);

    int arredonda = round(9.123213); // arredonda para o inteiro mais próximo
    printf("9.123213 arredondado para %i", arredonda);
  }

  // Operadores booleanos

  // Igualdade
  {
    printf("## Igualdade ##\n\n");
    // Lembre de importar o stdbool.h
    bool igual = true == false; // podemos usar diretamente true ou false
    igual = 10 == 20;
    printf("10 == 20 ? %d\n", igual); // 0 é false e 1 é true
    igual = 20 == 20;
    printf("20 == 20 ? %d\n", igual);
  }

  // Diferença
  {
    printf("## Diferença ##\n\n");

    bool igual = true != false;
    igual = 10 != 20;
    printf("10 != 20 ? %d\n", igual);
    igual = 20 == 20;
    printf("20 != 20 ? %d\n", igual);
  }

  // Maior / Menor
  {
    printf("## Maior / Menor ##\n\n");

    bool maior = 10 > 8;
    printf("10 é maior que 8 ? %d\n", maior);

    bool menor = 15 < 38;
    printf("15 é menor que 38 ? %d\n", menor);
  }

  // Maior igual, Menor igual
  {
    printf("## Maior igual, Menor igual ##\n\n");

    bool maior_igual = 10 >= 10;
    printf("10 é maior ou igual a 10 ? %d\n", maior_igual);

    bool menor_igual = 10 <= 14;
    printf("10 é menor ou igual a 14 ? %d\n", menor_igual);
  }

  // Negação
  {
    printf("## Negação ##\n\n");
    bool negacao = !(10 > 20);
    printf("O 10 NÃO é maior que 20? %i\n", negacao);

    negacao = !(20 == 20);
    printf("O 20 NÃO é igual a 20? %i\n", negacao);
  }

  return 0;
}
