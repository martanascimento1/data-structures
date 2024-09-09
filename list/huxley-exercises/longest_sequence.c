#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct No {
    int item;
    struct No* next;
};


void inserir(struct No** lista, int item) {
    struct No* novo_no = (struct No*)malloc(sizeof(struct No));
    novo_no->item = item;
    novo_no->next = NULL;


    if (*lista == NULL) {
        *lista = novo_no;
    } else {
        struct No* current = *lista;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = novo_no;
    }
}

void freeList(struct No* lista) {
    while (lista != NULL) {
        struct No* temp = lista;
        lista = lista->next;
        free(temp);
    }
}

void sequencia(const char* str, int* start, int* end) {
    struct No* lista = NULL; 
    int currentStart = -1;
    int longestStart = -1;
    int longestEnd = -1;
    int maxLength = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            if (currentStart == -1) {
                currentStart = i;
            }
        } else {
            if (currentStart != -1) {
                int currentLength = i - currentStart;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    longestStart = currentStart;
                    longestEnd = i - 1;
                }
                inserir(&lista, currentStart);
                currentStart = -1;
            }
        }
    }

    if (currentStart != -1) {
        int currentLength = strlen(str) - currentStart;
        if (currentLength > maxLength) {
            longestStart = currentStart;
            longestEnd = strlen(str) - 1;
        }
        inserir(&lista, currentStart);
    }

    *start = longestStart;
    *end = longestEnd;

    freeList(lista);
}

int main() {
    char str[255];

    while (1) {
        scanf("%s", str);
        if (strcmp(str, "0") == 0) {
            break;
        }

        int start, end;
        sequencia(str, &start, &end);

        if (start != -1 && end != -1) {
            printf("%d %d\n", start, end);
        }
    }

    return 0;
}