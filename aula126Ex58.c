#include "stdio.h"
#include "wchar.h"  //para usar caracteres unicode
#include "stdlib.h"
#include "time.h"
#include "locale.h"
#include <wchar.h>

#define TAM 9
#define LINHA 3
#define COLUNA 3

//constantes das opções do menu
#define UMJOGADOR 1
#define SAIR 2

//constantes da partida
#define JOGANDO -1
#define EMPATE 0
#define JOGADOR1 1
#define BOT 2

int lerInteiro(char *mensagem) {
  int valorLido;
  wprintf(L" %s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    while (getchar() != '\n');
    wprintf(L" %s", mensagem);
  }
  return valorLido;
}

void resetaJogo(wchar_t matriz[LINHA][COLUNA]) {
  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      matriz[y][x] = L'❑';
}

void imprimeJogo(wchar_t matriz[LINHA][COLUNA]) {
  for (int y = 0; y < LINHA; y++) {
    wprintf(L"\t\t");
    for (int x = 0; x < COLUNA; x++) {
        wprintf(L"%lc ",matriz[y][x]);
    }
    wprintf(L"\n");
  }
  wprintf(L"\n");
}


int avaliaJogadaBot(wchar_t jogador,wchar_t bot,wchar_t matriz[LINHA][COLUNA]){
    int resultado = JOGANDO;
    for (int y = 0; y < LINHA; y++) { //avalia jogadas nas linhas
        if(matriz[y][0] == jogador && matriz[y][1] == jogador && matriz[y][2] == jogador)
            return JOGADOR1;
        if(matriz[y][0] == bot && matriz[y][1] == bot && matriz[y][2] == bot)
            return BOT;
    }

    for (int x = 0; x < COLUNA; x++) { //avalia jogadas nas colunas
        if(matriz[0][x] == jogador && matriz[1][x] == jogador && matriz[2][x] == jogador)
            return JOGADOR1;
        if(matriz[0][x] == bot && matriz[1][x] == bot && matriz[2][x] == bot)
            return BOT;
    }

//avalia diagonal principal  
int diagonalJogador = 0,diagonalBot = 0;
  for(int y = 0;y<LINHA;y++){
    if(matriz[y][y] == jogador){
        diagonalJogador++;
    }else if(matriz[y][y] == bot){
        diagonalBot++;
    }
  }
  
  if(diagonalJogador == 3) return JOGADOR1;
  else if (diagonalBot == 3) return BOT;

  diagonalJogador = 0,diagonalBot = 0;

  //avalia diagonal secundária
  for(int y = 0;y<LINHA;y++){
    if(matriz[y][LINHA - 1 - y] == jogador)
        diagonalJogador++;
    if(matriz[y][LINHA - 1 - y] == bot)
        diagonalBot++;
  }
  if(diagonalJogador == 3) return JOGADOR1;
  else if (diagonalBot == 3) return BOT;

  return JOGANDO;
}


int jogo(wchar_t matriz[LINHA][COLUNA]){
    int resultado = -1,vez = JOGADOR1,jogadas = 0;
    srand(time(NULL));
    wchar_t jogador, bot;
    int simbolo = lerInteiro("\nDigite 1 para jogar com  \'X\'\n"
        "2 para jogar com \'O\'\nEscolha: ");
    if(simbolo == 1){
        jogador = L'X'; bot = L'O';
    }
    else{
        jogador = L'O'; bot = L'X';
    }
    
    do{
        int tempValidade = 0;
        wprintf(L"\n");
        imprimeJogo(matriz);
        if(vez == JOGADOR1){
            do{
                int tempJogada = lerInteiro("Deseja jogar em qual bloco?[1 - 9]: ")-1;
                int cont = 0;
                for (int y = 0; y < LINHA; y++) {
                    for (int x = 0; x < COLUNA; x++) {
                        if(matriz[y][x] == L'❑' && cont == tempJogada){
                            matriz[y][x] = jogador;
                            tempValidade = 1;
                            break;
                        }
                        cont++;
                    }
                    if(tempValidade == 1)
                        break;
                }
                if(tempValidade == 0)
                    wprintf(L"Opção inválida!\n");
            }while(tempValidade == 0);
            jogadas++;
            vez = BOT;
        }else if (vez == BOT) {
            int jogadaValida = 0;
            while (!jogadaValida) {
                int tempJogada = rand() % 9; // 0-8
                int cont = 0;
                for (int y = 0; y < LINHA; y++) {
                    for (int x = 0; x < COLUNA; x++) {
                        if (cont == tempJogada && matriz[y][x] == L'❑') {
                            matriz[y][x] = bot;
                            jogadaValida = 1;
                            break;
                        }
                        cont++;
                    }
                    if (jogadaValida) break;
                }
            }
            jogadas++;
            vez = JOGADOR1;
        }   
        resultado = avaliaJogadaBot(jogador,  bot, matriz);
        if(jogadas >= 9 && resultado == JOGANDO ){
            resultado = EMPATE;
        }
    }while(resultado == JOGANDO);
    return resultado;
}

int main(void) {
  setlocale(LC_ALL,"");
  wchar_t matriz[LINHA][COLUNA];
  
  int opcao = 0,rodadas;
  int resultado = 0;
  system("clear");
  do{
    wprintf(L"\nBem vindo ao Jogo da velha!\n"
        "\nPressione a opcação que deseja:\n"
        "⟶ 1 jogar uma partida com a maquina\n"
        "⟶ 2 sair\n");
    opcao = lerInteiro("opção: ");

    switch (opcao) {
        default:
            wprintf(L"valor inválido!");
            break;
        case UMJOGADOR:
            system("clear");
            resetaJogo(matriz);
            resultado = jogo(matriz);
            switch (resultado) {
                case JOGADOR1:
                    wprintf(L"\nO jogador Venceu!\n");
                    break;
                case BOT:
                    wprintf(L"\nA máquina venceu!\n");
                    break;
                case EMPATE:
                    wprintf(L"\nEmpate!\n");
                    break;
                default:
                    wprintf(L"\nDebug: %i",resultado);
                    break;
            }
            imprimeJogo(matriz);
            break;
        case SAIR:
            wprintf(L"\nAté logo!");
            break;
    }
  }while(opcao != 2 );

  return 0;
}
