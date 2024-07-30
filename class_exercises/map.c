#include <stdio.h>
#include <stdlib.h>

int square (int x) {

    return x*x;
}

int fatorial (int x) {
    if (x <=1) {
        return 1;
    }
    return x * fatorial(x-1);
}

//função map:

int* map(int (*funcao)(int), int* array, int length) {

    int* result = (int*)malloc(length*sizeof(int));
    for (int i=0; i < length; i++) {

        result[i] = funcao(array[i]);
    }
    return result;
}

int main () {

    int y[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(y) / sizeof(y[0]);

    int* quadrado = map(square, y, length);
    for (int i=0; i< length; i++) {
        printf("%d ", quadrado[i]);
    }

    int* fact = map(fatorial, y, length);
    for (int i=0; i<length; i++) {
        printf("%d ", fact[i]);
    }

    free (quadrado);
    free(fact);
}