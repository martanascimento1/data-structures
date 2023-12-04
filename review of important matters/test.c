#include <stdio.h>
#include <string.h>
void PrintString (char *str, int (*func)(const char *));
main (void)
{
char String []="Curso de C.";
int (*p)(const char *);
p=puts;
PrintString (String, p);
return 0;
}
void PrintString (char *str, int (*func)(const char *))
{
(*func)(str);
func(str);
}