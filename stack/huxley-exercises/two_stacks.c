#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 50

typedef struct pilha_dupla {
    ITEM vet[TAM];
    int topo1, topo2;
} TPilhaDupla;

void create(TPilhaDupla *pd) {
    pd->topo1 = -1;
    pd->topo2 = TAM;
}

void destroy(TPilhaDupla *pd) {
	pd->topo1 = -1;
    pd->topo2 = TAM;
}

int isfull(TPilhaDupla *pd) {
    return pd->topo1 +1 == pd->topo2;
}

int isempty(TPilhaDupla *pd, int topo) {
	return (topo ==1 && pd->topo1 == -1) || (topo == 2 && pd->topo2 == TAM);
    }


void push(TPilhaDupla *pd, ITEM x, int topo) {
	if(isfull(pd))
    {
       return;
    }

    if(topo == 1)
    {
        pd->topo1++;
        pd->vet[pd->topo1] = x;
    }
    else
    {
        pd->topo2--;
        pd->vet[pd->topo2] = x;
    }

}

ITEM pop(TPilhaDupla *pd, int topo) {
	if(isempty(pd, topo))
    {
       return;
    }

    char x;
    if(topo == 1)
    {
        x = pd->vet[pd->topo1];
        pd->topo1--;
    }
    if(topo == 2)
    {
        x = pd->vet[pd->topo2];
        pd->topo2++;
    }

    return x;
    }

ITEM top(TPilhaDupla *pd, int topo) {
   if (topo == 1) {
       if (pd->topo1 >= 0) {
           return pd->vet[pd->topo1];
       }
       
   }
   else if (topo == 2) {
       if (pd->topo2 < TAM) {
           return pd->vet[pd->topo2];
       }
       
   }}
   
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
