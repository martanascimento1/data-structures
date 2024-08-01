#include <stdio.h>
#include <stdlib.h>


typedef int (*test)(int);

int* filter(test func, int* array, int size, int* new_size) {
    int* result = (int*)malloc(size * sizeof(int));
    int cont = 0;

    for (int i = 0; i < size; i++) {
        if (func(array[i])) {
            result[cont++] = array[i];
        }
    }

    *new_size = cont;
    return result;
}


int par(int n) {
    return n % 2 == 0;
}


int impar(int n) {
    return n % 2 != 0;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int new_size;

    int* pares = filter(par, array, size, &new_size);
    printf("Pares: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");
    free(pares);

    
    int* impares = filter(impar, array, size, &new_size);
    printf("Impares: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", impares[i]);
    }
    printf("\n");
    free(impares);

    return 0;
}
