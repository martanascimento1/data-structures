#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
struct Node {
    int data;
    struct Node* next;
};

// Função para trocar os dados de dois nós
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Função para inserir um novo nó no início da lista
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Função para imprimir a lista
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Função para liberar a memória alocada pela lista
void freeList(struct Node* node) {
    struct Node* tmp;
    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
}

// Função para ordenar a lista encadeada em ordem crescente usando Bubble Sort
void bubbleSort(struct Node* start) {
    int swapped;
    struct Node* ptr;
    struct Node* lptr = NULL;

    // Caso base
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr = start;

        while (ptr->next != lptr) {
            if (ptr->data > ptr->next->data) {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

// Função principal
int main() {
    struct Node* start = NULL;
    int n, data;

    printf("Quantos números deseja inserir na lista? ");
    scanf("%d", &n);

    printf("Digite os números separados por espaços:\n");

    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        push(&start, data);
    }

    printf("Lista antes da ordenação: ");
    printList(start);

    // Chamada da função para ordenar a lista
    bubbleSort(start);

    printf("Lista ordenada: ");
    printList(start);

    // Libera a memória alocada pela lista
    freeList(start);

    return 0;
}

