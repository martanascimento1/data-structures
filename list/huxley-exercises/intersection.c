#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int item;
    struct No* next;
} No;


void inserir(No** lista, int n) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->item = n;
    novo_no->next = NULL;

    if (*lista == NULL || n < (*lista)->item) {
        novo_no->next = *lista;
        *lista = novo_no;
    } else {
        No* atual = *lista;
        while (atual->next != NULL && atual->next->item < n) {
            atual = atual->next;
        }
        novo_no->next = atual->next;
        atual->next = novo_no;
    }
}

void remover(No* head) {
    No* current = head;

    while (current != NULL && current->next != NULL) {
        No* prox = current;
        while (prox->next != NULL) {
            if (current->item == prox->next->item) {
                No* next = prox->next->next;
                free(prox->next);
                prox->next = next;
            } else {
                prox = prox->next;
            }
        }
        current = current->next;
    }
}

void intersection(No* l1, No* l2) {
    No* resultado = NULL;

    remover(l1);
    remover(l2);

    while (l1 != NULL && l2 != NULL) {
        if (l1->item == l2->item) {
            inserir(&resultado, l1->item);
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1->item < l2->item) {
            l1 = l1->next;
        } else {
            l2 = l2->next;
        }
    }

    if (resultado == NULL) {
        printf("VAZIO\n");
    } else {
        printList(resultado);
    }
}

void printList(No* node) {
    while (node != NULL) {
        printf("%d\n", node->item);
        node = node->next;
    }
}

int main() {
    No* l1 = NULL;
    No* l2 = NULL;
    int a;

    for (int i = 0; i < 20; i++) {
        scanf("%d", &a);
        inserir(&l1, a);
    }
    for (int i = 0; i < 20; i++) {
        scanf("%d", &a);
        inserir(&l2, a);
    }

    intersection(l1, l2);

    return 0;
}
