#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Pilha;

typedef struct {
    int count;
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
   
    strcpy(s->states[s->count++], state);
}
void push(Pilha *p, Stack *s, int x) {
    if (p->top == MAX - 1) {
        return;
    }
    p->items[++(p->top)] = x;
}

int pop(Pilha *p, Stack *s) {
    if (p->top == -1) {
        return -1;
    }
    int topo = p->items[(p->top)--];
    return topo;
}

void exibirPilha(Stack *s) {

    for (int i = 0; i < s->count; i++) {
        printf("%s\n", s->states[i]);
    }
}

int main() {
    Pilha p;
    p.top = -1;
    Stack s;
    s.count = 0;
    char command[20];
    int valor;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "Empilhar") == 0) {
            scanf("%d", &valor);
            push(&p, &s, valor);
        } else if (strcmp(command, "Desempilhar") == 0) {
            pop(&p, &s);
        } else if (strcmp(command, "Imprimir") == 0) {
          salvar(&p, &s);
        }  else if (strcmp(command, "Finalizar") == 0) {
            break;
    } }


    exibirPilha(&s);

    return 0;
}