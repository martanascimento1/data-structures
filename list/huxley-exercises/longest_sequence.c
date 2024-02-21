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


No *inserir() {
  No *lista = NULL;
  No *anterior = NULL;
  int valor;
while (scanf("%d", &valor) != EOF) {
  if (valor == 0) {
    break;
  } 
  No *novo_no = criar_no(valor);
    if (lista == NULL) {
      lista = novo_no;
    } else {
      anterior->proximo = novo_no;
    }
    anterior = novo_no;
  }

  return lista;
}
void sequencia(No *lista, int *inicio, int *fim) {
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

  // Corrige o cálculo do fim da sequência
  if (tamanho_maximo > 0) {
    *fim = inicio_maximo + tamanho_maximo - 1;
  } else {
    *inicio = -1;
    *fim = -1;
  }
}

int main() {
  No *lista = inserir();
  int inicio, fim;
  sequencia(lista, &inicio, &fim);

  printf("%d %d\n", inicio, fim);

  return 0;
}


