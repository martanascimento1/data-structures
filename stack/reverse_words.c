#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 100

typedef struct pilha {
    ITEM vet[TAM];
    int topo;
} TPilha;

void create(TPilha *p) {
    p->topo = -1;
}

void destroy(TPilha *p) {
    p->topo = -1;
}

int isfull(TPilha *p) {
    return p->topo == TAM;
}

int isempty(TPilha *p) {
    return p->topo == -1;
}

void push(TPilha *p, ITEM x) {
    if( isfull(p) ) {
        puts("overflow");
        abort();
    }
    p->topo++;
    p->vet[p->topo] = x;
}

ITEM pop(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    ITEM x = p->vet[p->topo];
    p->topo--;
    return x;
}

ITEM top(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    return p->vet[p->topo];
}

void inverte_palavras_frase(char frase[]) {
	 
    TPilha p;
    create(&p);
    int i = 0, j = 0;
    char fraseInvertida[TAM] = "";
        while (frase[i] != '\0') {
        if (frase[i] != ' ') {
            push(&p, frase[i]);
        } else {
            while (!isempty(&p)) {
                fraseInvertida[j++] = pop(&p);
            }
            fraseInvertida[j++] = ' ';
        }
        i++;
    }
    while (!isempty(&p)) {
        fraseInvertida[j++] = pop(&p);
    }
    fraseInvertida[j] = '\0'; // termina a string

    // Copia a frase invertida de volta para a frase original
    strcpy(frase, fraseInvertida);
}

int main(void) {
    char frase[TAM];

    gets(frase);
    printf("original = %s\n", frase);
    inverte_palavras_frase(frase);
    printf("invertida = %s\n", frase);
    
    return 0;
}
