#include <stdio.h>
#include <stdlib.h>

int main () {
 
 char array [] = {'a', 'b', 'c', 'd', 'e'};
 putchar("\n");
 
 for (int i =0; i< 5; i++) {
    printf("caractere %i: %c\n"
    "endereco %i: %p\n\n", i, array[i], i, &array[i]);
 }
 return 0;
 }




