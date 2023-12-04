#include<stdio.h>
#include <stdlib.h>

int binarySearch(int *v, int size, int valor) {
    int begin = 0;
    int end = size - 1;
    int middle;
     while (begin <= end ) {
        middle = (begin + end) / 2;
        if (v[middle] < valor) {
            begin = middle + 1;
        }
        else if (v[middle] > valor) {
            end = middle - 1;
        }
        else {
            return middle;
        }
     }
     return -1;
}
int main ()
{

 int array[16]={1,3,2,8,3,4,6,5,9,10, 11, 12, 13, 14, 15, 16};
 int result = 0;
 int v = 0;

 printf("Enter the value you want to search:\n");
 scanf("%d",&v);
 result = binarySearch(array, 16, v );
 if(result == -1){
 	printf("value not found\n");
 }else{
 	printf("value found\n");
 }
 return 0;

} 