#include <stdlib.h>
#include <stdio.h>
typedef struct Node{
    int item;
    struct Node *proximo;
}Node;

typedef struct 
{
    Node *inicio;
    int tam;
} List;

//inserção no início da lista
void insertInit (List  *lista, int item) {
   Node *new = (Node*)malloc(sizeof(Node));
   new -> item = item;
   new -> proximo = lista -> inicio;
   lista->inicio = new;
   lista->tam++;

}
// inserção no final da lista 

// imprimir a lista
void imprimir (List *lista) {
    Node *inicio = lista -> inicio;
    printf("mostrar %d\n", lista->tam);
    while (inicio != NULL)
    {
        printf(" %d ", inicio->item);
        inicio = inicio->item;
    }
    printf("\n\n");
}
 int main () {

    int op, valor;
    List lista;
    lista.inicio = NULL;
    lista.tam = 0;
     do {
        printf("1 - inserir no inicio\n2 - imprimir\n3 - sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        printf("insira o valor:\n"); 
        scanf("%d", &valor);
        insertInit(&lista, valor);
            break;

        case 2:
        imprimir(&lista);
            break;
        
        case 3:
        printf("finalizando\n");
        break;
        default:
        printf("opção inválida\n");
        }
        
     } while (op != 3);
     
    return 0;
 }