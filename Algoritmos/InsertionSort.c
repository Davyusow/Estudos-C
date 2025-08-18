#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//constantes, considerando que os vetores são estáticos
#define TAM 10
#define LIMITE 21

void imprimeVetor(int vetor[TAM], int tamanho) {    //função utilitária para impressão do vetor
  printf("[ ");
  for (int i = 0; i < tamanho; i++) {
    printf("%2i ", vetor[i]);
  }
  printf("]\n");
}

void criaVetor(int vetor[TAM]) {    //função utilitária para criar vetores com valores aleatórios
  srand(time(NULL));
  for (int y = 0; y < TAM; y++)
    vetor[y] = rand() % LIMITE;
}

/**
* @brief Aplica o algoritmo de ordenação Insertion Sort a um vetor
* 
* Esta função considera que o vetor é estático, ou seja, seu tamanho é constante
* E que são considerados apenas valores inteiros (-2³¹...2³¹-1)
* ou inferiores, tais como short e char.
*
* @param vetor É o vetor à ser ordenado
* @param tamanho é o tamanho do vetor
* @return void, O vetor é ordenado in-place.
*
*/
void InsertionSort(int vetor[TAM], int tamanho) {
  int contador, revisador, chave;   //Variáveis de controle da ordenação: contador, índice de revisão e chave temporária
  for (contador = 1; contador < tamanho; contador++) {  //para o segundo elemento do vetor até o último
    chave = vetor[contador];    //a chave sera o elemento atual comparado
    revisador = contador - 1;   //o revisador é o índice anterior da chave
    imprimeVetor(vetor, tamanho);
    while (revisador >= 0 && vetor[revisador] > chave) {    //enquanto o revisador estiver no vetor e for maior que a chave
    //se a segunda verificação for falsa, isso quer dizer que o vetor esta ordenado na esquerda e ele sairá do loop
      vetor[revisador + 1] = vetor[revisador]; // Desloca o elemento maior para a direita para abrir espaço para a chave
      revisador--; //continua indo em direção ao ínício do vetor
    }
    vetor[revisador + 1] = chave; //insere a chave na posição ordenada
  }
}

int main(void) {

  int vetor[TAM];
  printf("Antes do insertionSort: \n");
  criaVetor(vetor);
  imprimeVetor(vetor, TAM);
  printf("Após do insertionSort: \n");
  InsertionSort(vetor, TAM);
  imprimeVetor(vetor, TAM);

  return 0;
}