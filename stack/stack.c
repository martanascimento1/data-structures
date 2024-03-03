#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

typedef struct {
    int count;
    char states[MAX][MAX];
} StackStates;

void push(Stack *s, StackStates *ss, int value) {
    if (s->top == MAX - 1) {
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s, StackStates *ss) {
    if (s->top == -1) {
        return -1;
    }
    int popped = s->items[(s->top)--];
    return popped;
}

void saveStackState(Stack *s, StackStates *ss) {
    char state[MAX] = "";
    for (int i = s->top; i >= 0; i--) {
        char item[10];
        sprintf(item, "%d ", s->items[i]);
        strcat(state, item);
    }
    strcpy(ss->states[ss->count++], state);
}

void printStackStates(StackStates *ss) {

    for (int i = 0; i < ss->count; i++) {
        printf("%s\n", ss->states[i]);
    }
}

void imprimirPilha(Stack *s, StackStates *ss) {
    char state[MAX] = "";
    for (int i = s->top; i >= 0; i--) {
        char item[10];
        sprintf(item, "%d ", s->items[i]);
        strcat(state, item);
    }
   
    strcpy(ss->states[ss->count++], state);
}

int main() {
    Stack s;
    s.top = -1;
    StackStates ss;
    ss.count = 0;
    char command[20];
    int value;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "Empilhar") == 0) {
            scanf("%d", &value);
            push(&s, &ss, value);
        } else if (strcmp(command, "Desempilhar") == 0) {
            pop(&s, &ss);
        } else if (strcmp(command, "Imprimir") == 0) {
          imprimirPilha(&s, &ss);
        }  else if (strcmp(command, "Finalizar") == 0) {
            break;
    } }


    printStackStates(&ss);

    return 0;
}