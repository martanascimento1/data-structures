#include <stdio.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para inserir um elemento no final da lista
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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
    Node* head = NULL;
    int num;

    // Leitura da entrada
    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            insert(&head, num);
            break;
        }
        insert(&head, num);
    }

    // Encontrar a maior sequência de zeros
    findMaxZeroSequence(head);

    return 0;
}
