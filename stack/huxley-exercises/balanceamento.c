#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack
{
    char vet[255];
    int topo
} stack;

void create(stack *s)
{
    s->topo = -1;
}

int isfull(stack *s)
{
    return s->topo == 255;
}

int isempty(stack *s)
{
    return s->topo == -1;
}

void push(stack *s, char x)
{
    if(isfull(s))
    {
        puts("Overflow");
        abort();
    }
    
    s->topo++;
    s->vet[s->topo] = x;
}

char pop(stack *s)
{
    if(isempty(s))
    {
        puts("Underflow");
        abort();
    }

    char x = s->vet[s->topo];
    s->topo--;
    return x;
}

//funcao para testar o balanceamento
int paladins (stack *s, int n)
{
    //tabela ascii
    // 40 = ) , 41 = (, 93 = ], 91 = [
    int cont40 = 0, cont41 = 0, cont93 = 0, cont91 = 0;

    for(int i = 0; i < n; i++)
    {
        //printf("TOPO %d\n", s->topo);
        
        char aux = pop(s);
        //printf("ESTOU ANALISANDO ESSE AQUI -> %c\n", aux);

        if(aux == ']')
        {
            cont93++;
        }
        
        else if(aux == ')')
        {
            cont40++;
        }

        else if(aux == '[')
        {
            if(cont93 == 0) 
            {
                return 0;
            }
    
            cont91++;
        }

        else if(aux == '(')
        {
            if(cont40 == 0) 
            {
                return 0;
            }
            
            cont41++;
        }
    }

    /*printf("cont 93 ']' = %d\n", cont93);

    printf("cont 91 '[' = %d\n", cont91);*/

    return (cont93 == cont91 && cont40 == cont41);
    
}

void scanstack(stack *s)
{
    int n;
    char string[255];
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++)
    {

        fgets(string,255,stdin);
        int j = strlen(string);
        //printf("J = %d\n", j);

        for(int m = 0; m < j; m++)
        {
            //printf("%d\n", m);
            push(s, string[m]);
        }

        printf(paladins(s,j) ? "Yes\n" : "No\n");  
    }
}

int main()
{
    stack s;

    create(&s);

    scanstack(&s);
}
