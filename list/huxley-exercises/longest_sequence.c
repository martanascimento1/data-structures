#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista encadeada
typedef struct No No;
struct No {
  int valor;
  No *proximo;
};

// Função para criar um novo nó
No *criar_no(int valor) {
  No *novo_no = (No *)malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = NULL;
  return novo_no;
}

// Função para criar uma lista encadeada
No *criar_lista_encadeada() {
  No *lista = NULL;
  No *anterior = NULL;
  int valor;

  // Lê cada valor do usuário
  while (scanf("%d", &valor) != EOF) {
    // Cria um novo nó
    No *novo_no = criar_no(valor);

    // Insere o novo nó no final da lista
    if (lista == NULL) {
      lista = novo_no;
    } else {
      anterior->proximo = novo_no;
    }
    anterior = novo_no;
  }

  return lista;
}

// Função para imprimir a lista encadeada
void imprimir_lista_encadeada(No *lista) {
  while (lista != NULL) {
    printf("%d ", lista->valor);
    lista = lista->proximo;
  }
  printf("\n");
}

// Função para encontrar a maior sequência de 0 na lista encadeada
void encontrar_maior_sequencia_de_zeros(No *lista, int *inicio, int *fim) {
  int tamanho_atual = 0;
  int tamanho_maximo = 0;
  int inicio_atual = 0;
  int inicio_maximo = 0;

  while (lista != NULL) {
    if (lista->valor == 0) {
      tamanho_atual++;
      if (tamanho_atual > tamanho_maximo) {
        tamanho_maximo = tamanho_atual;
        inicio_maximo = inicio_atual;
      }
    } else {
      tamanho_atual = 0;
      inicio_atual = lista->proximo;
    }
    lista = lista->proximo;
  }

  *inicio = inicio_maximo;
 *fim = inicio_maximo + tamanho_maximo - 2; // Correção: subtrai 2 do tamanho_maximo

}


int main() {
  // Cria a lista encadeada
  No *lista = criar_lista_encadeada();

  // Imprime a lista encadeada
  imprimir_lista_encadeada(lista);

  // Encontra a maior sequência de 0
  int inicio, fim;
  encontrar_maior_sequencia_de_zeros(lista, &inicio, &fim);

  // Imprime a posição inicial e final da maior sequência de 0
  printf("\n");
  printf("%d %d\n", inicio, fim);

  return 0;
}


