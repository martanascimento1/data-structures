#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 256

typedef struct no {
    unsigned char c;
    int frequencia;
    struct no *esq, *dir, *prox;
} No;

typedef struct lista {
    No *inicio;
    No *fim;
    int tam;
} Lista;

//PARTE 1 - Inicialização da tabela de frequência
void inicializa_tabela_com_zero (unsigned int tab[]) {
    for (int i = 0; i < MAX; i++) {
        tab[i] = 0;
    }
}

void preenche_tab_freq (unsigned char texto[], unsigned int tab[]) {
    int i = 0;
    while (texto[i] != '\0') {
        tab[texto[i]]++;
        i++;
    }
}

void imprime_tab_freq (unsigned int tab[]) {
    for (int i = 0; i < MAX; i++) {
        if (tab[i] != 0) {
            printf("%d = %u = %c\n", i, tab [i], i);
    } }
}

//PARTE 2 - Criação da lista encadeada ordenada
void criar_lista (Lista *lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}
void inserir(Lista *lista, No *novo) {
    No *aux;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    }
     else if (novo->frequencia < lista->inicio->frequencia) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }
    else {
        aux = lista->inicio;
        while (aux->prox != NULL && aux->prox->frequencia <= novo->frequencia) {
            aux = aux->prox;

       novo->prox = aux->prox;
       aux->prox = novo;
        }
    }
    lista->tam++;
}

void preencher_lista (unsigned int tab[], Lista *lista) {
    No *novo;
    for (int i = 0; i < MAX; i++) {
        if (tab[i] > 0) {
            novo = (No *) malloc(sizeof(No));
            if (novo) {
            novo->c = i;
            novo->frequencia = tab[i];
            novo->esq = NULL;
            novo->dir = NULL;
            novo->prox = NULL;
            inserir(lista, novo);
            }
            else {
                printf("Erro de alocação\n");
                break;
            }
        }
    }
}

void imprimir_lista (Lista *lista) {
    No *aux;
    aux = lista->inicio;
    while (aux != NULL) {
        printf("Caracter: %c  Frequência = %d\n", aux->c, aux->frequencia);
        aux = aux->prox;
    }
}

//PARTE 3 - Criação da árvore de Huffman

No* remover_inicio(Lista *lista) {
    No *aux = NULL;
    if (lista->inicio) {
        aux = lista->inicio;
        lista->inicio = aux->prox;
        aux->prox = NULL;
        lista->tam--;
    }
    
    return aux;
}

No* criar_arvore(Lista *lista) {
    No *novo, *p, *seg;
    while (lista->tam > 1) {
        p = remover_inicio(lista);
        seg = remover_inicio(lista);
        novo = malloc(sizeof(No));
        if (novo) {
            novo->c = '*';
            novo->frequencia = p->frequencia + seg->frequencia;
            novo->esq = p;
            novo->dir = seg;
            novo->prox = NULL;
            inserir(lista, novo);
        }
        else {
            printf("Erro de alocação\n");
            break;
        }
    }
    return lista->inicio;
}

void imprimir_arvore(No *raiz, int tam) {
    if (raiz->esq == NULL && raiz->dir == NULL) {
        printf("%c", raiz->c);
        printf("\n altura = %d\n", tam);
    }
    else {
        imprimir_arvore(raiz->esq, tam+1);
        imprimir_arvore(raiz->dir, tam+1);
    
    }
}
int main () {
    unsigned char texto[] ="Vamos aprender a programa";
    unsigned int tab_freq[MAX];
    Lista lista;
    No *arvore;
    setlocale(LC_ALL, "Portuguese");
    
    //PARTE 1 - Inicialização da tabela de frequência
    inicializa_tabela_com_zero(tab_freq);
    preenche_tab_freq(texto, tab_freq);
    imprime_tab_freq(tab_freq);

    //PARTE 2 - Criação da lista encadeada ordenada
    criar_lista(&lista);
    preencher_lista(tab_freq, &lista);
    imprimir_lista(&lista);

    //PARTE 3 - Criação da árvore de Huffman
    arvore = criar_arvore(&lista);
    imprimir_arvore(arvore, 0);
  return 0;
}