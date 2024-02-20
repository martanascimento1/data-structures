#include <stdio.h>
#include <stdlib.h>


typedef struct No No;
struct No {
  char item;
  int n;
  No *proximo;
};

No *criar_no(char item, int n) {
  No *novo_no = (No *)malloc(sizeof(No));
  novo_no->item = item;
  novo_no->n = n;
  novo_no->proximo = NULL;
  return novo_no;
}

No *criarLista() {
  int n[256] = {0};
  char item;

  while ((item = getchar()) != EOF) {
    n[item]++;
  }

  No *lista_encadeada = NULL;
  for (int i = 0; i < 256; i++) {
    if (n[i] > 0) {
      No *novo_no = criar_no(i, n[i]);
      novo_no->proximo = lista_encadeada;
      lista_encadeada = novo_no;
    }
  }

  return lista_encadeada;
}

void exibirLista(No *lista_encadeada) {
  while (lista_encadeada != NULL) {
    printf("%c %d\n", lista_encadeada->item, lista_encadeada->n);
    lista_encadeada = lista_encadeada->proximo;
  }
}

int main() {

  No *lista = criarLista();
  printf("\n");
  exibirLista(lista);

  return 0;
}
