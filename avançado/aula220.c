#include "stdio.h"
#include "stdlib.h"


//constantes lógicas
#define TAM 50
#define TRUE 1
#define FALSE 0
//constantes do menu
#define CADASTRAR 1
#define EDITAR 2
#define IMPRIMIR 3
#define SALVAR 4
#define CARREGAR 5
#define SALVAR_BINARIO 6
#define CARREGAR_BINARIO 7
#define SAIR 0


typedef struct Contato{
    char nome[TAM];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **contatos,int quant){ //ponteiro para ponteiro pois a agenda é um array e ponteiro (dois *)
    printf("\nLista de Contatos: \n\n");
    for(int indice = 0;indice < quant; indice++){
        printf("id: %i = %2i/%2i/%4i  %s\n",indice + 1,
            contatos[indice]->dia, contatos[indice]->mes, contatos[indice]->ano, contatos[indice]->nome);
    }
}

int cadastrarContato(Contato **contatos, int quant){
    if(quant < TAM){
        Contato *novo = malloc(sizeof(Contato));
        printf("Digite seu nome: ");
        scanf("%50[^\n]",novo->nome);
        printf("Digite a data de nascimento: dd/mm/aaaa: ");
        scanf(" %i/%i/%i",&novo->dia,&novo->mes,&novo->ano);
        contatos[quant] = novo;
        return TRUE;
    }else{
        printf("\nImpossível cadastrar, vetor cheito!\n");
        return FALSE;
    }
}

void aleterarContato(Contato **contatos, int quant){
    imprimir(contatos, quant);
    int id;
    printf("\nDigite o id do contato que deseja alterar: ");
    scanf(" %i",&id); id--;
    getchar();

    if(id >= 0 && id < quant){
        cadastrarContato(contatos, id);
    }else{
        printf("\nid inválido!");
    }
}

void salvar(Contato **contatos, int quant, char file[]) {
    FILE *arquivo = fopen(file, "w");
    if (arquivo) {
        fprintf(arquivo, "%d\n", quant);
        for (int i = 0; i < quant; i++) {
            fprintf(arquivo, "%s\n", contatos[i]->nome);
            fprintf(arquivo, "%d/%d/%d\n", contatos[i]->dia, contatos[i]->mes, contatos[i]->ano);
        }
        fclose(arquivo);
    } else {
        printf("\nErro ao abrir o arquivo!");
    }
}

int carregar(Contato **contatos, int quant, char file[]) {
    FILE *arquivo = fopen(file, "r");
    if (arquivo == NULL) {
        printf("\nErro ao carregar o arquivo\n");
        return FALSE;
    }

    for(int i = 0; i < quant; i++){
        free(contatos[i]);
    }

    int quantidadeArquivo;
    if (fscanf(arquivo, "%d", &quantidadeArquivo) != 1) {
        printf("\nErro ao ler a quantidade de contatos do arquivo.\n");
        fclose(arquivo);
        return FALSE;
    }
    fgetc(arquivo);
    for (int i = 0; i < quantidadeArquivo; i++) {
        Contato *novo = malloc(sizeof(Contato));
        if (novo == NULL) {
            printf("\nErro ao alocar memória para o contato %d!\n", i + 1);
            fclose(arquivo);
            return i;
        }

        fscanf(arquivo, "%49[^\n]", novo->nome);
        fscanf(arquivo, " %d/%d/%d", &novo->dia, &novo->mes, &novo->ano);
        fgetc(arquivo);

        contatos[i] = novo;
    }

    fclose(arquivo);
    printf("\n%d contatos carregados!\n", quantidadeArquivo);
    return quantidadeArquivo;
}

void salvarBinario(Contato **contatos,int quant,char file[]){
    FILE *arquivo = fopen(file,"wb");
    if(arquivo){
        for(int indice = 0; indice < quant; indice++){
            fwrite(contatos[indice],sizeof(Contato),1,arquivo);
        }
        fclose(arquivo);
    }else{
        printf("\nErro ao carregar arquivo\n");
    }
}

int carregarBinario(Contato **contatos, char file[]){
    int quant = 0;
    Contato *novo = malloc(sizeof(Contato));
    FILE *arquivo = fopen(file,"rb");
    if(arquivo){
        while(fread(novo,sizeof(Contato),1,arquivo)){
            contatos[quant++] = novo;
            novo = malloc(sizeof(Contato));
        }
        fclose(arquivo);
    }else{
        printf("\nErro ao carregar arquivo\n");
    }
    return quant;
}

int lerInteiro(char *mensagem){
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != TRUE){
    while (getchar() != '\n')
      printf("%s", mensagem);
  }
  return valorLido;
}

int main(void){
    Contato *agenda[TAM];
    char arquivo[] = {"resources/agenda.txt"};
    char arquivoBin[] = {"resources/agenda.dat"};
    int quantidade = 0, opcao = 0;
    do{
        printf("\nDigite a opção desejada:\n"
            "1 -> Cadastrar\n"
            "2 -> Editar\n"
            "3 -> Imprimir\n"
            "4 -> Salvar\n"
            "5 -> Carregar\n"
            "6 -> Salvar em Binário\n"
            "7 -> Carregar em Binário\n"
            "0 -> Sair\n");
        opcao = lerInteiro("Opção: ");
        getchar();
        switch(opcao){
            default:
                printf("\nOpção inválida!");
            break;
            case CADASTRAR:
                quantidade += cadastrarContato(agenda, quantidade);
            break;
            case EDITAR:
                aleterarContato(agenda, quantidade);
            break;
            case IMPRIMIR:
                imprimir(agenda, quantidade);
            break;
            case SALVAR:
                salvar(agenda, quantidade, arquivo);
            break;
            case CARREGAR:
                quantidade = carregar(agenda,quantidade ,arquivo);
            break;
            case SALVAR_BINARIO:
                salvarBinario(agenda,quantidade ,arquivo);
            break;
            case CARREGAR_BINARIO:
                quantidade = carregarBinario(agenda,arquivo);
            break;
            case SAIR:
                printf("\nAté logo!\n");
            break;
        }
    }while(opcao != 0);

    for(int i = 0; i < quantidade; i++){
        free(agenda[i]);
    }
    return 0;
}
