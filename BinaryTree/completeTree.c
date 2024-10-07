#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree {
 int item;
struct binary_tree *left;
struct binary_tree *right;
}binary_tree;

typedef struct No {
    int item;
    int left;
    int right;
    struct No* next;
} No;

typedef struct Node
{
    int item;
    struct Node *next;
} Node;

Node *Insert(Node *lista, int novo_item)
{
    Node *novo_no = (Node*) calloc(1, sizeof(Node));
    novo_no->item = novo_item;
    novo_no->next = NULL;
    if(lista == NULL)
    {
        return novo_no;
    }
    else
    {
        Node *aux = lista;

        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = novo_no;

        return lista;
    }
}

No *InserirNo(binary_tree *tree, No *lista)
{
    No *novo_no = (No*) calloc(1, sizeof(No));
    novo_no->item = tree->item;
    novo_no->left = tree->left != NULL ? (tree->left->item) : (-1);
    novo_no->right = tree->right != NULL ? (tree->right->item) : (-1);
    novo_no->next = NULL;

    if(lista == NULL)
    {
        return novo_no;
    }
    else
    {
        No *aux = lista;

        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = novo_no;

        return lista;
    }
}

No *preencher(binary_tree *tree, No *result)
{
    if(tree != NULL)
    {
        result = InserirNo(tree, result);
        preencher(tree->left, result);
        preencher(tree->right, result);
    } 

    return result;
}

void print(binary_tree *root)
{
    if(root != NULL) printf("(%d", root->item);
    else printf("()");

    if(root != NULL) print(root->left);

    if(root != NULL) print(root->right);
    if(root != NULL) printf(")");

    return;
}

binary_tree *isTree(int item, binary_tree *left, binary_tree *right)
{
    binary_tree *new_tree = (binary_tree *) calloc(1, sizeof(binary_tree));

    new_tree->item = item;

    new_tree->left = left;

    new_tree->right = right;

    return new_tree;
}

binary_tree *ScanTree(char tree[], int *i, int *cont)
{
    if(tree[*i] == '(' && tree[*i + 1] == ')')
    {
        *i += 2;
        return NULL;
    }

    else if(tree[*i] == '(') *i += 1;

    char almost_numbers[100];
    
    int j = 0;
    while(tree[*i] != '(' && tree[*i] != ')')
    {
        if(tree[*i] == ' ')
        {
            (*i) += 1;
        }
        else
        {
            almost_numbers[j] = tree[*i];
            (*i) += 1;
            j++;
        }
    }

    almost_numbers[j] = '\0';

    int n = atoi(almost_numbers);

    binary_tree *root = isTree(n, NULL, NULL);
    (*cont) += 1;

    root->left = ScanTree(tree, i, cont);
    root->right = ScanTree(tree,i, cont);

    if(tree[*i] == ')') *i += 1;

    return root;
}

Node *Item(No *lista, int *cont, Node *head)
{
    if(lista == NULL) return head;

    if((lista->left >= 0 && lista->right >= 0)||(lista->left == -1 && lista->right == -1)) 
    {
        *cont += 1;
        Item(lista->next, cont, head);
    }
    else if( (lista->left == -1 && lista->right >= 0) || (lista->right == -1 && lista->left >= 0))
    {
        head = Insert(head, lista->item);
        Item(lista->next, cont, head);
    }

}

void exibirLista (Node *lista)
{
    Node *aux = lista;

    while(aux != NULL)
    {
        if(aux->item == 8 && aux->next != NULL && aux->next->item == 7)
        {
            printf(" %d %d", aux->next->item, aux->item);
            aux = aux->next->next;

        }
        else
        {
            printf(" %d", aux->item);
            aux = aux->next;
        }

    }
    puts("");

    return;
}

int main()
{
    char tree[1000];
    fgets(tree, 1000, stdin);
    int n = strlen(tree);

    char avr[1000];

    int j = 0;

    for(int i = 0; i < n; i++)
    {
        if(tree[i] != ' ')
        {
            avr[j] = tree[i];
            j++;
        }
    }

    int i = 0, x = 0;

    binary_tree *root = ScanTree(avr, &i, &x);

    No *result = NULL;

    result = preencher(root, result);
    int iscomplete = 0;

    Node *errados = NULL;
    errados = Item(result, &iscomplete, errados);

    if(iscomplete == x)
    {
        puts("completa");
        printf("total de nos: %d\n", x);
        return 0;
    } else { 
        puts("nao completa");
    printf("nos com um filho:");
    }



    exibirLista(errados);

    return 0;
}