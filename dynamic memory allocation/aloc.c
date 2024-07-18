#include <stdio.h>
#include <stdlib.h>

int main() {

//A função sizeof determina o número de bytes para um determinado tipo de dados.
//x = sizeof(int); //retorna 4 no gcc
// malloc - aloca um espaço de memória e retorna um ponteiro do tipo void para o início do espaço de memória alocado.
// free - libera o espaço de memória alocado.

	printf("\nSize of char: %d", sizeof(char));
	printf("\nSize of int: %d", sizeof(int));
	printf("\nSize of float: %d", sizeof(float));
	printf("\nSize of double: %d\n", sizeof(double));
	
}