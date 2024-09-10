#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct  No *prox;
    
}No;

typedef struct Pilha
{
   No *topo;
}Pilha;

void inicializaPilha (Pilha *p) {
    p->topo = NULL;
}

void empilhar (int dado, Pilha *p) {
    No *ptr = (No*) malloc(sizeof(No));
    if(ptr == NULL) {
        printf("erro\n");
    }
    else {
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}

void desempilhar (Pilha *p) {
    No* ptr = p->topo;
    int dado;
    if (ptr == NULL) {
        printf("pilha vazia\n");
        return;
     } else {
        p->topo = ptr->prox;
        ptr->prox = NULL; 
        dado = ptr->dado;
        free(ptr);
        return dado;
     }
}

void imprimirPilha (Pilha *p) {
    No *ptr = p->topo;
    if (ptr == NULL) {
        printf("pilha vazia\n");
        return;
    }  else {
        while (ptr != NULL)
        {
            printf("%d", ptr->dado);
            ptr = ptr->prox;
        }

       printf("/n"); 
    }
}
int main () {

    Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
    if (p1== NULL) {
        printf("erro de alocação\n");
        exit(0);
    } else {
        inicializaPilha(p1);
        empilhar(10, p1);
        empilhar(20, p1);
        empilhar(30, p1);
        imprimirPilha(p1);

        desempilhar(p1);
        imprimirPilha(p1);
        desempilhar(p1);
        imprimirPilha(p1);
        desempilhar(p1);


    }
}