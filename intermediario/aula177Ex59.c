// Campo minado
#include "stdio.h"

int linhas;
int colunas;
int bombas;

// cores
#define NEUTRO   "\033[m"
#define BRANCO   "\033[37;3m"
#define VERMELHO "\033[31m"
#define VERDE    "\033[32m"
#define LARANJA  "\033[93m"
#define AZUL     "\033[34m"
#define AMARELO  "\033[33m"
#define ROXO     "\033[35m"
#define PRETO    "\033[30m"

void imprimirValor(int valor, int largura) {
  switch (valor) {
  case -1:
    printf(" %s%*d%s |", BRANCO, largura, valor, NEUTRO);
    break;
  case 0:
    printf(" %s%*d%s |", BRANCO, largura, valor, NEUTRO);
    break;
  case 1:
    printf(" %s%*d%s |", VERDE, largura, valor, NEUTRO);
    break;
  case 2:
    printf(" %s%*d%s |", AZUL, largura, valor, NEUTRO);
    break;
  case 3:
    printf(" %s%*d%s |", AMARELO, largura, valor, NEUTRO);
    break;
  case 4:
    printf(" %s%*d%s |", LARANJA, largura, valor, NEUTRO);
    break;
  case 5:
    printf(" %s%*d%s |", ROXO, largura, valor, NEUTRO);
    break;
  case 6:
    printf(" %s%*d%s |", VERMELHO, largura, valor, NEUTRO);
    break;
  case 7:
    printf(" %s%*d%s |", PRETO, largura, valor, NEUTRO);
    break;
  }
}

void imprimirMatriz(int matriz[linhas][colunas]) {
  // Primeiro, determina a largura necessária para os índices
  int largura = 1; // largura mínima
  int maiorDigito = (linhas > colunas) ? linhas : colunas;
  while (maiorDigito /= 10)
  largura++;

  // Imprime o cabeçalho com os índices das colunas
  printf("%*s", largura + 1, ""); //%*s faz com que imprima a string "" com
                                  //largura+1 espaços em brancha à esquerda
  for (int coluna = 0; coluna < colunas; coluna++) {
    printf(" %*d |", largura,
           coluna); // imprime a coluna com  a largura de cima de espaçamento
  }
  printf("\n");
  // Imprime uma linha separadora
  printf("%*s", largura + 1, "");
  for (int coluna = 0; coluna < colunas; coluna++) {
    for (int i = 0; i < largura + 2; i++)
      printf("-");
    printf("+");
  }
  printf("\n");
  // Imprime as linhas da matriz
  for (int linha = 0; linha < linhas; linha++) {
    printf("%*d |", largura, linha); // Índice da linha
    for (int coluna = 0; coluna < colunas; coluna++) {
      imprimirValor(matriz[linha][coluna], largura); // imprime o valor
    }
    printf("\n");
    // Imprime uma linha separadora entre as linhas da matriz
    printf("%*s", largura + 1, "");
    for (int coluna = 0; coluna < colunas; coluna++) {
      for (int i = 0; i < largura + 2; i++)
        printf("-");
      printf("+");
    }
    printf("\n");
  }
}

void iniciarMatriz(int matriz[linhas][colunas]) {
  for (int linha = 0; linha < linhas; linha++) {
    for (int coluna = 0; coluna < colunas; coluna++) {
      matriz[linha][coluna] = -1;
    }
  }
}

int main(void) {
  linhas = 8, colunas = 8;
  int matriz[linhas][colunas];
  iniciarMatriz(matriz);
  imprimirMatriz(matriz);
}
