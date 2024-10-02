#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct binary_tree {
 int item;
 struct binary_tree *left;
 struct binary_tree *right;
}binary_tree;

binary_tree* create_empty_binary_tree()
{
 return NULL;
}
binary_tree* create_binary_tree(int item) {

 binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
 new_binary_tree->item = item;
 new_binary_tree->left = new_binary_tree->right = NULL;

 return new_binary_tree;
}

binary_tree* isTree(binary_tree* root, int item) {

    if (root == NULL) {
        return create_binary_tree(item);
    }

    if (item < root->item) {
         root->left = isTree(root->left, item);
    } 
    else {
        root->right = isTree(root->right, item);
    }

    return root;
} 

void print(binary_tree *bt)
{
     if (bt == NULL)  printf(" () ");

    else {
        printf(" ( %d ", bt->item);
        print(bt->left);
        print(bt->right);
        printf(") ");
    }
 
 } 
 int main() {
    int item;
    binary_tree *root = create_empty_binary_tree();

    while (scanf("%d", &item) != EOF) {
        printf("----\n");
        printf("Adicionando %d\n", item);
        printf("  ");
        root = isTree(root, item);
        print(root);
        printf("\n");
    }

    printf("----\n");
    return 0;
}