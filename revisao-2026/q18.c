#include <stdio.h>

int main(void)
{
    float media = 0;
    int quantidade_P = 0;
    int salarios = 0;
    int salarios_totais = 0;
    int sexo = 0;
    int M = 0;
    int F = 0;
    int i = 0;
    int mulheres2000;

    printf("qual a quantidade de pessoas?\n");
    scanf("%i", &quantidade_P);
    for (i = 0; i < quantidade_P; i++)
    {
        printf("\ndigite o salario de cada pessoa:\n");
        scanf("%i", &salarios);

        printf("\nagora digite para escolher sexo:1 para masculino,2 para feminino.\n");
        scanf("%i", &sexo);
        if (sexo == 1)
        {
            M++;
        }
        else if (sexo == 2)
        {
            F++;
        }
        if (sexo == 2 && salarios == 2000)
        {
            mulheres2000++;
        }
        salarios += salarios_totais;
    }
    media = salarios / quantidade_P;
    printf("\nsalarios totais:\n:%i", salarios);
    printf("\na media dos salarios e:\n%f", media);
    printf("\no numero de mulheres e:\n%i", F);
    printf("\no numero de homens e:\n%i", M);
    printf("\nnumero de mulheres com 2000 reais::\n%i", mulheres2000);
    return 0;
}