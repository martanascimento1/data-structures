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

// Função para encontrar a maior sequência de zeros
void findMaxZeroSequence(Node* head) {
    int maxStart = -1, maxEnd = -1;
    int currentStart = -1, currentEnd = -1;
    int maxLength = 0, currentLength = 0;
    int position = 0;

    Node* current = head;
    while (current != NULL) {
        if (current->data == 0) {
            if (currentStart == -1)
                currentStart = position;
            currentEnd = position;
            currentLength++;

            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxStart = currentStart;
                maxEnd = currentEnd;
            }
        } else {
            currentStart = -1;
            currentEnd = -1;
            currentLength = 0;
        }

        current = current->next;
        position++;
    }

    if (maxStart != -1 && maxEnd != -1) {
        printf("%d %d\n", maxStart, maxEnd);
    } else {
        printf("Nenhuma sequência de zeros encontrada.\n");
    }
}

// Função principal
int main() {
  No* lista = NULL;
    int n;

    while (scanf("%d", &n) != EOF) {
        inserir(&lista, n);
    }

    // Encontrar a maior sequência de zeros
    findMaxZeroSequence(head);

    return 0;
}

