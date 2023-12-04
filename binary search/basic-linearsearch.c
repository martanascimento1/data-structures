#include<stdio.h>
#include <stdlib.h>

int linearSearch (int *v,int size, int element)
{
int i;
   for(i=0; i <size;i++)
  {
     if(v[i]==element)
     {
     return i;
     }
  }
 return -1;
}

int main ()
{
 int v[16]={1,3,2,8,3,4,6,5,9,10, 11, 12, 13, 14, 15, 16};
 int result = 0;
 int value = 0;

 printf("Enter the value you want to search:\n");
 scanf("%d",&value);

 result = linearSearch(v, 16, value);
    if(result == -1){
 		printf("value not found\n");
 }
   else{
 	   printf("value found\n");
 }

 return 0;

}