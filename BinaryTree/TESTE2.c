#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Estrutura da árvore binária
typedef struct binary_tree {
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
} binary_tree;

// Função para criar um novo nó da árvore
binary_tree* create(int item) {
    binary_tree* new_node = (binary_tree*) malloc(sizeof(binary_tree));
    new_node->item = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Função para construir a árvore binária a partir da string
binary_tree* scanTree(char* str, int* index) {
    if (str[*index] == '(' && str[*index + 1] == ')') {
        *index += 2;
        return NULL;
    } else if (str[*index] == '(') {
        (*index)++;
    }

    char number_buffer[100];
    int j = 0;
    
    while (str[*index] != '(' && str[*index] != ')') {
        if (str[*index] != ' ') {
            number_buffer[j++] = str[*index];
        }
        (*index)++;
    }
    
    number_buffer[j] = '\0';
    int num = atoi(number_buffer);

    binary_tree* new_binary_tree = create(num);

    if (str[*index] == '(') {
        (*index)++;
        new_binary_tree->left = scanTree(str, index);
        while (str[*index] != ')') {
            (*index)++;
        }
        (*index)++;
    }

    if (str[*index] == '(') {
        (*index)++;
        new_binary_tree->right = scanTree(str, index);
        while (str[*index] != ')') {
            (*index)++;
        }
        (*index)++;
    }

    return new_binary_tree;
}
// Função que verifica se a árvore é uma árvore binária de busca
int isTree(binary_tree* node, int min, int max) {
    if (node == NULL) {
        return 1;  // Uma árvore vazia é uma árvore binária de busca
    }

    // Verifica se o valor do nó está dentro dos limites permitidos
    if (node->item < min || node->item > max) {
    return 0;
}

return isTree(node->left, min, node->item - 1) && 
       isTree(node->right, node->item + 1, max);
}

int main() {
    char tree[1000];
    fgets(tree, 1000, stdin);  // Lê a árvore como uma string

   int i = 0;
binary_tree* root = scanTree(tree, &i);

if (isTree(root, INT_MIN, INT_MAX)) {
    printf("VERDADEIRO\n");
} else {
    printf("FALSO\n");
}

    return 0;
}

