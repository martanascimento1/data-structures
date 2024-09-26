#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct binary_tree {
 int item;
 binary_tree *left;
 binary_tree *right;
};

binary_tree* create_empty_binary_tree();

binary_tree* create_binary_tree( int item, binary_tree *left, binary_tree *right);

binary_tree* search(binary_tree *bt, int item);
int is_empty(binary_tree *bt);
void print_in_order(binary_tree *bt);
void print_pre_order(binary_tree *bt);
void print_post_order(binary_tree *bt);

binary_tree* create_empty_binary_tree()
{
 return NULL;
}

binary_tree* create_binary_tree(
 int item, binary_tree *left, binary_tree *right)
{
 binary_tree *new_binary_tree =
 (binary_tree*) malloc(sizeof(binary_tree));
 new_binary_tree->item = item;
 new_binary_tree->left = left;
 new_binary_tree->right = right;
 return new_binary_tree;
}

void print_in_order(binary_tree *bt)
{
 if (!is_empty(bt)) {
 print_in_order(bt->left);
 printf(“%d”, bt->item);
 print_in_order(bt->right);
 } }