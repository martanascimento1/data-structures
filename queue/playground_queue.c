#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    struct No *prev;
    int item;
    struct No *next;
} No;

typedef struct Queue
{
    No *front;
    No *rear;
    int size;
} Queue;

No *Novo_no(int item)
{
    No *novo_no = (No *) calloc(1, sizeof(No));

    novo_no->prev = NULL;
    novo_no->next = NULL;
    novo_no->item = item;

    return novo_no;
}

Queue *Fila()
{
    Queue *fila = (Queue *) calloc(1, sizeof(Queue));

    fila->front = NULL;
    fila->rear = NULL;
    fila->size = 0;

    return fila;
}

int Isempty(Queue *queue)
{
    return queue->size == 0;
}

void Dequeue(Queue *queue)
{
    if (!Isempty(queue))
    {
        No *aux = queue->front;
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

void Enqueue(Queue *queue, int item) 
{
    No *novo_no = Novo_no(item);

    if (Isempty(queue))
    {
        queue->front = novo_no;
        queue->rear = novo_no;
    }
    else 
    {
        novo_no->prev = queue->rear;
        queue->rear->next = novo_no;
        queue->rear = novo_no;
    }

    queue->size++;
}

No *ordenar(No *head)
{
    No *aux = head;
    int swapped = 1;

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

Queue *transferir(No *head)
{
    Queue *result = Fila();

    while(head != NULL)
    {
        Enqueue(result, head->item);
        head = head->next;
    }

    return result;
}

int comparar(No *original, No *result)
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

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        Queue *head = Fila();

        for( int j = 0; j < m; j++)
        {
            int item;
            scanf("%d", &item);
            Enqueue(head, item);
        }

        Queue *result = transferir(head->front);
        result->front = ordenar(result->front);
        int cont = comparar(head->front, result->front); 

        printf("%d\n", cont);
    }

    return 0;
}