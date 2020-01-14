#include <stdio.h>

int main()
{
  char *s = "now is the time";
  
  while(*s != '\0') {
    printf("%c", *s);
    s++;
  }
}