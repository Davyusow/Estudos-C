#include "stdio.h"
#include "wchar.h"
#include "locale.h"
#include <wchar.h>

#define GANHOU 1
#define JOGANDO 0
#define TRUE 1
#define FALSE 0
#define LINHAS 3
#define COLUNAS 3

wchar_t jogo[LINHAS][COLUNAS];

void iniciarMatriz(){
    for(int i = 0;i < LINHAS;i++){
        for(int j = 0;j < COLUNAS;j++){
            jogo[i][j] = L'❑';
        }
    }
}

void imprimir(){
    wprintf(L"\n\t0  1  2\n");
    for(int linha = 0;linha < LINHAS;linha++){
        wprintf(L"\t");
        for(int coluna = 0;coluna < COLUNAS;coluna++){
            wprintf(L"%lc",jogo[linha][coluna]);
            if(coluna < 2)
                wprintf(L" |");
        }
        wprintf(L"  %i",linha);
        wprintf(L"\n");
        if(linha < 2)
            wprintf(L"\t--------\n");
    }
}

int ganhouPorLinha(int linha,wchar_t jogador){
    if(jogo[linha][0] == jogador
        && jogo[linha][1] == jogador
        && jogo[linha][2] == jogador ){
            return GANHOU;
        }
    else
        return JOGANDO;
}

int ganhouPorLinhas(wchar_t jogador){
    for(int linha = 0;linha < LINHAS;linha++){
        if(ganhouPorLinha(linha,jogador) == GANHOU)
            return GANHOU;
    }
    return JOGANDO;
}

int ganhouPorColuna(int coluna,wchar_t jogador){
    if(jogo[0][coluna] == jogador
        && jogo[1][coluna] == jogador
        && jogo[2][coluna] == jogador ){
            return GANHOU;
        }
    else
        return JOGANDO;
}

int ganhouPorColunas(wchar_t jogador){
    for(int coluna = 0;coluna < LINHAS;coluna++){
        if(ganhouPorColuna(coluna,jogador) == GANHOU)
            return GANHOU;
    }
    return JOGANDO;
}

int ganhouPorDiagonais(wchar_t jogador){
    if(jogo[0][0] == jogador
        && jogo[1][1] == jogador
        && jogo[2][2] == jogador){
            return GANHOU;
        }
    if(jogo[0][2] == jogador
        && jogo[1][1] == jogador
        && jogo[2][0] == jogador){
            return GANHOU;
        }
    return JOGANDO;
}

int jogadaValida(int linha,int coluna){
    if(linha >=0 && linha < LINHAS
        && coluna >=0 && coluna < COLUNAS
        && jogo[linha][coluna] == L'❑'){
            return TRUE;
        }
    else{
        wprintf(L"\nCoordenadas inválidas!\n");
        return FALSE;
    }
}

int lerInteiro(char *mensagem) {
  int valorLido;
  wprintf(L"%s", mensagem);
  while (scanf(" %d", &valorLido) != TRUE) {
    while (getchar() != '\n');
    wprintf(L"%s", mensagem);
  }
  return valorLido;
}

int posicoesVazias(){
int posicoes = 0;
    for(int i = 0;i < LINHAS;i++){
        for(int j = 0;j < COLUNAS;j++){
            if(jogo[i][j] == L'❑')
                posicoes++;
        }
    }
    return posicoes;
}

void lerCoordenadas(wchar_t jogador){
    int linha,coluna;
    do{
        linha = lerInteiro("Digite a linha que deseja jogar:");
        coluna = lerInteiro("Digite a coluna que deseja jogar");
    }while(jogadaValida(linha, coluna) != TRUE);
    jogo[linha][coluna] = jogador;
}



void jogar(){
    int vez = 1;
    iniciarMatriz();
    int vitoriaX = 0,vitoriaO = 0;
    wchar_t jogador1 = L'X',jogador2 = L'O';
    do{
        imprimir();
        if(vez == 1){
            lerCoordenadas(jogador1);
            vitoriaX = ganhouPorLinhas(jogador1)
            || ganhouPorColunas(jogador1)
            || ganhouPorDiagonais(jogador1);
            vez = 2;
        }
        else{
            lerCoordenadas(jogador2);
            vitoriaO = ganhouPorLinhas(jogador2)
            || ganhouPorColunas(jogador2)
            || ganhouPorDiagonais(jogador2);
            vez = 1;
        }
    }while((vitoriaO == 0 && vitoriaX == 0) && posicoesVazias() > 0);

    if(vitoriaX > 0)
        wprintf(L"\nVitória do jogador 1! Parabéns!!\n");
    else if(vitoriaO > 0){
        wprintf(L"\nVitória do jogador 2! Parabéns!!\n");
    }else{
        wprintf(L"\nEmpate!!\n");
    }
}

int main(void){
    setlocale(LC_ALL,""); //define para pt_BR ou o idioma do Sistema operacional
    int opcao;
    do{
        jogar();
        opcao = lerInteiro("\nDigite 1 para jogar novamente!");
    }while(opcao == TRUE);

    return 0;
}
