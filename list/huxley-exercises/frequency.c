#include <stdio.h>
#include <stdlib.h>


typedef struct No No;
struct No {
  char item;
  int n;
  No *next;
};

No *criarNo(char item, int n) {
  No *no = (No *)malloc(sizeof(No));
  no->item = item;
  no->n = n;
  no->next = NULL;
  return no;
}

No *criarLista() {
  int n[256] = {0};
  char item;

  while ((item = getchar()) != EOF) {
    n[item]++;
  }

  No *lista = NULL;
  for (int i = 0; i < 256; i++) {
    if (n[i] > 0) {
      No *no = criarNo(i, n[i]);
      no->next = lista;
      lista = no;
    }
  }

  return lista;
}

void exibirLista(No *lista) {
  while (lista != NULL) {
    printf("%c %d\n", lista->item, lista->n);
    lista = lista->next;
  }
}

int main() {

  No *lista = criarLista();
  printf("\n");
  exibirLista(lista);

  return 0;
}
