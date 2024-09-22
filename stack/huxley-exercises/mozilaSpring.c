#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    struct No *next;
} No;

No *novoNo(No *data) {
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->next = data;
    return novo_no;
}

void removeNewLine(char *string)
{
    if(string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 1] = '\0';
    }

    return;
}
void pop(No *data)
{
    data = data->next;
    return;
}


int Avance(No *data)
{
    int n = 0;
    while(data != NULL)
    {
        n++;
        data = data->next;
    }

    return n;
}
int Volte(No *data)
{
    int n = -1;
    while(data != NULL)
    {
        n++;
        data = data->next;
    }

    return n;
}
void scanstack(No *headback, No *headforward)
{
    char string[10];

    while(fgets(string,10,stdin) != NULL)
    {
        removeNewLine(string);
        if(strcmp(string, "ENTER") == 0)
        {
            headback = novoNo(headback);
        }
        else if(strcmp(string, "BACK") == 0)
        {
            headforward = novoNo(headforward);
            pop(headback);
        }
        else if(strcmp(string, "FORWARD") == 0)
        {
            headforward = novoNo(headback);
            pop(headforward);
        }
    }

    int forward = Avance(headforward);
    int back = Volte(headback);

    printf("BACK: %d\nFORWARD: %d\n", back, forward);
}


int main()
{
    No *headback = NULL;
    No *headforward = NULL;

    scanstack(headback, headforward);

    return 0;
}