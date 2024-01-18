#include <stdlib.h>
#include <stdio.h>

// sobre a estrutura

typedef struct ITEM{
    int item;
    struct ITEM *proximo;
}*tipoLista;
// continuar
