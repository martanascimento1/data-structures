#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int *lista;         
    int tamanho;        
    struct No* next;     
} No;

typedef struct Pilha {
    No *top;            
} Pilha;


Pilha *create_stack() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->top = NULL;    
    return p;
}


void remover_linha(char *string) {
    int newlinePos = strcspn(string, "\n");
    string[newlinePos] = '\0';
}

void push(Pilha *pilha, int *lista, int tamanho) {
    No *novo_no = (No*)malloc(sizeof(No));
    novo_no->lista = (int*)malloc(tamanho * sizeof(int));
    memcpy(novo_no->lista, lista, tamanho * sizeof(int));  
    novo_no->tamanho = tamanho;
    novo_no->next = pilha->top;
    pilha->top = novo_no;
}

void pop(Pilha *pilha) {
    if (pilha->top == NULL) {
        printf("EMPTY STACK\n");
        return;
    }
    No *temp = pilha->top;
    pilha->top = pilha->top->next;

    for (int i = 0; i < temp->tamanho; i++) {
        if (i > 0) {
            printf(" ");  
        }
        printf("%d", temp->lista[i]);
    }
    printf("\n");
    
    free(temp->lista);
    free(temp);
}

void ler(Pilha *pilha) {
    char x[10];
    int lista[100];  
    int n;
    char aux;

    while (fgets(x, 10, stdin) != NULL) {
        remover_linha(x);

        if (strcmp(x, "PUSH") == 0) {
            n = 0;
            while (scanf("%d%c", &lista[n], &aux) == 2) {
                n++;
                if (aux == '\n') break;
            }
            push(pilha, lista, n);
        } else if (strcmp(x, "POP") == 0) {
            pop(pilha);
        }
    }
}

int main() {
    Pilha *p = create_stack();
    ler(p);


    return 0;
}

