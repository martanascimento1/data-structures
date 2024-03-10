#include <stdio.h>
#include <stdlib.h>

int main () {

/* operador bit a bit E (&)
A B A & B
0 0    0
0 1    0
1 0    0
1 1    1
*/
int a, b, c;
a = 30; // 0000.0000.0001.1110
b= 19; // 0000.0000.0001.0011
c = a & b; // 0000.0000.0000.1010
//c = a && b; // 1

//printf(" %d & %d = %d\n", a, b, c);

// testar se um bit está ligado ou desligado

a = 73; 
b = a & (1 << 3); 
printf(" a: %d\tb: %d\n", a, b);
b = a & (1 << 4);
printf(" a: %d\tb: %d\n", a, b);


// verificar se um número é par ou ímpar

int n = 98; // 0110.0010
if (n & 1) { // 0000.0001
    printf(" %d é ímpar\n", n);
} else {
    printf(" %d é par\n", n);
}
return 0;

}