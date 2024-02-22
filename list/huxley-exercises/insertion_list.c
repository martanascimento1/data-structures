#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
} LISTA;

void inicializar(LISTA *l)
{
    l->cabeca = NULL;
}

NO* criarNo(ITEM item, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    pNovo->item = item;
    pNovo->prox = prox;
    return pNovo;
}


int tamanho(LISTA *l)
{
    NO* p = l->cabeca;
    int tam = 0;
    while (p)  // p != NULL
    {
        tam++;
        p = p->prox;
    }
    return tam;
}


bool vazia(LISTA *l)
{
    return l->cabeca == NULL;
}


// Exibicao da lista sequencial
void exibirLista(LISTA *l)
{
    NO* p = l->cabeca;
    while (p)  
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->prox;
    }
}

void destruir(LISTA *l)
{
    NO* atual = l->cabeca;
    while (atual) {
        NO* prox = atual->prox; 
        free(atual);         
        atual = prox;
    }
    l->cabeca = NULL; 
}


void imprimirLista(LISTA *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}

bool inserirNaOrdem(ITEM item, LISTA *l)
{
    LISTA *atual = l;
    NO *aux = NULL;
    NO *novo = criarNo(item, NULL);

    if (vazia(l))
    {
        atual->cabeca = novo; 
        atual->cabeca->prox = NULL;
        return true;
    }
    
    if (atual->cabeca->item.chave > item.chave) {
        novo->prox = atual->cabeca;
        atual->cabeca = novo;

        return true;
    }

    aux = atual->cabeca;

    while (aux->prox != NULL)
    {
        if (aux->prox->item.chave > item.chave) {
            break;
        }
        aux = aux->prox;

    }


    if (aux->item.chave == novo->item.chave)
    {
        free(novo); 
        return false; 
    }

    novo->prox = aux->prox;
    aux->prox = novo;

    return true;
}

//////////////////////////////////////////////////////////////


void lerItens(LISTA *l)
{
    int n;
    scanf("%d", &n);

    // insere os valores n pares chave,valor
    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        inserirNaOrdem(item, l);
    }
}


int main(){
  LISTA l;
  ITEM item;

  inicializar(&l);

  lerItens(&l);
  imprimirLista(&l);
    
  lerItens(&l);
  imprimirLista(&l);

  destruir(&l);
  return 0;
}