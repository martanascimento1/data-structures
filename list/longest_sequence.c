#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* novoNo(int data) {
    struct Node* novo_no = (struct Node*) malloc(sizeof(struct Node));
    novo_no->data = data;
    novo_no->next = NULL;
    return novo_no;
}

void inserirNoFinal(struct Node** head_ref, int data) {
    struct Node* novo_no = novoNo(data);
    if (*head_ref == NULL) {
        *head_ref = novo_no;
        return;
    }
    struct Node* ultimo = *head_ref;
    while (ultimo->next != NULL) {
        ultimo = ultimo->next;
    }
    ultimo->next = novo_no;
}

void maiorSequenciaZeros(struct Node* head) {
    int pos = 1;
    int count = 0, maxCount = 0, start = 0, maxStart = 0;
    struct Node* atual = head;
    while (atual != NULL) {
        if (atual->data == 0) {
            if (count == 0) start = pos;
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                maxStart = start;
            }
            count = 0;
        }
        atual = atual->next;
        pos++;
    }
    if (count > maxCount) {
        maxCount = count;
        maxStart = start;
    }
    printf("%d %d\n", maxStart, maxStart + maxCount - 1);
}

int main() {
    struct Node* head = NULL;
    int data;
    while (scanf("%d", &data) != EOF) {
        if (data == 0) {
            break;
        }
        inserirNoFinal(&head, data);
    }
    maiorSequenciaZeros(head);
    return 0;
}