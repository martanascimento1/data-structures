#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int item;
    struct No* next;
} No;

void inserir(No** lista, int novo_item) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->item = novo_item;
    novo_no->next = NULL;

    if (*lista == NULL) {
        *lista = novo_no;
    } else {
        No* ultimo = *lista;
        while (ultimo->next != NULL) {
            ultimo = ultimo->next;
        }
        ultimo->next = novo_no;
    }
}
void inverter(No** lista) {
    No* anterior = NULL;
    No* atual = *lista;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->next; 
        atual->next = anterior; 
        anterior = atual; 
        atual = proximo; 
    }

    *lista = anterior; 
}
void imprimir(No* lista) {
    if (lista == NULL) {
        return;
    }
    printf("%d ", lista->item);
    imprimir(lista->next);
}



int main () {

No* lista = NULL;
    int n;

    while (scanf("%d", &n) != EOF) {
        inserir(&lista, n);
    }
    inverter(&lista);
    printf("\n");
    imprimir(lista);
     
    return 0;
}
void inverter(LISTA** l)
{
    LISTA* anterior = NULL;
    LISTA* atual = *l;
    LISTA* prox;

    while (atual != NULL) {
        prox = atual->cabeca;
        atual->cabeca = anterior;
        anterior = atual;
        atual = prox;
    }

    *l = anterior;

}