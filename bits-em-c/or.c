#include <stdio.h>
#include <stdlib.h>

/*
Operador bit a bit OR (|) - Se um bit for 1, o resultado é 1
  A | B
  0 | 0 = 0
  0 | 1 = 1
  1 | 0 = 1
  1 | 1 = 1

*/
int main () {

int a, b, c;
a = 30; // 0001 1110
b = 19; // 0001 0011
c = a | b; // 0001 1111 = 31
//c = a || b; // 0000 0001 = 1

printf("%d | %d = %d\n", a, b, c);

return 0;

}