#include <stdio.h>
#include <stdlib.h>

struct No {
    int item;
    struct No* next;
};

void inverter(struct No* a, struct No* b) {
    int temp = a->item;
    a->item = b->item;
    b->item = temp;
}

void push(struct No** head_ref, int new_data) {
    struct No* new_node = (struct No*)malloc(sizeof(struct No));
    new_node->item = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct No* node) {
    while (node != NULL) {
        printf("%d ", node->item);
        node = node->next;
    }
    printf("\n");
}

void bubbleSort(struct No* start) {
    int swapped;
    struct No* ptr;
    struct No* lptr = NULL;

    // Caso base
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr = start;

        while (ptr->next != lptr) {
            if (ptr->item > ptr->next->item) {
                inverter(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

// Função principal
int main() {
    struct No* start = NULL;
    int data;

    printf("Digite os números separados por espaços (Ctrl+D para finalizar):\n");

    // Lê os números até o final do arquivo (EOF)
    while (scanf("%d", &data) != EOF) {
        push(&start, data);
    }

    // Chamada da função para ordenar a lista
    bubbleSort(start);
    printList(start);

    return 0;
}
