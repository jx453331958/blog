#include <stdio.h>

int main()
{
  char *s = "now is the time";
  char t[100];

  char *m = t;

  while(*m++ = *s++) {
  }

  while(*m != '\0') {
    printf("%c", *m);
    m++;
  }
}