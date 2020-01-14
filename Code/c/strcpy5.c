#include <stdio.h>
#include <string.h>

int main()
{
  char *s = "now is the time";
  char t[100];

  char *p = t;
  strcpy(t, s);
  while(*p != '\0') {
    printf("%c", *p);
    p++;
  }
}