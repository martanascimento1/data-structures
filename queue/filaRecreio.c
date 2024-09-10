#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    struct _node *prev;
    int item;
    struct _node *next;
} node;

typedef struct _queue
{
    node *front;
    node *rear;
    int size;
} queue;

node *create_node(int item)
{
    node *new_node = (node *) calloc(1, sizeof(node));

    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->item = item;

    return new_node;
}

queue *create_queue()
{
    queue *new_queue = (queue *) calloc(1, sizeof(queue));

    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;

    return new_queue;
}

int empty(queue *queue)
{
    return queue->size == 0;
}

void dequeue(queue *queue)
{
    if (!empty(queue))
    {
        node *aux = queue->front;
        queue->front = aux->next;

        if (queue->front != NULL) {
            queue->front->prev = NULL;
        }
        else
        {
            queue->rear = NULL;
        }
        free(aux);
        queue->size--;
    }
}

void enqueue(queue *queue, int item) 
{
    node *new_node = create_node(item);

    if (empty(queue))
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else 
    {
        new_node->prev = queue->rear;
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
}

node *bubblesortlinkedlist(node *head)
{
    node *aux = head;
    int swapped = 1, item;

    while(swapped != 0)
    {
        swapped = 0;

        while(aux->next != NULL)
        {
            if(aux->item < (aux->next)->item)
            {
                int aux1 = aux->item;
                aux->item = (aux->next)->item;
                (aux->next)->item = aux1;
                swapped++;
            }
            
            aux = aux->next;
        }

        aux = head;
    }

    return head;
}

queue *copylinkedlist(node *head)
{
    queue *result = create_queue();

    while(head != NULL)
    {
        enqueue(result, head->item);
        head = head->next;
    }

    return result;
}

int comparar(node *original, node *result)
{
    int cont = 0;

    while(original != NULL && result != NULL)
    {
        if(original->item == result->item) cont++;

        original = original->next;
        result = result->next;
    }

    return cont;
}

void print(queue *queue) {
    node *current = queue->front;
    while (current != NULL)
    {
        printf("%d", current->item);

        printf(current->next == NULL ? "\n" : " ");

        current = current->next;
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        queue *head = create_queue();

        for( int j = 0; j < m; j++)
        {
            int item;
            scanf("%d", &item);
            enqueue(head, item);
        }

        //print(head);

        queue *result = copylinkedlist(head->front);
        //fazer o bubble sort da linked list aqui

        //print(result);
        
        result->front = bubblesortlinkedlist(result->front);

        //print(result);
        
        int cont = comparar(head->front, result->front); //cont = comparar;
        //comparar a lista ordenada e a lista original
        //para descobrir quantas mudanças de posição houveram

        printf("%d\n", cont);
    }

    return 0;
}