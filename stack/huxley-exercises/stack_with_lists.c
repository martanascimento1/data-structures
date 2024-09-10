#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    int item;
    struct _node *next;
} node;

typedef struct _stacknode
{
    node *next;
    node *startlist;
} stacknode;

/*typedef struct _stack
{
    stacknode *top;
} stack;*/

stacknode *create_stack()
{
    return NULL;
}

node *createlinkedlist()
{
    return NULL;
}

stacknode *createstack()
{
    return NULL;
}

node *addnodefinal(node *head, int item)
{
    node *new_node = (node*) calloc(1, sizeof(node));
    new_node->item = item;
    //new_node->n = n;
    //my goal here is to add in the final of the list
    //new_node->next = head;
    new_node->next = NULL;

    //if I want to put the head in the start of the linked list, I must erase everything under this line and
    //just "return new_node;"
    if(head == NULL)
    {
        return new_node;
    }
    else
    {
        node *aux = head;

        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = new_node;

        return head;
    }
}

stacknode *addnodeinicio(stacknode *top)
{
    stacknode *new_node = (stacknode*) calloc(1,sizeof(stacknode));
    new_node->startlist = (node*) calloc (1,sizeof(node));
    new_node->startlist->item = 0;
    new_node->next = top;
    return new_node;
}

void removeNewLine(char *string)
{
    int newlinePos = strcspn(string, "\n");
    string[newlinePos] = '\0';
    return;
}

/*void push(stack *s, int item)
{   
    s->top;
    //printf("%d\n", s->topo);
    s->vet[s->topo] = calloc(n, sizeof(int));
    memcpy(s->vet[s->topo], x, n * sizeof(int));

    s->tam[s->topo] = n;
}*/

void printlinkedlist(node *head)
{
    node *aux = head;

    while(aux != NULL)
    {
        printf("%d ", aux->item);
        aux = aux->next;
    }
    puts("");
}

void scanstack(stack *s)
{
    char string[10];
    int item;
    //int vetor[TAM];

    while(fgets(string, 10, stdin) != NULL)
    {
        removeNewLine(string);

        //printf("%s\n", string);
        if(strcmp(string, "PUSH") == 0)
        {
            s->top = addnodeinicio(s->top->next);
            //puts("TO ENTRANDO NO PUSH");
            /*fgets(aux, 100, stdin);

            int n = strlen(aux) - 1;*/
            //printf("%d\n", n);

            /*int i = 0;
            while(scanf("%d%*c", vetor[i]) != EOF)
            {
                i++;
            }*/

            //int i = 0;
            char aux;
            /*for(i = 0; scanf("%d %c", &vetor[i], &aux); i++)
            {
                printf("%d\n", i);
                if(aux == '\n') break;
            }*/

            while(scanf("%d%c", &item, &aux) == 2 && aux != '\n')
            {
                //printf("%d%c\n", vetor[i], aux);
                //puts("FOI");
                //push(s->top->startlist, item);  
                s->top->startlist = addnodefinal(s->top->startlist, item);          
            }
            s->top->startlist = addnodefinal(s->top->startlist, item);
            //printf("i = %d\n", i);
            //i++;
            //printf("%d\n", vetor[i]);

        }  

        else
        {
            if(s->top->startlist == NULL)
            {
                puts("EMPTY STACK"); 
            }

            else
            {
                printlinkedlist(s->top->startlist);
                s->top->startlist = s->top->next;
            }
        }
    }

    return;
}

int main()
{
    stacknode s = create_stack();

    scanstack(s->top);

    return 0;
}