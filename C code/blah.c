#include <string.h>
#include <stdio.h>

int foo(void);

int main()
{
  int x = foo();
  printf("%i\n", x);

  char blarg[] = "fizzbuzz";
  printf("%s\n", blarg+4);

  return 0;
}

int foo(void)
{
  char bar[128];
  char *baz = &bar[0];
  baz[127] = 0;

  return strlen(baz);
}
