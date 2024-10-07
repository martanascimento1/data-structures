#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node
{
    int value;
    struct tree_node *left_child;
    struct tree_node *right_child;
} tree_node;

tree_node *create_node(int value, tree_node *left_child, tree_node *right_child)
{
    tree_node *new_node = (tree_node*) malloc(sizeof(tree_node));
    new_node->value = value;
    new_node->left_child = left_child;
    new_node->right_child = right_child;

    return new_node;
}

int find_value(tree_node *tree, int target, tree_node **found_node)
{
    *found_node = tree;

    if (tree == NULL) return 0;

    if (tree->value == target) return 1;

    find_value(tree->left_child, target, found_node);
    find_value(tree->right_child, target, found_node);
   
    return find_value(tree->left_child, target, found_node) || find_value(tree->right_child, target, found_node);
}

tree_node *get_node(tree_node *tree, int target, tree_node **found_node)
{
    return find_value(tree, target, found_node) == 1 ? tree : NULL; 
}

tree_node *construct_tree(char input[], int *index)
{
    if (input[*index] == '(' && input[*index + 1] == ')')
    {
        *index += 2;
        return NULL;
    }
    else if (input[*index] == '(') *index += 1;

    char buffer[100];
    int j = 0;
    while (input[*index] != '(' && input[*index] != ')')
    {
        if (input[*index] == ' ')
        {
            (*index) += 1;
        }
        else
        {
            buffer[j] = input[*index];
            (*index) += 1;
            j++;
        }
    }

    buffer[j] = '\0';
    int number = atoi(buffer);
    tree_node *new_root = create_node(number, NULL, NULL);

    new_root->left_child = construct_tree(input, index);
    new_root->right_child = construct_tree(input, index);

    if (input[*index] == ')') *index += 1;

    return new_root;
}

void print_tree(tree_node *root)
{
    if (root != NULL) printf("(%d", root->value);
    else printf("()");

    if (root != NULL) print_tree(root->left_child);
    if (root != NULL) print_tree(root->right_child);
    if (root != NULL) printf(")");

    return;
}

int main()
{
    char input_buffer[1000];
    fgets(input_buffer, 1000, stdin);

    int length = strlen(input_buffer);
    int j = 0;
    char cleaned_input[1000];

    for (int i = 0; i < length; i++)
    {
        if (input_buffer[i] != ' ')
        {
            cleaned_input[j] = input_buffer[i];
            j++;
        }
    }

    int i = 0;
    tree_node *root = construct_tree(cleaned_input, &i);

    while (1)
    {
        char query_buffer[1000];
        fgets(query_buffer, 1000, stdin);
        int n = strlen(query_buffer);

        if (n <= 3) break;

        char cleaned_query[1000];
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (query_buffer[i] != ' ')
            {
                cleaned_query[j] = query_buffer[i];
                j++;
            }
        }

        int i2 = 0;
        tree_node *aux_root = construct_tree(cleaned_query, &i2);
        int searched_value = aux_root->value;

        tree_node *found_node = NULL;
        tree_node *result_node = get_node(root, searched_value, &found_node);

        printf("%d\n\n\n\n", found_node->value);

        found_node = aux_root;

        printf("%d\n\n\n\n", found_node->left_child->value);
    }

    print_tree(root);
    puts("");
    
    return 0;
}
