#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM{
    int item;
    struct ITEM *proximo;
}*tipoLista;
