#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

// Estrutura de nó da árvore binária
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó da árvore
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para construir a árvore binária a partir da string de entrada
struct Node* buildTree(char* str, int* index) {
    // Caso base: se o índice for inválido ou o caractere atual não for um número, retorne NULL
    if (str[*index] == '\0' || str[*index] == ')') {
        return NULL;
    }

    // Parse do número atual (pode ter mais de um dígito)
    int num = 0;
    int sign = 1;
    if (str[*index] == '-') {  // Verifica se o número é negativo
        sign = -1;
        (*index)++;
    }
    while (isdigit(str[*index])) {
        num = num * 10 + (str[*index] - '0');
        (*index)++;
    }
    num *= sign;

    // Cria o nó com o valor lido
    struct Node* node = newNode(num);

    // Se o próximo caractere for '(', começamos a ler a subárvore esquerda
    if (str[*index] == '(') {
        (*index)++;  // Pula o '('
        node->left = buildTree(str, index);
        (*index)++;  // Pula o ')'
    }

    // Se o próximo caractere for '(', começamos a ler a subárvore direita
    if (str[*index] == '(') {
        (*index)++;  // Pula o '('
        node->right = buildTree(str, index);
        (*index)++;  // Pula o ')'
    }

    return node;
}

// Função auxiliar recursiva para verificar se a árvore é uma árvore de busca binária
int isBSTUtil(struct Node* node, int min, int max) {
    if (node == NULL)
        return 1;

    if (node->data <= min || node->data >= max)
        return 0;

    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data, max);
}

// Função para verificar se a árvore é uma árvore de busca binária
int isBST(struct Node* node) {
    return isBSTUtil(node, INT_MIN, INT_MAX);
}

// Programa principal
int main() {
    char input[1000];
    printf("Digite a árvore no formato (ex: 5(4(11(7()())(2()()))())(8(13()())(4()(1()())))): ");
    scanf("%s", input);

    int index = 0;
    struct Node* root = buildTree(input, &index);

    if (isBST(root))
        printf("A árvore é uma árvore de busca binária\n");
    else
        printf("A árvore NÃO é uma árvore de busca binária\n");

    return 0;
}
