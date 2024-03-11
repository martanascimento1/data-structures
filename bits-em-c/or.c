#include <stdio.h>
#include <stdlib.h>

/*
Operador bit a bit OU exclusivo ( ^)
  A ^ B
  0 ^ 0 = 0
  0 ^ 1 = 1
  1 ^ 0 = 1
  1 ^ 1 = 0

*/
int main () {

int a, b;
a = 73; // 01001001
b = a ^(1 << 3); // 01000000 para inverter o bit 3 = 65
printf("a: %d\tb: %d\n",a, b); 
b = b ^(1 << 3); // 01000000 para inverter o bit 3 = 73
printf("a: %d\tb: %d\n",a, b); 

return 0;

}