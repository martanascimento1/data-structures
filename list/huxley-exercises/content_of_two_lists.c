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

int verificar(No* lista1, No* lista2) {
    while (lista2 != NULL) {
        int n = 0;
        No* l1 = lista1;
        while (l1 != NULL) {
            if (l1->item == lista2->item) {
                n = 1;
                break;
            }
            l1 = l1->next;
        }
        if (!n) {
            return 0; 
        }
        lista2 = lista2->next;
    }
    return 1; 
}

int main() {
    int n, m, x, y;
    scanf("%d", &n);

    No* lista1 = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        inserir(&lista1, x);
    }
    scanf("%d", &m);
    No* lista2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &y);
        inserir(&lista2, y);
    }

    if (verificar(lista1, lista2)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
