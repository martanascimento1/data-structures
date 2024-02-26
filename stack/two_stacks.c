#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 50

typedef struct pilha_dupla {
    ITEM vet[TAM];
    int topo1, topo2;
} TPilhaDupla;

void create(TPilhaDupla *pd) {
	TPilhaDupla *p = (TPilhaDupla*)malloc(sizeof(TPilhaDupla));
    pd->topo1 = -1;
    pd->topo2 = TAM;
}

void destroy(TPilhaDupla *pd) {
	//Insira o código aqui
}

int isfull(TPilhaDupla *pd) {
}

int isempty(TPilhaDupla *pd, int topo) {
	//Insira o código aqui
}

void push(TPilhaDupla *pd, ITEM x, int topo) {
	if (pd->topo1 < pd->topo2 -1) {
        if (topo == 1) {
            pd->topo1++;
            pd->vet[pd->topo1] = x;
        }
        else if (topo == 2){
            pd->topo2--;
            pd->vet[pd->topo2] = x;
        }
    }
}

ITEM pop(TPilhaDupla *pd, int topo) {
	if (topo == 1) {
        if (pd->topo1 >= 0) {
            int x = pd->vet[pd->topo1];
            pd->topo1--;
            return x;
        }
        else {
            exit(EXIT_FAILURE);
        } }
        else if (topo == 2 ) {
            if (pd->topo2 < TAM) {
            int x = pd->vet[pd->topo2];
            pd->topo2++;
            return x;
            }
            else {
            exit(EXIT_FAILURE);
        }
        }
        return -1;
    }

ITEM top(TPilhaDupla *pd, int topo) {
	
}
void preenche(TPilhaDupla *pd) {
    ITEM x;
    int topo, qtd, i;

    scanf("%d%*c", &qtd);

    for( i=0; i<qtd; i++ ) {
        scanf("%c %d%*c", &x, &topo);
        push(pd, x, topo);
    }
}

void exibe(TPilhaDupla *pd) {
    int topo;

    while( scanf("%d", &topo) != EOF )
        printf("TOPO %d = %c\n", topo, pop(pd, topo));
}

int main(void) {
    TPilhaDupla pd;

    create(&pd);
    preenche(&pd);
    exibe(&pd);
    destroy(&pd);

    return 0;
}
