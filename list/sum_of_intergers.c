#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó com um dado valor
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo nó no início da lista
void insertAtBeginning(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Função para imprimir a lista encadeada
void printList(Node* head) {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

// Função para liberar a memória alocada para a lista encadeada
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Função para somar duas listas encadeadas representando números
Node* addLists(Node* num1, Node* num2) {
    Node* result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;

        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        insertAtBeginning(&result, sum);
    }

    return result;
}

int main() {
    Node* num1 = NULL;
    Node* num2 = NULL;

    // Leitura do primeiro número
    printf("Digite o primeiro número (termine com '+'): ");
    char ch;
    while ((ch = getchar()) != '+') {
        if (ch >= '0' && ch <= '9') {
            int digit = ch - '0';
            insertAtBeginning(&num1, digit);
        }
    }

    // Leitura do segundo número
    printf("Digite o segundo número (termine com '='): ");
    while ((ch = getchar()) != '=') {
        if (ch >= '0' && ch <= '9') {
            int digit = ch - '0';
            insertAtBeginning(&num2, digit);
        }
    }

    // Soma dos números
    Node* result = addLists(num1, num2);

    // Impressão do resultado
    printf("Resultado da soma: ");
    printList(result);

    // Liberação de memória
    freeList(num1);
    freeList(num2);
    freeList(result);

    return 0;
}
