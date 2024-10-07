#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct binary_tree {
 int item;
 int p;
 struct binary_tree *left;
 struct binary_tree *right;
}binary_tree;

binary_tree* create_binary_tree( int item, binary_tree *left, binary_tree *right)
{
 binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
 new_binary_tree->item = item;
 new_binary_tree->left = left;
 new_binary_tree->right = right;

 return new_binary_tree;
}

binary_tree* scanTree(char str[], int* x) {
   if (str[*x] == '(') {
        (*x)++;

        if (str[*x] == ')') {
            (*x)++;
            return NULL;
        }

        char n[1000];
        int j = 0;
        while (str[*x] >= '0' && str[*x] <= '9') {
            n[j] = str[*x];
            (*x)++;
            j++;
        }
        n[j] = '\0';
        int item = atoi(n);

        binary_tree* new_binary_tree = create_binary_tree(item, NULL, NULL);

        if (str[*x] == '(') {
            new_binary_tree->left = scanTree(str, x);
        }

        if (str[*x] == '(') {
            new_binary_tree->right = scanTree(str, x);
        }

        (*x)++;
        return new_binary_tree;
    }

    return NULL;
}

void deptH(binary_tree* tree , int i) {
    if (tree == NULL)
        return;
    tree->p = i;
    deptH(tree->left, i + 1);
    deptH(tree->right, i + 1);
}

binary_tree* calculateDepth(binary_tree* tree, int item) {
    if (tree == NULL || tree->item == item) {
        return tree;
    }
    binary_tree* i = NULL;
    if (i == NULL && tree->left != NULL) {
        i = calculateDepth(tree->left, item);
    }
    if (i == NULL && tree->right != NULL) {
        i = calculateDepth(tree->right, item);
    }
    return i;
}

int main() {
    binary_tree* tree, *node;
    char string[100];
    int valor = 0;
    int* x = &valor;

    fgets(string, sizeof(string), stdin);
    int no;
    scanf("%d", &no);

    tree = scanTree(string, x);
    deptH(tree, 0);
    node = calculateDepth(tree, no);

    if (node == NULL) {
        printf("NAO ESTA NA ARVORE\n");
        printf("-1\n");
    } else {
        printf("ESTA NA ARVORE\n");
        printf("%d\n", node->p);
    }

    return 0;
}