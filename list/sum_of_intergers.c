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

void inserirNoInicio(struct Node** head_ref, int data) {
    struct Node* novo_no = novoNo(data);
    novo_no->next = *head_ref;
    *head_ref = novo_no;
}

void imprimirLista(struct Node* head) {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    int leadingZero = 1;
    while (head != NULL) {
        if (head->data != 0 || !leadingZero) {
            printf("%d ", head->data);
            leadingZero = 0;
        }
        head = head->next;
    }
    printf("\n");
}

struct Node* somarListas(struct Node* first, struct Node* second) {
    struct Node* res = NULL;
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first? first->data: 0) + (second? second->data: 0);
        carry = (sum >= 10)? 1 : 0;
        sum = sum % 10;
        temp = novoNo(sum);
        if (res == NULL) res = temp;
        else prev->next = temp;
        prev = temp;
        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0) temp->next = novoNo(carry);

    return res;
}

struct Node* inverterLista(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* res = NULL;
    int data;

    while (scanf("%d", &data) == 1 && data != '+') {
        inserirNoInicio(&first, data);
    }

    while (scanf("%d", &data) == 1 && data != '=') {
        inserirNoInicio(&second, data);
    }

    res = somarListas(first, second);
    res = inverterLista(res);
    imprimirLista(res);

    return 0;
}
