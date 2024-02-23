#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int item;
    struct No* next;
}No;

struct No* criarNo(int item) {
    struct No* novo_no = (struct No*) malloc(sizeof(No));
    novo_no->item = item;
    novo_no->next = NULL;
    return novo_no;
}

void inserir( No** lista, int item) {
    No* novo_no = criarNo(item);
    novo_no->next = *lista;
    *lista = novo_no;
}

struct No* somarLista(No* l1, No* l2) {
    int soma;
    No* res = NULL;
    No *temp, *prev = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        soma = carry + (l1? l1->item: 0) + (l2? l2->item: 0);
        carry = (soma >= 10)? 1 : 0;
        soma = soma % 10;
        temp = criarNo(soma);
        if (res == NULL) res = temp;
        else prev->next = temp;
        prev = temp;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    if (carry > 0) temp->next = criarNo(carry);

    return res;
}

struct No* inverterLista(No* lista) {
    No* anterior = NULL;
    No* atual = lista;
    No* next = NULL;
    while (atual != NULL) {
        next = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = next;
    }
     lista = anterior;
    return lista;
}

void exibirLista(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    int n = 1;
    while (lista != NULL) {
        if (lista->item != 0 || !n) {
            printf("%d ", lista->item);
            n = 0;
        }
        lista = lista->next;
    }
    printf("\n");
}
int main() {
     No* l1 = NULL;
     No* l2 = NULL;
     No* res = NULL;
    int n;

    while (scanf("%d", &n) == 1 && n != '+') {
        inserir(&l1, n);
    }

    while (scanf("%d", &n) == 1 && n != '=') {
        inserir(&l2, n);
    }

    res = somarLista(l1, l2);
    res = inverterLista(res);
    exibirLista(res);

    return 0;
}
