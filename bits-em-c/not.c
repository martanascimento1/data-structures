#include <stdio.h>
#include <stdlib.h>

int main () {

//operador bit a bit NOT (~)
// 1 = 0001
// ~1 = 1110 = -2

int a, b;
a = 1;
b= ~a;

printf("a: %d\t!a: %d\n", a, b);

/*complemento de 2

como representar -2 em binário?
2 - em decimal
0010 - dois em binário
1101
   1
1110 -> -2 em binário
*/
return 0;

}