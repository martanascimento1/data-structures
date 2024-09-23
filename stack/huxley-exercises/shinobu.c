#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack() {
     STACK *new_stack = (STACK*) calloc(1, sizeof(STACK));
    
    new_stack->head = NULL;
    
    return new_stack;
}

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element) {
     NODE *new_node = calloc(1, sizeof(NODE));

    new_node->element = element;


    return new_node;
}

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack) {
    return stack->head == -1;
}

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack) {
      if(IS_EMPTY(stack))
    {
        puts("Underflow");
        abort();
    }
    
    NODE *aux = stack->head;

    stack->head = aux->next;

    return aux->element;
}


void PUSH(STACK* stack, int element) {
     NODE *new_node = create_node(element);
    
    new_node->next = stack->head;

    stack->head = new_node;

    return;
}


void result(STACK* stack, char operation) {
    int v1 = POP(stack);
    int v2 = POP(stack);
    int resultado;

    if (operation =='*') {
        resultado = v2 * v1;
    }
    if (operation == '+') {
        resultado = v2 + v1;
    }
    if (operation == '/') {
        resultado = v2 / v1;
    }
    if (operation == '-') {
        resultado = v2 - v1;
    }

    PUSH(stack, resultado);
}


void Calculadora(STACK* calculadora, int size) {

    for(int i = 0; i < size; i++)
    {
        char operacao[50];
        scanf("%s", operacao);

        if(operacao[0] == '+' || operacao[0] == '-' || operacao[0] == '/' || operacao[0] == '*')
        {
            result(calculadora,operacao[0]);
        }
        else
        {
            int item = atoi(operacao);
            PUSH(calculadora,item);
        }
} }

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
//Insira o código aqui