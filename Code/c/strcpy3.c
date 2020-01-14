#include <stdio.h>

int main()
{
  char *s = "now is the time";
  char t[100];

  char *m = t;

  while(*s != '\0') {
    *m = *s;
    printf("%c", *m);

    s++;
    m++;
  }
}