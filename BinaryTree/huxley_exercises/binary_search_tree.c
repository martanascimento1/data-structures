#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct binary_tree {
 int item;
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

        printf("( %d", root->item);
        printtree(root->left);
        printtree(root->right);
        printf(")");
    }
}
/*binary_tree* create(int item) {
   struct binary_tree* new_binary_tree =
 (struct binary_tree*)malloc(sizeof(binary_tree));
    new_binary_tree->item = item;
    new_binary_tree->left = NULL;
    new_binary_tree->right = NULL;
    return new_binary_tree;
}

binary_tree* insert(binary_tree* root, int item) {
    if (root == NULL) {
        return create(item);
    }
    if (item < root->item) {
        root->item = insert(root->left, item);
    } else if (item > root->item) {
        root->right = insert(root->right, item);
    }
    return root;

}*/

int isTree(binary_tree* root, int min, int max) {
    if (root == NULL) {
        return 1;
    }

    if (root->item < min || root->item > max) {
        return 0;
    }

    return isTree(root->left, min, root->item - 1) &&
           isTree(root->right, root->item + 1, max);
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

int main () {

    char n[1000];
    binary_tree* tree;
    int i = 0;
    int* x = &i;
    int result;

   scanf("%s", n);
   tree = scanTree(n, x);
    result = isTree(tree, INT_MIN, INT_MAX);
    if (result == 1 )  printf("VERDADEIRO\n");
    else
        printf("FALSO\n");

    return 0;
}