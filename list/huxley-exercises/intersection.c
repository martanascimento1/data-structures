#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int item;
    struct No* next;
} No;

void inserir_ordenado(No** lista, int novo_item) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->item = novo_item;
    novo_no->next = NULL;

    if (*lista == NULL || novo_item < (*lista)->item) {
        novo_no->next = *lista;
        *lista = novo_no;
    } else {
        No* atual = *lista;
        while (atual->next != NULL && atual->next->item < novo_item) {
            atual = atual->next;
        }
        novo_no->next = atual->next;
        atual->next = novo_no;
    }
}

void remover_duplicados(No* head) {
    No* current = head;

    while (current != NULL && current->next != NULL) {
        No* runner = current;
        while (runner->next != NULL) {
            if (current->item == runner->next->item) {
                No* next = runner->next->next;
                free(runner->next);
                runner->next = next;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void intersection(No* l1, No* l2) {
    No* resultado = NULL;

    // Remove duplicates from both lists
    remover_duplicados(l1);
    remover_duplicados(l2);

    // Iterate through both lists, adding common elements to the intersection
    while (l1 != NULL && l2 != NULL) {
        if (l1->item == l2->item) {
            inserir_ordenado(&resultado, l1->item);
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
        inserir_ordenado(&l1, a);
    }
    for (int i = 0; i < 20; i++) {
        scanf("%d", &a);
        inserir_ordenado(&l2, a);
    }

    intersection(l1, l2);

    return 0;
}
