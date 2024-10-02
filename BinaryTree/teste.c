#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} TreeNode;

TreeNode *createNode(int data) {
    TreeNode *newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode *insertBST(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else {
        root->right = insertBST(root->right, data);
    }

    return root;
}

void printTree(TreeNode* node) {
    if (node == NULL) {
        printf(" () ");
    } else {
        printf(" ( %d ", node->data);
        printTree(node->left);
        printTree(node->right);
        printf(") ");
    }
}

int main() {
    TreeNode *treeRoot = NULL;
    int insertedValue;

    while (scanf("%d", &insertedValue) != EOF) {
        printf("----\n");
        printf("Adicionando %d\n", insertedValue);
        printf("  ");
        treeRoot = insertBST(treeRoot, insertedValue);
        printTree(treeRoot);
        printf("\n");
    }

    printf("----\n");
    return 0;
}