#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista encadeada
typedef struct No No;
struct No {
  int item;
  No *next;
};

// Função para criar um novo nó
No *criar_no(int item) {
  No *novo_no = (No *)malloc(sizeof(No));
  novo_no->item = item;
  novo_no->next = NULL;
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
      anterior->next = novo_no;
    }
    anterior = novo_no;
  }

  return lista;
}
void sequencia(No *lista, int *inicio, int *fim) {
  
    int tamanho_atual = 0;
    int tamanho_maximo = 0;
    int inicio_atual = -1; // Inicializa com -1 para tratar caso não haja sequência de 0
    int inicio_maximo = -1;
    int posicao = 0; // Variável para rastrear a posição atual na lista

    while (lista != NULL) {
        if (lista->item == 0) {
            tamanho_atual++;
            if (tamanho_atual > tamanho_maximo) {
                tamanho_maximo = tamanho_atual;
                inicio_maximo = inicio_atual;
            }}
            else {
            tamanho_atual = 0;
            inicio_atual = posicao + 1; // Atualiza o início da sequência
        }
        lista = lista->next;
        posicao++;
    }
    if (tamanho_maximo > 0) {
        *inicio = inicio_maximo;
        *fim = inicio_maximo + tamanho_maximo - 1;
    } else {
        *inicio = -1;
        *fim = -1;
    } }

int main() {

  int inicio, fim;
  No *lista = inserir();
  sequencia(lista, &inicio, &fim);
  printf("%d %d\n", inicio, fim);

  return 0;
}


