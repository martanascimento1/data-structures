#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 50

typedef struct fila {
    ITEM vet[TAM];
    int front, rear;
} TFila;

typedef struct filaprio {
    TFila f1, f2, f3;
} TFilaPrio;

void create(TFila *f) {
	f->front = f->rear = 0;
}

void destroy(TFila *f) {
	f->front = f->rear;
}

int next(int n) {
    return (n + 1) % TAM;
}

int isfull(TFila *f) {
	return next(f->rear + 1) == f->front;
}

int isempty(TFila *f) {
	return f->front == f->rear;
}

void store(TFila *f, ITEM x) {
    if( isfull(f) ) {
        puts("overflow");
        abort();
    }
    f->vet[f->rear] = x;
    f->rear = next(f->rear);
}

ITEM retrieve(TFila *f) {
    if( isempty(f) ) {
        puts("underflow");
        abort();
    }
    ITEM aux = f->vet[f->front];
    f->front = next(f->front);
    return aux;
}

void createfp(TFilaPrio *fp) {
	create(&fp->f1);
    create(&fp->f2);
    create(&fp->f3);
}

void destroyfp(TFilaPrio *fp) {
    destroy(&fp->f1);
    destroy(&fp->f2);
    destroy(&fp->f3);
}

int isemptyfp(TFilaPrio *fp, int prio) {
	TFila *filas[3] = {&fp->f1, &fp->f2, &fp->f3};
    if (prio < 1 || prio > 3) {
        puts("Prioridade inválida");
        abort();
    }
    return isempty(filas[prio - 1]);
}

void storefp(TFilaPrio *fp, int prio, ITEM x) {
	TFila *filas[3] = {&fp->f1, &fp->f2, &fp->f3};
    if (prio < 1 || prio > 3) {
        puts("Prioridade inválida");
        abort();
    }
    store(filas[prio - 1], x);
}

ITEM retrievefp(TFilaPrio *fp, int prio) {
	TFila *filas[3] = {&fp->f1, &fp->f2, &fp->f3};
    if (prio < 1 || prio > 3) {
        puts("Prioridade inválida");
        abort();
    }
    return retrieve(filas[prio - 1]); }

void preenche(TFilaPrio *fp) {
    ITEM x;
    int prio, qtd, i;

    scanf("%d%*c", &qtd);

    for( i=0; i<qtd; i++ ) {
        scanf("%c %d%*c", &x, &prio);
        storefp(fp, prio, x);
    }
}

void exibe(TFilaPrio *fp) {
    int i;
    for( i=1; i<=3; i++ ) {
        printf("PRIORIDADE %d =", i);
        while( !isemptyfp(fp, i) )
            printf(" %c", retrievefp(fp, i));
        putchar('\n');
    }
}

int main(void) {
    TFilaPrio fp;

    createfp(&fp);
    preenche(&fp);
    exibe(&fp);
    destroyfp(&fp);

    return 0;
}