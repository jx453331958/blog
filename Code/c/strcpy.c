#include <stdio.h>

// ？？？
void strcpy(char *s, char *t)
{
  while((*s = *t) != '\0') {
    printf("%c", *s);
    s++;
    t++;
  }
}

int main()
{
  // char sArr[] = {'t', 'e', 's', 't'};
  // char tArr[1000];
  
  char sArr[] = "now is the time";
  char tArr[100];

  strcpy(sArr, tArr);

  char *p = tArr;
  while(*p != '\0') {
    printf("%c\n", *p);
    *p++;
  }
}