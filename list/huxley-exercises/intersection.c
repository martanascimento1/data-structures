#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int item;
    struct No* next;
} No;


void inserir(No** list, int novo_item) {
    No* novo_no = (No*)malloc(sizeof(No));
    No* last = *list;

    novo_no->item = novo_item;
    novo_no->next = NULL;

    if (*list == NULL) {
        *list = novo_no;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = novo_no;
}

void remover(No* head) {
    No* current = head;
    No* prox;

    if (current == NULL) {
        return;
    }

    while (current->next != NULL) {
        if (current->item == current->next->item) {
            prox = current->next->next;
            free(current->next);
            current->next = prox;
        } else {
            current = current->next;
        }
    }
}


void intersection(No* l1, No* l2) {
    No* resultado = NULL;

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

    remover(resultado);

    if (resultado == NULL) {
        printf("VAZIO\n");
    } else {
        printList(resultado);
    }
}

void free(No** head) {
    No* current = *head;
    No* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
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
    free(&l1);
    free(&l2);

    return 0;
}


