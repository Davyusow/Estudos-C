# Algoritmos
Este readme é dedicado à anotações a respeito de algoritmos e estrutura de dados

<details> <summary> <h1>Insertion Sort</h1> </summary>

É um algoritmo de ordanação por **inserção**, daí o nome, feito apartir de um array  
que constroe uma matriz com um elemento por vez. Uma analogia com o mundo real é o
embaralhamento de cartas.

- Características 
1. Fácil implementação e manuntenção
2. Requer quantidade constante de memória
3. É estável
4. Bom para trabalhar com pequenas entradas  
e arrays quase completamente ordenados

## Pseudocódigo

```
procedimento insertionSort(vetor[], tamanho){
  i,j,chave
	para i = 1 até tamanho-1 passo 1{
      chave = vetor[i];
      j = i - 1;
      enquanto(j>=0 && vetor[j]>chave){
      	vetor[j + 1] = vetor[j];
      	j--;
      }
      vetor[j + 1] = chave;
	}
}
```
_tal que 'i' é o índice que vai do ínicio ao fim do vetor_  
_'j' é o índice que percorre os valores anteriores do vetor_  
_e 'chave' é o valor do vetor comparado no momento._

| índice = i | comparador = j | 1 | 2 | 3 | 4 |
|------------|----------------|---|---|---|---|
| Inicial    | -              | 7 | 5 | 1 | 2 |
| 1          | 0              | 5 | 7 | 1 | 2 |
| 2          | 1 → 0          | 1 | 5 | 7 | 2 |
| 3          | 2 → 1 → 0      | 1 | 2 | 5 | 7 |

> A aplicação do algoritmo em C pode ser visto no arquivo  
**InsertionSort.c** deste repositório
</details>