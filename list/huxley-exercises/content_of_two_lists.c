#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para um nó da lista encadeada
struct Node {
    int data;
    struct Node* next;
};

// Função para inserir um novo nó no final da lista
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para verificar se B é um subconjunto de A
int isSubset(struct Node* A, struct Node* B) {
    struct Node* ptrB = B;
    while (ptrB != NULL) {
        int found = 0;
        struct Node* ptrA = A;
        while (ptrA != NULL) {
            if (ptrA->data == ptrB->data) {
                found = 1;
                break;
            }
            ptrA = ptrA->next;
        }
        if (!found) {
            return 0; // Se um elemento de B não for encontrado em A, B não é um subconjunto de A
        }
        ptrB = ptrB->next;
    }
    return 1; // Se todos os elementos de B forem encontrados em A, B é um subconjunto de A
}

// Função para imprimir os elementos de uma lista encadeada
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Digite o tamanho da primeira lista: ");
    scanf("%d", &n);
    
    struct Node* A = NULL;
    printf("Digite os elementos da primeira lista: ");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&A, data);
    }
    
    printf("Digite o tamanho da segunda lista: ");
    scanf("%d", &m);
    
    struct Node* B = NULL;
    printf("Digite os elementos da segunda lista: ");
    for (int i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&B, data);
    }
    
    if (isSubset(A, B)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}
