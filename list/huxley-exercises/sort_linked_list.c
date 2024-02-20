#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int item;
    struct No *next;
}No;

void inverter(No* a, No* b) {
    int temp = a->item;
    a->item = b->item;
    b->item = temp;
}

void inserir(No** head, int n) {
    No* node = (No*)malloc(sizeof(No));
    node->item = n;
    node->next = (*head);
    (*head) = node;
}

void exibirLista(No* node) {
    printf("\n");
    while (node != NULL) {
        printf("%d ", node->item);
        node = node->next;
    }
}

void bubbleSort(No* lista) {

    if (lista == NULL) {
        return;
    }

    int troca = 1;
    No* primeiro = lista;
    No* ultimo = NULL;

    while (troca) {
        troca = 0;
        primeiro = lista;

        while (primeiro->next != ultimo) {
            if (primeiro->item > primeiro->next->item) {
                inverter(primeiro, primeiro->next);
                troca = 1;
            }
            primeiro = primeiro->next;
        }
        ultimo = primeiro;
    }
}

int main() {
    struct No* head = NULL;
    int n;

    while (scanf("%d", &n) != EOF) {
        inserir(&head, n);
    }
    bubbleSort(head);
    exibirLista(head);

    return 0;
}

