#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct binary_tree {
 int item;
struct binary_tree *left;
struct binary_tree *right;
}binary_tree;

binary_tree* create_binary_tree( int item)
{
 binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
 new_binary_tree->item = item;
 new_binary_tree->left = NULL;
 new_binary_tree->right = NULL;

 return new_binary_tree;
}

int Max(int x, int y);

int levelsCalculate(binary_tree *root, int level, int *min, int *max) {
    if (root == NULL) {
        return 0;
    }


    if (root->item > max[level]) {
        max[level] = root->item;
    }
    if (root->item< min[level]) {
        min[level] = root->item;
    }

    int leftCount = levelsCalculate(root->left, level + 1, min, max);
    int rightCount = levelsCalculate(root->right, level + 1, min, max);
    
    return 1 + Max(leftCount, rightCount);
}

int Max(int x, int y) {
    return (x > y) ? x : y;
}
int main () {
    int n, value, fe, fd;
    scanf("%d", &n);

    int *min = malloc(n * sizeof(int));
    int *max = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        min[i] = INT_MAX;
        max[i] = INT_MIN;
    }

    binary_tree **nodes = malloc(n * sizeof(binary_tree));
    int leftChildren[n];
    int rightChildren[n];
    
    memset(&rightChildren, -1, sizeof(rightChildren));
    memset(&leftChildren, -1, sizeof(leftChildren));

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &value, &fe, &fd);

        nodes[i] = create_binary_tree(value);

        if (fe > 0)  {
            leftChildren[fe] = i;
        }
        if (fd > 0) {
             rightChildren[fd] = i;
    } }

    for (int i = 0; i < n; i++){
        if (leftChildren[i] != -1) nodes[leftChildren[i]]->left = nodes[i];
        if (rightChildren[i] != -1) nodes[rightChildren[i]]->right = nodes[i];
    }

    int height = levelsCalculate(nodes[0], 0, min, max);

      for(int i = 0; i < height; i++)
    {
        printf("Nivel %d: Maior = %d, Menor = %d\n", i + 1, max[i], min[i]);
    }
    
    free(min);
    free(max);
    free(nodes);

    return 0;
}
