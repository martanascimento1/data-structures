#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

typedef struct Pilha
{
    int top;
    char items[MAX]
} Pilha;

void criar(Pilha *p)
{
    p->top = -1;
}

int cheia(Pilha *p)
{
    return p->top == 255;
}

int vazia(Pilha *p)
{
    return p->top == -1;
}

void push(Pilha *p, char x) {
    if (cheia(p)) {
       return;
}
    p->top++;
    p->items[p->top] = x;
 }

char pop (Pilha *p) {
    if (vazia(p)) {
        return -1;
    }
    char x  = p->items[(p->top)--];
    return x;
}

int balanceamento ( Pilha *p, int n) {


    int ptd=0, pte=0, cd=0, ce=0;

    for (int i=0; i<n; i++) {
        char atual = pop(p);
    
    if (atual == ']') { 
        cd++; 
    }
    else if (atual == ')') {
        ptd++;
    }
    else  if ((atual == '[')) {
        if (cd ==0){
            return 0;
        }
        ce++;
    }

    else  if ((atual == '(')) {
        if (ptd ==0){
            return 0;
        }
        pte++;
    }
    }
return ( cd==ce && ptd==pte);
}

void ler(Pilha *p) {
    int x;
    char string[MAX];
    scanf("%d", &x);
    getchar();

    for (int i=0; i<x; i++) {
        fgets(string, MAX, stdin);
        int j = strlen(string);
    
    for (int m=0; m<j; m++) {
        push(p, string[m]);
    }
    printf(balanceamento(p,j) ? "Yes\n" : "No\n");
    }
}

int main () {

Pilha p;
criar(&p);
ler(&p);

}
