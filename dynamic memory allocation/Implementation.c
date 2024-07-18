#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
  int *v;
  int i, qtd;
  
  scanf("%d", &qtd);
  v = (int *) malloc(qtd * sizeof(int));
  
  for (i = 0; i < qtd; i++)
  {
    scanf("%d",&v[i]);
  }
  
  for (i = 0;i < qtd; i++)
  {
    printf("%d\n",v[i]);
  }
  
  free(v);

  return 0;
}