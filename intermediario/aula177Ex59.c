// Campo minado
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int linhas;
int colunas;
int bombas;
int escondidos = 0;

// cores
#define NEUTRO   "\033[m"
#define BRANCO   "\033[37;3m"
#define VERMELHO "\033[31m"
#define VERDE    "\033[32m"
#define AMARELO_SATURADO  "\033[93m"
#define AZUL     "\033[34m"
#define AMARELO  "\033[33m"
#define ROXO     "\033[36m"
#define VERMELHO_SATURADO  "\033[91m"
#define BRANCO_FUNDO_VERDE   "\033[37;42m"
//elementos:
#define BOMBA 8
//dificuldade
#define FACIL 1
#define MEDIO 2
#define DIFICIL 3
//lógicos
#define TRUE 1
#define FALSE 0


typedef struct{
  int valor;
  int oculto;
}Valor;

void imprimirValor(Valor elemento, int largura) {
  if(elemento.oculto == FALSE){
    switch (elemento.valor) {
      default:
        printf(" %s%*c%s |", BRANCO, largura, '!', NEUTRO);
      break;
      case 0:
        printf(" %s%*i%s |", BRANCO, largura, elemento.valor, NEUTRO);
        break;
      case 1:
        printf(" %s%*i%s |", VERDE, largura, elemento.valor, NEUTRO);
        break;
      case 2:
        printf(" %s%*i%s |", AZUL, largura, elemento.valor, NEUTRO);
        break;
      case 3:
        printf(" %s%*i%s |", AMARELO, largura, elemento.valor, NEUTRO);
        break;
      case 4:
        printf(" %s%*i%s |", AMARELO_SATURADO, largura, elemento.valor, NEUTRO);
        break;
      case 5:
        printf(" %s%*i%s |", ROXO, largura, elemento.valor, NEUTRO);
        break;
      case 6:
        printf(" %s%*i%s |", VERMELHO, largura, elemento.valor, NEUTRO);
        break;
      case 7:
        printf(" %s%*i%s |", VERMELHO_SATURADO, largura, elemento.valor, NEUTRO);
        break;
      case BOMBA:
        printf(" %s%*c%s |", VERMELHO_SATURADO, largura, '#', NEUTRO);
        break;
    }
  }else {
    printf(" %s%*c%s |", BRANCO_FUNDO_VERDE, largura, '?', NEUTRO);
  }
}

void imprimirMatriz(Valor matriz[linhas][colunas]) {
  // Primeiro, determina a largura necessária para os índices
  int largura = 1; // largura mínima
  int maiorDigito = (linhas > colunas) ? linhas : colunas;
  while (maiorDigito /= 10)
  largura++;

  // Imprime o cabeçalho com os índices das colunas
  printf("%*s", largura + 1, ""); //%*s faz com que imprima a string "" com largura+1 espaços em brancha à esquerda
  for (int coluna = 0; coluna < colunas; coluna++) {
    printf(" %*d |", largura, coluna); // imprime a coluna com  a largura de cima de espaçamento
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
  printf("Bombas: %i\tBlocos escondidos: %i",bombas,escondidos);
}


int sorteio(int dificuldade){
  switch (dificuldade) {
    case FACIL:
      if(rand() % 100 >= 80 && bombas < 10)
        return BOMBA;
      else
        return 0;
      break;
    case MEDIO:
      if(rand() % 100 >= 85 && bombas < 40)
        return BOMBA;
      else
        return 0;
      break;
    case DIFICIL:
      if(rand() % 100 >= 78 && bombas < 99)
        return BOMBA;
      else
        return 0;
      break;
    default:
      return 0;
      break;
  }
}

int valida(Valor matriz[linhas][colunas],int linha,int coluna){
  int resultado = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue;

      int nLinha = linha + i;
      int nColuna = coluna + j;

      if (nLinha >= 0 && nLinha < linhas &&
        nColuna >= 0 && nColuna < colunas) {
        if (matriz[nLinha][nColuna].valor == BOMBA) {
          resultado++;
        }
      }
    }
  }
  return resultado;
}

void iniciarMatriz(Valor matriz[linhas][colunas],int dificuldade) {
  for (int linha = 0; linha < linhas; linha++) {
    for (int coluna = 0; coluna < colunas; coluna++) {
      matriz[linha][coluna].oculto = TRUE;
      matriz[linha][coluna].valor = sorteio(dificuldade);
      if(matriz[linha][coluna].valor == BOMBA)
        bombas++;
      else
        escondidos++;
    }
  }

  for (int linha = 0; linha < linhas; linha++) {
    for (int coluna = 0; coluna < colunas; coluna++) {
      if(matriz[linha][coluna].valor != BOMBA){
        matriz[linha][coluna].valor = valida(matriz, linha, coluna);
      }
    }
  }
}

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != TRUE) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}

void revelaBombas(Valor matriz[linhas][colunas]){
  for(int linha = 0;linha < linhas;linha++){
    for(int coluna = 0;coluna < colunas;coluna++){
      if(matriz[linha][coluna].valor == BOMBA){
        matriz[linha][coluna].oculto = FALSE;
      }
    }
  }
}


void revela(Valor matriz[linhas][colunas], int linha, int coluna){
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas || 
        matriz[linha][coluna].oculto == FALSE) {
        return;
    }
    
    matriz[linha][coluna].oculto = FALSE;
    escondidos--;
    
    if (matriz[linha][coluna].valor == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                revela(matriz, linha + i, coluna + j);
            }
        }
    }
}


int jogada(Valor matriz[linhas][colunas]){
  int linha = lerInteiro("\nEscolha a linha:");
  int coluna = lerInteiro("Escolha a coluna:");
  if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && 
    matriz[linha][coluna].oculto == TRUE) {
    if (matriz[linha][coluna].valor == BOMBA) {
        revelaBombas(matriz);
        return FALSE;
    } else {
        revela(matriz, linha, coluna);
        return TRUE;
    }
} else {
    printf("Posição inválida!\n");
    return TRUE;
  }
}


int main(void) {
  srand(time(NULL));
  linhas = 16, colunas = 16;
  system("clear");
  int dificuldade;
  printf("Bem vindo à o campo minado!\n"
    "Selencione a dificuldade que você deseja jogar!\n"
    "1 - Fácil\n"
    "2 - Médio\n"
    "3 - Difícil\n");
  do{
    dificuldade = lerInteiro("Dificuldade: ");
  }while(dificuldade < 0 && dificuldade);

  switch (dificuldade) {
    case FACIL:
      linhas = 8; colunas = 8;
    break;
    case MEDIO:
      linhas = 16; colunas = 16;
    break;
    case DIFICIL:
      linhas = 16; colunas = 30;
    break;
  }

  Valor matriz[linhas][colunas];
  iniciarMatriz(matriz,dificuldade);
  imprimirMatriz(matriz);
  while(jogada(matriz) != FALSE && escondidos != 0){
    system("clear");
    imprimirMatriz(matriz);
  }
  system("clear");
  if(escondidos == 0){
    printf("\nVocê venceu!\nParabéns!\n");
    revelaBombas(matriz);
  }
  else
    printf("\nVocê pisou em uma bomba!\nVocê perdeu!\n");
  imprimirMatriz(matriz);
}
