#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int item;
    struct No *next;
}No;

No *criar_no(char caractere, int frequencia) {
  No *novo_no = (No *)malloc(sizeof(No));
  novo_no->caractere = caractere;
  novo_no->frequencia = frequencia;
  novo_no->proximo = NULL;
  return novo_no;
}

// Função para criar uma lista encadeada onde cada nó possui o caractere e sua frequência no texto
No *criar_lista_encadeada() {
  // Dicionário para armazenar a frequência de cada caractere
  int frequencia[256] = {0};
  char caractere;

  // Lê cada caractere do usuário
  while ((caractere = getchar()) != EOF) {
    frequencia[caractere]++;
  }

  // Lista encadeada para armazenar os caracteres e suas frequências
  No *lista_encadeada = NULL;
  for (int i = 0; i < 256; i++) {
    if (frequencia[i] > 0) {
      // Cria um novo nó
      No *novo_no = criar_no(i, frequencia[i]);

      // Insere o novo nó no início da lista
      novo_no->proximo = lista_encadeada;
      lista_encadeada = novo_no;
    }
  }

  return lista_encadeada;
}

// Função para imprimir a lista encadeada
void imprimir_lista_encadeada(No *lista_encadeada) {
  while (lista_encadeada != NULL) {
    printf("%c %d\n", lista_encadeada->caractere, lista_encadeada->frequencia);
    lista_encadeada = lista_encadeada->proximo;
  }
}

int main() {
  // Cria a lista encadeada
  No *lista_encadeada = criar_lista_encadeada();

   printf("\n");
  imprimir_lista_encadeada(lista_encadeada);

  return 0;
}
