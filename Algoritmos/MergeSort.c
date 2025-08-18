#include "stdio.h"
#include "stdlib.h"

// contantes lógicos
#define TRUE 1
#define FALSE 0
#define NAO_ENCONTRADO -1
#define NIL -1

// constantes do menu
#define VER 1
#define INSERIR 2
#define BUSCAR 3
#define EXCLUIR 4
#define ORDENAR 5
#define SAIR 0

typedef struct Vetor {
  int *dados;
  int ultimo;
  int tamanho;
} Vetor;

void imprimeVetor(Vetor vetor) {
  printf("[ ");
  for (int i = 0; i < vetor.ultimo; i++) {
    printf("%i ", vetor.dados[i]);
  }
  printf("]\n");
}

Vetor atribui(Vetor *pai, int inicio, int fim) {
  Vetor filho;
  filho.tamanho = fim - inicio;
  filho.dados = (int *)malloc(filho.tamanho * sizeof(int));
  filho.ultimo = filho.tamanho;

  if (filho.dados == NULL) {
    filho.tamanho = 0;
    filho.ultimo = 0;
    return filho;
  }

  for (int i = 0; i < filho.tamanho; i++) {
    filho.dados[i] = pai->dados[inicio + i];
  }

  return filho;
}

void merge(Vetor *vetor, int inicio, int meio, int fim) {
  Vetor esquerda = atribui(vetor, inicio, meio);
  Vetor direita = atribui(vetor, meio, fim);
  int L = 0, R = 0;

  if (esquerda.dados == NULL || direita.dados == NULL) {
    if (esquerda.dados != NULL)
      free(esquerda.dados);
    if (direita.dados != NULL)
      free(direita.dados);
    return;
  }

  printf("Merge: [");
  for (int i = 0; i < esquerda.tamanho; i++)
    printf(" %d", esquerda.dados[i]);
  printf(" ] + [");
  for (int i = 0; i < direita.tamanho; i++)
    printf(" %d", direita.dados[i]);
  printf(" ]\n");

  for (int contador = inicio; contador < fim; contador++) {
    if (L >= esquerda.tamanho)
      vetor->dados[contador] = direita.dados[R++];
    else if (R >= direita.tamanho)
      vetor->dados[contador] = esquerda.dados[L++];
    else if (esquerda.dados[L] < direita.dados[R])
      vetor->dados[contador] = esquerda.dados[L++];
    else
      vetor->dados[contador] = direita.dados[R++];
  }

  free(esquerda.dados);
  free(direita.dados);
}

void mergeSort(Vetor *vetor, int inicio, int fim) {
  if (fim - inicio > 1) {
    int meio = (inicio + fim) / 2;

    printf("Dividindo: [");
    for (int i = inicio; i < fim; i++)
      printf(" %d", vetor->dados[i]);
    printf(" ] em [%d:%d] e [%d:%d]\n", inicio, meio, meio, fim);

    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio, fim);
    merge(vetor, inicio, meio, fim);

    printf("Após o merge: [");
    for (int i = inicio; i < fim; i++)
      printf(" %d", vetor->dados[i]);
    printf("] \n");
  }
}

int buscaSequencial(Vetor *vetor, int chave) {
  int indice = 0;
  while (indice < vetor->ultimo) {
    if (chave == vetor->dados[indice])
      return indice;
    else
      indice++;
  }
  return NAO_ENCONTRADO;
}

void insercaoSequencial(Vetor *vetor, int chave) {
  if (vetor->ultimo < vetor->tamanho) {
    if (buscaSequencial(vetor, chave) == NAO_ENCONTRADO) {
      vetor->dados[vetor->ultimo] = chave;
      vetor->ultimo++;
      printf("Valor inserido com sucesso!\n");
    } else {
      printf("O elemento %i já existe na lista!\n", chave);
    }
  } else {
    printf("Vetor Cheio!\n");
  }
}

int excluir(Vetor *vetor, int chave) {
  int indice;
  int posicao = buscaSequencial(vetor, chave);
  if (posicao == NAO_ENCONTRADO)
    return FALSE;
  for (indice = posicao; indice < vetor->ultimo - 1; indice++)
    vetor->dados[indice] = vetor->dados[indice + 1];
  --vetor->ultimo;
  return TRUE;
}

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != TRUE) {
    while (getchar() != '\n')
      ;
    printf("%s", mensagem);
  }
  return valorLido;
}

int main(void) {
  Vetor vetor;
  int opcao, tempChave = NAO_ENCONTRADO;
  vetor.dados = (int *)malloc(sizeof(int) * 1);
  vetor.tamanho = 1;
  vetor.ultimo = 0;

  do {
    printf("----------------------------------------"
           "\n Lista Linear Sequencial Com MergeSort\n"
           "----------------------------------------\n");
    printf(" Digite um número para escolher a opção:  \n"
           " 1 ⟶ Para Imprimir o vetor\n"
           " 2 ⟶ Para inserir um valor\n"
           " 3 ⟶ Para buscar um valor\n"
           " 4 ⟶ Para excluir um valor\n"
           " 5 ⟶ Para Ordenar o vetor (Merge sort)\n"
           " 0 ⟶ Para sair\n");
    opcao = lerInteiro("Opção: ");

    switch (opcao) {
    default:
      system("clear");
      printf("Opção inválida!\n");
      break;
    case VER:
      system("clear");
      printf("Imprimindo...\n");
      imprimeVetor(vetor);
      break;
    case INSERIR:
      system("clear");
      printf("Inserindo...\n");
      vetor.dados =
          (int *)realloc(vetor.dados, sizeof(int) * (vetor.tamanho + 1));
      ++vetor.tamanho;
      tempChave =
          lerInteiro("Insira aqui o valor da chave que deseja inserir: ");
      insercaoSequencial(&vetor, tempChave);
      break;
    case BUSCAR:
      system("clear");
      printf("Buscando...\n");
      tempChave = lerInteiro("Digite o valor que deseja buscar: ");
      int tempBusca = buscaSequencial(&vetor, tempChave);
      if (tempBusca != NAO_ENCONTRADO)
        printf("O valor %i foi encontrado no índice %i.\n", tempChave,
               tempBusca);
      else
        printf("%i não esta presente no vetor.\n", tempChave);
      break;
    case EXCLUIR:
      system("clear");
      printf("Excluindo...\n");
      tempChave = lerInteiro("Digite o valor que deseja remover da lista: ");
      tempBusca = buscaSequencial(&vetor, tempChave);
      if (excluir(&vetor, tempChave)) {
        printf("%i removido com sucesso!\n", tempChave);
      } else
        printf("O valor %i não foi encontrado no vetor.\n", tempChave);
      break;
    case ORDENAR:
      system("clear");
      printf("Ordenando...\n");
      mergeSort(&vetor, 0, vetor.ultimo);
      printf("\nMerge Sort completo: ");
      imprimeVetor(vetor);
      break;
    case SAIR:
      system("clear");
      printf("Saindo...\n");
      break;
    }

  } while (opcao != SAIR);
  printf("Até logo!");
  free(vetor.dados);
  return 0;
}
