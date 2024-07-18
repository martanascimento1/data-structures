#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Pilha;

typedef struct {
    int valor;
    char states[MAX][MAX];
} Stack;

void salvar(Pilha *p, Stack *s) {
    char state[MAX] = "";
    for (int i = p->top; i >= 0; i--) {
        char item[10];
        sprintf(item, "%d", p->items[i]);
        strcat(state, item);
        if (i != 0) { 
            strcat(state, " ");
        }
    }
    strcpy(s->states[s->valor++], state);
}

void push(Pilha *p, Stack *s, int x) {
    if (p->top == MAX - 1) {
        return;
    }
    p->items[++(p->top)] = x;
    salvar(p, s);
}

int pop(Pilha *p, Stack *s) {
    if (p->top == -1) {

        return -1;
    }
    int topo = p->items[(p->top)--];
    salvar(p, s);
    return topo;
}

void exibirPilha(Stack *s) {
    for (int i = 0; i < s->valor; i++) {
        printf("%s\n", s->states[i]);
    }
}

int main() {
    Pilha p;
    p.top = -1;
    Stack s;
    s.valor = 0;
    char command[20];
    int n;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "Empilhar") == 0) {
            scanf("%d", &n);
            push(&p, &s, n);
        } else if (strcmp(command, "Desempilhar") == 0) {
            pop(&p, &s);
        } else if (strcmp(command, "Fim") == 0) {
            break;
        }
    }

    exibirPilha(&s);

    return 0;
}