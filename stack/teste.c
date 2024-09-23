#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    struct No *next;
} No;

// Função para criar um novo nó na pilha
No *novoNo(No *data) {
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->next = data;
    return novo_no;
}

// Exclui o '\n' do final da string
void Excluir(char *string) {
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}

// Remove o topo da pilha e retorna o novo topo
No *pop(No *data) {
    if (data != NULL) {
        No *temp = data;
        data = data->next;
        free(temp);
    }
    return data;
}

// Conta os elementos na pilha
int contar(No *data) {
    int n = 0;
    while (data != NULL) {
        n++;
        data = data->next;
    }
    return n;
}

// Função principal que manipula as pilhas
void Pilha(No **headback, No **headforward) {
    char string[10];

    while (fgets(string, 10, stdin) != NULL) {
        Excluir(string);

        // Comando ENTER - Adiciona à pilha de BACK e limpa a de FORWARD
        if (strcmp(string, "ENTER") == 0) {
            *headback = novoNo(*headback);
            *headforward = NULL;  // Esvazia a pilha de FORWARD ao entrar em um novo site
        } 
        // Comando BACK - Adiciona à pilha de FORWARD e remove da pilha de BACK
        else if (strcmp(string, "BACK") == 0 && *headback != NULL) {
            *headforward = novoNo(*headforward);  // Adiciona o topo da pilha de BACK na pilha de FORWARD
            *headback = pop(*headback);           // Remove o topo da pilha de BACK
        } 
        // Comando FORWARD - Adiciona ENTER
ENTER
ENTER
ENTER
ENTER
BACK
FORWARD
BACK
BACKà pilha de BACK e remove da pilha de FORWARD
        else if (strcmp(string, "FORWARD") == 0 && *headforward != NULL) {
            *headback = novoNo(*headback);        // Adiciona o topo da pilha de FORWARD na pilha de BACK
            *headforward = pop(*headforward);     // Remove o topo da pilha de FORWARD
        }
    }

    // Conta quantos elementos restam nas pilhas
    int forward = contar(*headforward);
    int back = contar(*headback);

    // Exibe os resultados
    printf("BACK: %d\n", back);
    printf("FORWARD: %d\n", forward);
}

int main() {
    No *headback = NULL;
    No *headforward = NULL;

    Pilha(&headback, &headforward);

    return 0;
}
