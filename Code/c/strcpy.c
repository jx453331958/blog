#include <stdio.h>

void strcpy(char *s, char *t)
{
  while((*s = *t) != '\0') {
    s++;
    t++;
  }
}

int main()
{
  char sArr[] = {'t', 'e', 's', 't'};
  char tArr[1000];

  strcpy(sArr, tArr);

  char *p = tArr;
  while(*p != '\0') {
    printf("%c\n", *p);
    *p++;
  }
}