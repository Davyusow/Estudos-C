#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define ALTURA 0
#define IDADE 1

int main(void) {
  srand(time(NULL));
  float aluno[45][2];
  float mediaAltura = 0 ,mediaIdade = 0;
  int totalAlunosAltura = 0, totalAlunosIdade = 0;

  for (int contador = 0; contador < 45; contador++) {
    aluno[contador][ALTURA] = 1.5 + (float)(rand() % 50) / 100; // gera um valor real entre 1.5 e 2.0
    aluno[contador][IDADE] = 18 + rand() % 20; //gera idades entre 18 e 38 anos

    float idadeAtual = aluno[contador][IDADE];
    float alturaAtual = aluno[contador][ALTURA];

    printf("Aluno %d\nAltura (m): %.2f\nIdade: %0.f\n-----------------------\n",contador + 1,alturaAtual,idadeAtual);
    if(alturaAtual <= 1.70){ //média de idade de alunos com menos de 1.70 de altura
        mediaIdade+=aluno[contador][IDADE];
        totalAlunosIdade++;
    }
    if(idadeAtual >=20){ //média de altura de pessoas com mais de 20 anos
        mediaAltura+=aluno[contador][ALTURA];
        totalAlunosAltura++;
    }
  }

  mediaIdade/=totalAlunosIdade;
  mediaAltura/=totalAlunosAltura;

  printf("\nA média de idade dos alunos com menos de 1.70 de altura é: %.2f",mediaIdade);
  printf("\nA média de altura de alunos com mais de 20 anos é: %.2f\n",mediaAltura);

  return 0;
}
