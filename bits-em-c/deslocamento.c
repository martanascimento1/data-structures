#include <stdio.h>
#include <stdlib.h>

int main () {

//deslocamento para a esquerda (equivalente a multiplicar por 2)
int a, b;
a = 1;
b = a << 1;
//printf("a: %d\tb: %d\n", a, b);

b = a << 2;
//printf("a: %d\tb: %d\n", a, b);

b = a << 3;
//printf("a: %d\tb: %d\n", a, b);

//deslocamento para a direita (equivalente a dividir por 2)

a = 10; //1010
b = a >> 1; //0101 = 5
printf("a: %d\tb: %d\n", a, b);

b = a >> 2; //0010 = 2
printf("a: %d\tb: %d\n", a, b);

b = a >> 3; //0001 = 1
printf("a: %d\tb: %d\n", a, b);
}